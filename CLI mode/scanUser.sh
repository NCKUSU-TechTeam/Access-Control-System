#!/bin/bash -x
cardID=""
until [ "$cardID" != "" ]
do
	cardID="$(echo "FF CA 00 00 00" | scriptor | awk '{split($0,a,"<")} {split(a[2],b,":")} {print b[1]}')"
	sleep 3
done

echo $cardID
# Check the userid in mysql
detect="$(cat "userdata.db" | grep `${cardID}` | wc -l )"

echo $detect

if [ "$detect" -eq "0" ]; then
	echo "No , enroll again"
else
	echo "Yes , it exist"
fi

