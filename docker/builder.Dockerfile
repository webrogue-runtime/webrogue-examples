FROM ubuntu:24.04

RUN apt-get update && apt-get -y install ca-certificates gpg wget curl
RUN test -f /usr/share/doc/kitware-archive-keyring/copyright || wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | tee /usr/share/keyrings/kitware-archive-keyring.gpg >/dev/null
RUN echo 'deb [signed-by=/usr/share/keyrings/kitware-archive-keyring.gpg] https://apt.kitware.com/ubuntu/ noble main' | tee /etc/apt/sources.list.d/kitware.list >/dev/null
RUN apt-get update
RUN test -f /usr/share/doc/kitware-archive-keyring/copyright || rm /usr/share/keyrings/kitware-archive-keyring.gpg
RUN apt-get -y install kitware-archive-keyring
RUN apt-get -y install cmake
RUN curl -L https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-24/wasi-sdk-24.0-x86_64-linux.tar.gz | tar -xz && mv wasi-sdk-24.0-x86_64-linux wasi-sdk
RUN curl -L https://github.com/wasix-org/wasix-libc/releases/download/v2024-07-08.1/sysroot.tar.gz | tar -xz
RUN curl https://get.wasmer.io -sSfL | WASMER_DIR=/.wasmer sh && chmod -R a+rx .wasmer
RUN rm -rf /usr/include/
