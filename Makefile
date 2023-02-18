config:
	export BAZEL_CXXOPTS=-std=c++17

build:
	bazel build //src:app

run:
	bazel run //src:app
