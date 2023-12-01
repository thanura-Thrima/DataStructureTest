
enable_testing()
add_executable(TreeTests TreeUtil.cpp
                        test1.cpp
        )

target_link_libraries(TreeTests PUBLIC GTest::gtest_main)
target_compile_features(TreeTests PUBLIC cxx_std_17)

include(GoogleTest)
gtest_discover_tests(TreeTests)
