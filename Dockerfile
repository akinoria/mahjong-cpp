FROM ubuntu:22.04
LABEL maintainer "pystyle"

ENV LC_ALL C.UTF-8
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    build-essential \
    ca-certificates \
    cmake \
    git \
    libboost-all-dev \
    python3-dev \
    ninja-build \
    pip

RUN rm -rf /var/lib/apt/lists/*

WORKDIR /mahjong-cpp
