#!/bin/bash

#Jake Ammons
#IEEE 2019
#Updated: 11/11/2018

#Set USER to your username on the beaglebone
USER="debian"
#Set REPO to the path to the Git repo
REPO=ieee/IEEE_2019

#Navigate to Git repo, pull updates, and connect to the latest ip address
cd $REPO
git pull
echo "connecting to $USER@$(cat support/ip_address)"
ssh $USER@$(cat support/ip_address)

