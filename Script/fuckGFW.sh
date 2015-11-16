#!/bin/bash

GOAGENT_PATH=${HOME}/Script/goagent-goagent-b130a8f/local
JSON_PATH=${HOME}/Script

# for goagent
# python ${GOAGENT_PATH}/proxy.py &> /dev/null &

# for shadowsocks
cd ${JSON_PATH}
sslocal &> /dev/null &

