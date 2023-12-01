
enable_testing()
add_executable(StackTests StackUtil.cpp
                        test1.cpp
        )

target_link_libraries(StackTests PUBLIC GTest::gtest_main)
target_compile_features(StackTests PUBLIC cxx_std_17)

include(GoogleTest)
gtest_discover_tests(StackTests)
