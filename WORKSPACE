workspace(name = "kube_test")

git_repository(
    name = "docker_rules",
    remote = "https://github.com/bazelbuild/rules_docker.git",
    tag = "v0.0.2",
)

load(
    "@docker_rules//docker:docker.bzl",
    "docker_repositories",
    "docker_pull",
)

docker_repositories()

docker_pull(
    name = "cc_base",
    registry = "gcr.io",
    repository = "distroless/cc",
    tag = "latest",
)
