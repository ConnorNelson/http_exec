# http_exec

http_exec is a super small ELF that will make an HTTP request to a remote HTTP server, download the contents, and exec it.

mget is a super small ELF that will make an HTTP request to a remote HTTP server, and output the contents.


## Usage

```sh
./http_exec <HOST> <PORT>
```

```sh
./mget <HOST> <PORT>
```


## Building

Build the docker container with `./build.sh`.

Build http_exec with `cd http_exec && ./run.sh`.

Build mget with `cd mget && ./run.sh`.


## Size

http_exec: 932 bytes

mget: 852 bytes