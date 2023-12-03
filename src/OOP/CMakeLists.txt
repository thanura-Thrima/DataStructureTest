
enable_testing()
add_executable(OOPTests OOPUtil.cpp
                        test1.cpp
                        test2.cpp
        )


target_link_libraries(OOPTests PUBLIC GTest::gtest_main)
target_compile_features(OOPTests PUBLIC cxx_std_17)

include(GoogleTest)
gtest_discover_tests(OOPTests)
