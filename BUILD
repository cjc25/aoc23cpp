cc_library(
    name = "input",
    srcs = ["input.cc"],
    hdrs = ["input.h"],
    deps = ["@abseil-cpp//absl/strings"],
)

cc_binary(
    name = "day1",
    srcs = ["day1.cc"],
    deps = [
        ":input",
        "@abseil-cpp//absl/strings",
    ],
)
