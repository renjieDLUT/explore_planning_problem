cc_library(
    name="array",
    hdrs=["array.h"]

)

cc_test(
    name="test",
    srcs=["my_array_test.cpp"],
    deps=["@com_google_googletest//:gtest_main",
        "array"],
    copts=["-std=c++17"],
)