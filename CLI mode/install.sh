#!/bin/bash

# install the dependency on your linux pc
sudo apt-get install pcscd libpcsc-perl pcsc-tools libccid
sudo apt-get update

# future work - using mysql to control user database
# sudo apt-get install mysql-server mysql-client
# sudo mysql_secure_installation
# mysql -u root -p

# copy your Info-plist 
sudo cp /usr/lib/pcsc/drivers/ifd-ccid.bundle/Contents/Info.plist /usr/lib/pcsc/drivers/ifd-ccid.bundle/Contents/Info.plist-bak
sudo cp dependency/Info.plist /usr/lib/pcsc/drivers/ifd-ccid.bundle/Contents/Info.plist

# search for now scanning card type
echo "Please put on your card, and after you see the card number behind 'ATR',copy it and ctrl+c to quit;"
echo "=========Then run 'check_atr.sh' if you want to check the card type.========="
echo "=========If you just want to check your card id , use 'scan_cardID.sh'.========="
echo "=========If you want to add the user , use 'addUser.sh'========="
echo "=========If you want to scan the user , use 'scanUser.sh'========="

 
pcsc_scan -n | grep "ATR" 

