// This example was created by me to demonstrate the 
// NEW method of creating a graphics context with WinBGIm.

// 2017 Michael Thomas Greer
// Released to the Public Domain

#include <cstdlib>
#include <ctime>
#include <graphics.h>
using namespace std;

// ---------------------------------------------------------------------------
// C-style random number generation as described by Michael Thomas Greer

int random_int_in_range( int first, int last )
{
  /* This function implements the method recommended by the knowing
   * folks at comp.lang.c: http://c-faq.com/lib/randrange.html
   * Returns an integer in [first, last].
   */
  unsigned int N = (last - first <= RAND_MAX)  /* Make sure the algorithm    */
                 ? (last - first + 1U)         /* terminates by keeping N    */
                 : (RAND_MAX + 1U);            /* in rand()'s maximum range. */
  unsigned int x = (RAND_MAX + 1U) / N;
  unsigned int y = x * N;
  unsigned int r;
  do {
    r = rand();
  } while (r >= y);
  return r / x + first;
}

double random_double()
{
  return rand() / (double)RAND_MAX;
}
 
double random_double_in_range( double low, double high )
{
  return random_double() * (high - low) + low;
}

// ---------------------------------------------------------------------------
// A simple interpolator class to compute the moving line ends
//
struct interpolator
{
  double x0, y0;
  double x1, y1;
  
  void randomize()
  {
    x0 = random_double_in_range( -100, getmaxx() + 100 );
    x1 = random_double_in_range( -100, getmaxx() + 100 );
    y0 = random_double_in_range( -100, getmaxy() + 100 );
    y1 = random_double_in_range( -100, getmaxy() + 100 );
  }
  
  void interpolate( double percent, int& x, int& y )
  {
    x = (x1 - x0) * percent + x0;
    y = (y1 - y0) * percent + y0;
  }
};

// ---------------------------------------------------------------------------
int main()
{
  srand( time( 0 ) );
  
  initwindow( 600, 400, "WinBGIm example - Kaleidoscope",
    (getmaxwidth()  - 600) / 2,
    (getmaxheight() - 400) / 10 * 4
  );
  
  interpolator a, b;
  clock_t clearout = 0;
  clock_t timeout = 0;
  clock_t start;
  
  bool done = false;
  while (!done)
  {
    // User input: 
    //   space, enter --> clear and start new pattern
    //   esc          --> quit
    if (kbhit())
    {
      switch (getch())
      {
        case ' ': case 13: case 10: clearout = timeout = 0; break;
        case 27: done = true; continue;
      }
    }
  
    // Reset timeouts
    clock_t now = clock();
    if (clock() > timeout)
    {
      if (now > clearout)
      {
        // Clear device in 7 to 21 seconds
        cleardevice();
        clearout = now + random_int_in_range( 7, 21 ) * CLOCKS_PER_SEC;
      }
      
      // Randomize next line interpolations
      a.randomize();
      b.randomize();
      start = now;
      // Line draw will occur in 0.5 to 3.0 seconds
      timeout = start + random_int_in_range( 5, 30 ) * CLOCKS_PER_SEC / 10;
      setcolor( RGB( 
        random_int_in_range( 0, 255 ), 
        random_int_in_range( 0, 255 ), 
        random_int_in_range( 0, 255 ) ) );
    }

    // Draw a line and its four reflections
    int x1, y1, x2, y2;
    double percent = (clock() - start) / (double)(timeout - start);
    a.interpolate( percent, x1, y1 );
    b.interpolate( percent, x2, y2 );
    line( x1, y1, x2, y2 );
    line( getmaxx() - x1, y1, getmaxx() - x2, y2 );
    line( x1, getmaxy() - y1, x2, getmaxy() - y2 );
    line( getmaxx() - x1, getmaxy() - y1, getmaxx() - x2, getmaxy() - y2 );

    delay( 40 );  // This is roughly 25 FPS
  }
}
