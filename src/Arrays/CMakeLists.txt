
enable_testing()
add_executable(ArrayTests ArrayUtil.cpp
                        test1.cpp
                        test2.cpp
                        test3.cpp
                        test4.cpp
                        test5.cpp
        )


target_link_libraries(ArrayTests PUBLIC GTest::gtest_main)
target_compile_features(ArrayTests PUBLIC cxx_std_17)

include(GoogleTest)
gtest_discover_tests(ArrayTests)
