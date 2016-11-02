#!/bin/bash

# install the dependency on your linux pc
sudo apt-get install pcscd libpcsc-perl pcsc-tools libccid > /dev/null
yes | sudo apt-get update upgrade

# install mysql 
sudo apt-get install mysql-server mysql-client
sudo mysql_secure_installation
# setting mysql
mysql -u root -p

# copy your Info-plist 
sudo cp /usr/lib/pcsc/drivers/ifd-ccid.bundle/Contents/Info.plist /usr/lib/pcsc/drivers/ifd-ccid.bundle/Contents/Info.plist-bak
sudo cp dependency/Info.plist /usr/lib/pcsc/drivers/ifd-ccid.bundle/Contents/Info.plist

# search for now scanning card type
echo "Please put on your card, and after you see the card number behind 'ATR',copy it and ctrl+c to quit,then run 'check_atr.sh' :"
 
pcsc_scan -n | grep "ATR" 

