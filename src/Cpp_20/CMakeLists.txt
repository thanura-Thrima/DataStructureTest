
enable_testing()
add_executable(Cpp_20Tests Cpp_20Utils.cpp
                        test1.cpp
        )


target_link_libraries(Cpp_20Tests PUBLIC GTest::gtest_main)
target_compile_features(Cpp_20Tests PUBLIC cxx_std_20)

include(GoogleTest)
gtest_discover_tests(Cpp_20Tests)
