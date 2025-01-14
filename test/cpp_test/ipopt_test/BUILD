cc_import(
    name = "my_external_lib",
    hdrs = glob(["~/local/include/coin-or/*.h"]),
    shared_library = "/home/renjie/local/lib/ipopt",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "problem",
    srcs = ["problem.cc"],
    hdrs = ["problem.h"],
    deps = [":my_external_lib"],
)

cc_binary(
    name = "ipopt_test",
    srcs = ["main.cc"],
    deps = [":problem"],
)
