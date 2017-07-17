load("@io_bazel_rules_docker//docker:docker.bzl", "docker_build")
load("@org_pubref_rules_protobuf//cpp:rules.bzl", "cc_proto_library")

cc_proto_library(
    name = "hello_cc_proto",
    protos = [
        "hello.proto",
    ],
    with_grpc = True,
)

cc_binary(
    name = "hello",
    srcs = ["hello.cc"],
    linkopts = ["-static"],
    deps = [
        ":hello_cc_proto",
        "@com_github_grpc_grpc//:grpc++_reflection",
    ],
)

docker_build(
    name = "hello_img",
    base = "@cc_base//image:image.tar",
    cmd = ["/hello"],
    files = [":hello"],
)
