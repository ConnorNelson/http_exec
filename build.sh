#!/usr/bin/env sh

docker build -t http_exec .
docker run -it --rm -v $PWD:/app http_exec
