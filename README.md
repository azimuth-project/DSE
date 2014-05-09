Authors
-------
DSE code : David Tweed
cmake makefile : Glyn Adgie

Copyright : David Tweed, 2012
Licence : BSD

Build
------

To build the library and tests:
	cd build
	cmake ../src
	make

This creates libdse.so.* in build/library, and test* in build/test. The tests
link to the local library, so there is no need to install it, or to set
LD_LIBRARY_PATH. To run test0, do test/test0 in the build directory.


Installation
-------------

I have not implemented the Cmake stuff to do a 'make install' yet. 


Cmake notes
------------

Cmake is a cross-platform make, that provides some of functionality of GNU
autotools (./configure etc), does dependency-checking by scanning source files
for includes, and generates makefiles for use in the actual build.

Cmake favours out-of-source builds, hence the separate build directory. This
policy means that the build process does not create any intermediate files or
targets in the source tree; they all end up in build, under subdirectories that
mirror the subdirectories in src. This make it much easier to distribute clean
sources, ready for building on another system. For simple projects, all you
have to do is 'rm -r *' in the build directory, then zip up the project root
directory.

The operation of Cmake is controlled by files called CMakeLists.txt. In this
project, there is a master file in src, that adds the subdirectories 'library'
and 'test' to the project. These in turn contain their own CMakeLists.txt
files, that build the library and tests. This is therefore a recursive build.


Minor improvements to the tests
--------------------------------

I have made some simple changes to the test sources.

1. Added a check on the number of command line arguments, and a usage message.

2. Used atoi() instead of fscanf() to read the arguments.

3. Improved the resolution of elapsed time measurement, by replacing time(),
   that has a resolution of 1 second, with a class based on gettimeofday(),
   that provides a resolution of 1 microsecond.
