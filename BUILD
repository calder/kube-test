load("@docker_rules//docker:docker.bzl", "docker_build")

cc_binary(
    name = "hello",
    srcs = ["hello.cc"],
)

docker_build(
    name = "hello_img",
    base = "@cc_base//image:image.tar",
    cmd = ["/hello"],
    files = [":hello"],
)
