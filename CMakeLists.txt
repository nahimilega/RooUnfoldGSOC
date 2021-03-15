cmake_minimum_required(VERSION 3.2)

if (MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(intro main.cpp)
target_compile_features(intro PRIVATE cxx_lambda_init_captures)


file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/RooUnfoldGSOC.cxx DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

enable_testing()

add_executable(tester tester.cpp)
add_test(Tester tester)


