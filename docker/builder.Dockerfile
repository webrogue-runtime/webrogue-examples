FROM ubuntu:24.04

RUN apt-get update && apt-get -y install ca-certificates gpg wget curl build-essential lld bzip2 subversion git unzip

ENV PATH="/opt/.cargo/bin:$PATH"
ENV RUSTUP_HOME=/opt/rustup
ENV CARGO_HOME=/opt/.cargo
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | HOME=/opt sh -s -- -y --no-modify-path
RUN curl -L --proto '=https' --tlsv1.2 -sSf https://raw.githubusercontent.com/cargo-bins/cargo-binstall/main/install-from-binstall-release.sh | bash
RUN cargo binstall wasm-tools
RUN chmod -R a+rwx /opt/.cargo/

RUN curl -L https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-25/wasi-sdk-25.0-x86_64-linux.tar.gz | tar -xz && mv wasi-sdk-25.0-x86_64-linux /opt/wasi-sdk

RUN test -f /usr/share/doc/kitware-archive-keyring/copyright || wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | tee /usr/share/keyrings/kitware-archive-keyring.gpg >/dev/null
RUN echo 'deb [signed-by=/usr/share/keyrings/kitware-archive-keyring.gpg] https://apt.kitware.com/ubuntu/ noble main' | tee /etc/apt/sources.list.d/kitware.list >/dev/null
RUN apt-get update
RUN test -f /usr/share/doc/kitware-archive-keyring/copyright || rm /usr/share/keyrings/kitware-archive-keyring.gpg
RUN apt-get -y install kitware-archive-keyring
RUN apt-get -y install cmake
COPY wasi-sdk-pthread.cmake /opt/wasi-sdk/share/cmake/wasi-sdk-pthread.cmake
RUN cp /opt/wasi-sdk/share/wasi-sysroot/include/wasm32-wasip2/netdb.h /opt/wasi-sdk/share/wasi-sysroot/include/wasm32-wasi-threads/netdb.h

# RUN rm -rf /usr/include/
