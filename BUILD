cc_library(
    name="interface",
    hdrs =glob(["*.h"]),
    srcs=["Writer.cpp","schedule.cpp"]
)

cc_binary(
    name="main",
    srcs=["main.cpp"],
    deps =[":interface"]
)