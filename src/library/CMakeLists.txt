add_library(dse SHARED
	histogram.cxx
	randomVariables.cxx
	simd.cxx
	simulationElts.cxx
	utilities.cxx)
set_target_properties(dse PROPERTIES VERSION 0.0.1 SOVERSION 0)
set_property(TARGET dse PROPERTY COMPILE_FLAGS "-Wall -msse2 -O3")

