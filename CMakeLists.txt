cmake_minimum_required(VERSION 3.6)

project(KMP)

set(CMAKE_CXX_STANDARD 11)

add_executable(patternSearch src/patternSearch.cpp src/KMP.cpp src/KMP.h)
add_executable(checkShift src/checkShift.cpp src/KMP.cpp src/KMP.h)

#add_executable(kmp_test test/kmp_test.cpp src/KMPAlgorithm.cpp src/KMPAlgorithm.h test/KMPTest.h test/KMPTest.cpp)
#add_executable(cycle_shift_test test/cycle_shift_test.cpp src/KMPAlgorithm.cpp src/KMPAlgorithm.h test/KMPTest.h test/KMPTest.cpp)

#target_link_libraries(kmp_test gtest gtest_main)
#target_link_libraries(cycle_shift_test gtest gtest_main)
