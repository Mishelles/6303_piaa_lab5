cmake_minimum_required(VERSION 3.5)

project(KMP)

set(CMAKE_CXX_STANDARD 11)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(patternSearch src/patternSearch.cpp src/KMP.cpp src/KMP.h)
add_executable(checkShift src/checkShift.cpp src/KMP.cpp src/KMP.h)

add_executable(testPrefix test/testPrefix.cpp test/TestKMP.cpp test/TestKMP.h src/KMP.cpp src/KMP.h)
add_executable(testPatternSearch test/testPatternSearch.cpp test/TestKMP.cpp test/TestKMP.h src/KMP.cpp src/KMP.h)
add_executable(testCheckShift test/testCheckShift.cpp test/TestKMP.cpp test/TestKMP.h src/KMP.cpp src/KMP.h)

add_executable(compareSimpleVsKmp src/compareSimpleVsKmp.cpp)

target_link_libraries(testPrefix ${GTEST_LIBRARIES} pthread)
target_link_libraries(testPatternSearch ${GTEST_LIBRARIES} pthread)
target_link_libraries(testCheckShift ${GTEST_LIBRARIES} pthread)

add_test(TestPrefix "./testPrefix")
add_test(TestPatternSearch "./testPatternSearch")
add_test(TestCheckShift "./testCheckShift")
