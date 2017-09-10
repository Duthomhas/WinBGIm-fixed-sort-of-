all: example kaleidoscope

kaleidoscope: kaleidoscope.exe
	rem

example: example.exe
	rem

example.exe: example.cpp ..\libbgi.a ..\graphics.h
	..\g++bgi example.cpp -L.. -I..
	example.exe

kaleidoscope.exe: kaleidoscope.cpp ..\libbgi.a ..\graphics.h
	..\g++bgi kaleidoscope.cpp -L.. -I..
	kaleidoscope.exe

..\libbgi.a:
	cd .. && $(MAKE)

..\graphics.h:
	cd .. && $(MAKE)

clean:
	del *.exe
