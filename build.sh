set -ex
cd $(dirname $0)

image_name=webrogue-sdk
docker --version | grep podman >/dev/null || {
    DOCKER_USER_FLAGS="-u $(id -u ${USER}):$(id -g ${USER})"
}
run_in_docker() {
    docker run \
        -it \
        --rm \
        -v $(pwd):/examples_host_dir \
        -v $(dirname $(pwd))/webrogue-sdk/libraries:/webrogue_sdk_libs \
        $DOCKER_USER_FLAGS \
        -t $image_name \
        bash -c "$1"
}
run_in_docker "make -C /examples_host_dir -f docker.Makefile"
