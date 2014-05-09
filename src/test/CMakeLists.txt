include_directories("${PROJECT_SOURCE_DIR}/library")

add_executable(test0 testModel0.cxx)
set_property(TARGET test0 PROPERTY COMPILE_FLAGS "-Wall -msse2 -O3")
target_link_libraries(test0 dse)

add_executable(test1 testModel1.cxx)
set_property(TARGET test1 PROPERTY COMPILE_FLAGS "-Wall -msse2 -O3")
target_link_libraries(test1 dse)

