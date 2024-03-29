load("//bazel:otel_cc_benchmark.bzl", "otel_cc_benchmark")

cc_test(
    name = "random_test",
    srcs = [
        "random_test.cc",
    ],
    tags = ["test"],
    deps = [
        "//sdk/src/common:random",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "fast_random_number_generator_test",
    srcs = [
        "fast_random_number_generator_test.cc",
    ],
    tags = ["test"],
    deps = [
        "//sdk/src/common:random",
        "@com_google_googletest//:gtest_main",
    ],
)

otel_cc_benchmark(
    name = "random_benchmark",
    srcs = ["random_benchmark.cc"],
    tags = ["test"],
    deps = ["//sdk/src/common:random"],
)

cc_test(
    name = "atomic_unique_ptr_test",
    srcs = [
        "atomic_unique_ptr_test.cc",
    ],
    tags = ["test"],
    deps = [
        "//api",
        "//sdk:headers",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "circular_buffer_range_test",
    srcs = [
        "circular_buffer_range_test.cc",
    ],
    tags = ["test"],
    deps = [
        "//api",
        "//sdk:headers",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "random_fork_test",
    srcs = [
        "random_fork_test.cc",
    ],
    tags = ["test"],
    deps = [
        "//sdk/src/common:random",
    ],
)

cc_library(
    name = "baseline_circular_buffer",
    hdrs = [
        "baseline_circular_buffer.h",
    ],
    include_prefix = "test/common",
    deps = [
        "//api",
    ],
)

otel_cc_benchmark(
    name = "circular_buffer_benchmark",
    srcs = ["circular_buffer_benchmark.cc"],
    tags = ["test"],
    deps = [
        ":baseline_circular_buffer",
        "//sdk:headers",
    ],
)

cc_test(
    name = "empty_attributes_test",
    srcs = [
        "empty_attributes_test.cc",
    ],
    tags = ["test"],
    deps = [
        "//api",
        "//sdk:headers",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "attribute_utils_test",
    srcs = [
        "attribute_utils_test.cc",
    ],
    tags = ["test"],
    deps = [
        "//api",
        "//sdk:headers",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "global_log_handle_test",
    srcs = [
        "global_log_handle_test.cc",
    ],
    tags = ["test"],
    deps = [
        "//api",
        "//sdk:headers",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "attributemap_hash_test",
    srcs = [
        "attributemap_hash_test.cc",
    ],
    tags = ["test"],
    deps = [
        "//api",
        "//sdk:headers",
        "@com_google_googletest//:gtest_main",
    ],
)

otel_cc_benchmark(
    name = "attributemap_hash_benchmark",
    srcs = ["attributemap_hash_benchmark.cc"],
    tags = ["test"],
    deps = [
        "//api",
        "//sdk:headers",
    ],
)
