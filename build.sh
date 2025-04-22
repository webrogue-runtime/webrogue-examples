set -ex
cd $(dirname $0)

image_name=webrogue-sdk
run_in_docker() {
    docker run \
        -it \
        --rm \
        -v $(pwd):/host_dir \
        -u $(id -u ${USER}):$(id -g ${USER}) \
        -t $image_name \
        bash -c "$1"
}
run_in_docker "make -C /host_dir -f docker.Makefile"
