FROM ubuntu:22.04 AS build

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    ninja-build \
    git \
    libeigen3-dev \
    libvtk9-dev \
    qtbase5-dev \
    qtchooser \
    qt5-qmake \
    qtbase5-dev-tools \
    libgtest-dev \
    pybind11-dev \
    mpich \
    libmpich-dev

RUN cd /usr/src/gtest && \
    cmake . && \
    make 

WORKDIR /app
COPY . /app

RUN rm -rf build && mkdir -p build && cd build && \
    cmake -G Ninja ..  && \
    ninja -j8 && \
    ninja install
