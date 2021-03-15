cmake_minimum_required(VERSION 3.2)


project(RooUnfoldGSOC)

# Copy the RooUnfoldGSOC.cxx file to build
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/RooUnfoldGSOC.cxx DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

enable_testing()

add_executable(tester tester.cpp)
add_test(Test_1 tester)
add_test(Test_2 tester)
add_test(Test_3 tester)
add_test(Test_4 tester)
