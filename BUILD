cc_library(
    name = "input",
    srcs = ["input.cc"],
    hdrs = ["input.h"],
    deps = ["@abseil-cpp//absl/strings"],
)

cc_library(
    name = "runner",
    srcs = ["runner.cc"],
    deps = [":input"],
)

cc_binary(
    name = "day1",
    srcs = ["day1.cc"],
    deps = [
        ":runner",
        "@abseil-cpp//absl/strings",
    ],
)