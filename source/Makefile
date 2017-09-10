libbgi.a: drawing.o misc.o mouse.o palette.o text.o winbgi.o winthread.o file.o dibutil.o winbgim.h graphics.h
	ar -rv libbgi.a drawing.o misc.o mouse.o palette.o text.o winthread.o winbgi.o file.o dibutil.o

clean:
	del *.o
	if exist libbgi.a   del libbgi.a
	if exist graphics.h del graphics.h

CPPFLAGS = -c -O3 -fno-rtti -fno-exceptions -m32

drawing.o: drawing.cxx winbgim.h winbgitypes.h
	g++ $(CPPFLAGS) drawing.cxx

misc.o: misc.cxx winbgim.h winbgitypes.h
	g++ $(CPPFLAGS) misc.cxx

mouse.o: mouse.cxx winbgim.h winbgitypes.h
	g++ $(CPPFLAGS) mouse.cxx

palette.o: palette.cxx winbgim.h winbgitypes.h
	g++ $(CPPFLAGS) palette.cxx

text.o: text.cxx winbgim.h winbgitypes.h
	g++ $(CPPFLAGS) text.cxx

winbgi.o: winbgi.cxx winbgim.h winbgitypes.h
	g++ $(CPPFLAGS) winbgi.cxx

winthread.o: winthread.cxx winbgim.h winbgitypes.h
	g++ $(CPPFLAGS) winthread.cxx

dibutil.o: dibutil.cxx dibutil.h dibapi.h
	g++ $(CPPFLAGS) dibutil.cxx

file.o: file.cxx dibutil.h dibapi.h winbgitypes.h
	g++ $(CPPFLAGS) file.cxx

graphics.h: winbgim.h
	if exist graphics.h del graphics.h
	copy /y winbgim.h graphics.h
