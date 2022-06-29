cc_library(
    name = "foo",
    hdrs = ["foo.h"],
)

cc_test(
    name = "test",
    srcs = ["test.cpp"],
    deps = [ "@com_google_googletest//:gtest_main",
            ":foo",
            ],
)
