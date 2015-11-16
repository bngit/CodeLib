#!/bin/bash

echo ''
date
echo "======="
timedatectl
timedatectl set-timezone Asia/Shanghai
echo "------------------------"
# systemctl stop ntpd
ntpdate -u cn.pool.ntp.org
# service start ntpd
hwclock --systohc
echo "------------------------"
date
echo "======="
timedatectl
echo ''
echo "SET TIME OK!!!"
