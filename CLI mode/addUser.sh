#!/bin/bash
cardID=""
until [ "$cardID" != "" ]
do
	cardID="$(echo "FF CA 00 00 00" | scriptor | awk '{split($0,a,"<")} {split(a[2],b,":")} {print b[1]}')"
	sleep 3
done

# Get the userid and add it into mysql
gcc adduser.c -o adduser
./adduser $cardID
