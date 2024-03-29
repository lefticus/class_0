project(TestForClass)

cmake_minimum_required(VERSION 3.10)

add_library(project_warnings INTERFACE)
target_compile_options(project_warnings
                       INTERFACE -Wall
                                 -Wextra # reasonable and standard
                                 -Wshadow # warn the user if a variable
                                          # declaration shadows one from a
                                          # parent context
                                 -Wnon-virtual-dtor # warn the user if a class
                                                    # with virtual functions has
                                                    # a non-virtual destructor.
                                                    # This helps catch hard to
                                                    # track down memory errors
                                 -Wold-style-cast # warn for c-style casts
                                 -Wcast-align # warn for potential performance
                                              # problem casts
                                 -Wunused # warn on anything being unused
                                 -Woverloaded-virtual # warn if you overload
                                                      # (not override) a virtual
                                                      # function
                                 -Wpedantic # warn if non-standard C++ is used
                                 -Wconversion # warn on type conversions that
                                              # may lose data
                                 -Wsign-conversion # warn on sign conversions
                                 -Wmisleading-indentation # warn if identation
                                                          # implies blocks where
                                                          # blocks do not exist
                                 -Wduplicated-cond # warn if if / else chain has
                                                   # duplicated conditions
                                 -Wduplicated-branches # warn if if / else
                                                       # branches have
                                                       # duplicated code
                                 -Wlogical-op # warn about logical operations
                                              # being used where bitwise were
                                              # probably wanted
                                 -Wnull-dereference # warn if a null dereference
                                                    # is detected
                                 -Wuseless-cast # warn if you perform a cast to
                                                # the same type
                                 -Wdouble-promotion # warn if float is implicit
                                                    # promoted to double
                                 -Wformat=2 # warn on security issues around
                                            # functions that format output (ie
                                            # printf)
                       )
add_executable(sum_number src/sum_number.cpp)
target_compile_features(sum_number PRIVATE cxx_std_11)

add_library(math_functions src/factorial.cpp)
target_compile_features(math_functions PRIVATE cxx_std_11)
target_include_directories(math_functions PUBLIC include)

add_executable(test_harness test/test.cpp)
target_compile_features(test_harness PRIVATE cxx_std_11)
target_link_libraries(test_harness math_functions)

add_executable(simulation src/simulation.cpp src/simulation_main.cpp)
target_compile_features(simulation PRIVATE cxx_std_14)
target_include_directories(simulation PUBLIC include)
target_link_libraries(simulation project_warnings)

enable_testing()
add_test(NAME MyTest COMMAND test_harness)
