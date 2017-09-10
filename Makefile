all: libbgi.a graphics.h examples

libbgi.a:
	@echo.
	@echo ------------------------------------------------------------------------------
	@echo Compiling the BGI library
	@echo ------------------------------------------------------------------------------
	cd source && $(MAKE)
	copy source\libbgi.a .

graphics.h:
	copy source\graphics.h .

examples: examples\example.exe examples\kaleidoscope.exe

examples\kaleidoscope.exe:
	@echo.
	@echo ------------------------------------------------------------------------------
	@echo Compiling the Kaleidoscope example program
	@echo ------------------------------------------------------------------------------
	cd examples && $(MAKE) kaleidoscope

examples\example.exe:
	@echo.
	@echo ------------------------------------------------------------------------------
	@echo Compiling an old Borland BGI example program
	@echo ------------------------------------------------------------------------------
	cd examples && $(MAKE) example

clean:
	cd source && $(MAKE) clean
	cd examples && $(MAKE) clean
	del *.a
	del *.h
