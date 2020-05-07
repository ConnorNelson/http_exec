# 20.04's gcc excessively null-pads the ELF
FROM ubuntu:18.04

RUN apt-get update && \
    apt-get install -y build-essential git

RUN git clone https://github.com/BR903/ELFkickers
RUN cd ELFkickers && make

RUN mkdir /app
WORKDIR /app

ENTRYPOINT make clean && make && /ELFkickers/bin/sstrip http_exec