#!/usr/bin/env bash

make clean
make
/ELFkickers/bin/sstrip mget

ls -al mget

(cat <(echo -en '\r\n\r\n') /usr/bin/whoami | nc -q0 -lp 4242) &
sleep 2

./mget 127.0.0.1 4242 > /tmp/whoami
chmod +x /tmp/whoami
result="$(/tmp/whoami)"
echo "$result"

if [ "$result" == "root" ]; then
    echo "Passed functionality test"
    exit 0
else
    echo "Failed functionality test"
    exit 1
fi
