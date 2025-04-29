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
        -v $(pwd):/host_dir \
        $DOCKER_USER_FLAGS \
        -t $image_name \
        bash -c "$1"
}
run_in_docker "make -C /host_dir -f docker.Makefile"
