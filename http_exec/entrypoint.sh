#!/usr/bin/env bash

make clean
make
/ELFkickers/bin/sstrip http_exec

ls -al http_exec

(cat <(echo -en '\r\n\r\n') /bin/sh | nc -q0 -lp 4242) &
sleep 2

result="$(echo 'whoami' | ./http_exec 127.0.0.1 4242)"
echo "$result"

if [ "$result" == "root" ]; then
    echo "Passed functionality test"
    exit 0
else
    echo "Failed functionality test"
    exit 1
fi
