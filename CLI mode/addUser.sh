#!/bin/bash
cardID=""
until [ "$cardID" != "" ]
do
	cardID="$(echo "FF CA 00 00 00" | scriptor | awk '{split($0,a,"<")} {split(a[2],b,":")} {print b[1]}')"
	sleep 3
done

newID="$(echo ${cardID} | awk '{gsub(" ","_")} { print $0 }')"

# Get the userid and add it into mysql
gcc src/adduser.c -o adduser
./adduser $newID
