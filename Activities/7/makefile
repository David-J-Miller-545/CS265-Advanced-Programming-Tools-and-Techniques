#
# makefile - use by the (really handy) make utility
#
# Targets are:  stringtest test.o mystring.o
#    Phony targets: run clean
#    - No file is created
#      - (We just want to run the recipe)
#
# To build a particular target:
#   $ make run
#   $ make test
#   , etc.
#

  # this is the default target, by virtue of being the top-most
stringtest : mystring.o testdriver.o
	gcc  mystring.o testdriver.o -o stringtest

  # GNU extension
.PHONY : run clean

run : $(exe)
	./stringtest

testdriver.o : testdriver.c mystring.h
	gcc -c  testdriver.c

mystring.o : mystring.c mystring.h
	gcc -c  mystring.c

clean :
	- rm *.o
	- rm stringtest

