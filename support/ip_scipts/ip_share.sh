#!/bin/bash

#Give OS time to connect to wifi
sleep 1m

#Open repo and get updates, resetting any uncommitted changes
cd IEEE_2019
git fetch --all
git reset --hard origin/master

#Write IP address and timestamp to repo and push update
ifconfig wlan0 | grep "inet " | awk -F'[: ]+' '{ print $3 }' > support/ip_address
date > support/last_updated
git add *
git commit -m 'updated ip address'
git push
