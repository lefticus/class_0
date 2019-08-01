project(TestForClass)

cmake_minimum_required(VERSION 3.13)

add_executable(sum_number src/sum_number.cpp)
target_compile_features(sum_number PRIVATE cxx_std_17)

add_library(math_functions src/factorial.cpp)
target_compile_features(math_functions PRIVATE cxx_std_11)
target_include_directories(math_functions PUBLIC include)


add_executable(test_harness test/test.cpp)
target_compile_features(test_harness PRIVATE cxx_std_11)
target_link_libraries(test_harness math_functions)

add_executable(simulation src/simulation.cpp)
target_compile_features(simulation PRIVATE cxx_std_14)
target_include_directories(simulation PUBLIC include)


enable_testing()
add_test(NAME MyTest COMMAND test_harness)


