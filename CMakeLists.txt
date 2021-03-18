cmake_minimum_required(VERSION 3.2)


project(RooUnfoldGSOC)

find_package( ROOT COMPONENTS Tree Unfold Matrix Hist RIO MathCore Physics RooFitCore RooFit Graf Postscript Gpad)
#ROOT_GENERATE_DICTIONARY(G__Event Event.h LINKDEF EventLinkDef.h)

# Create a shared library with a generated dictionary.
# Passing cmake targets such as `ROOT::RIO` as dependencies (rather than plain
# library names e.g. via ${ROOT_LIBRARIES}) ensures that properties such as required
# include directories and C++ standard are propagated to our libraries or executables.
# Note: to ensure compatibility with Cling, targets *must* be compiled using the
# same C++ standard as ROOT was compiled with.
#
#add_library(Event SHARED Event.cxx G__Event.cxx)




add_executable(RooUnfoldGSOC RooUnfoldGSOC.cxx)
target_link_libraries(RooUnfoldGSOC PUBLIC ROOT::Matrix ROOT::Core ROOT::Hist)

# Create the main program using the library.








#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/RooUnfoldGSOC.cxx DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

enable_testing()

add_executable(tester tester.cpp)
add_test(Test_1 tester)
add_test(Test_2 tester)
add_test(Test_3 tester)
add_test(Test_4 tester)
