#!/bin/bash

echo ''
date
echo "------------------------"
service ntp stop
ntpdate -u cn.pool.ntp.org
service ntp start
echo "------------------------"
date
echo ''
