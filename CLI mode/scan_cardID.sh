#!/bin/bash

#echo "This is your scan command , by card-type mifare:"
#cat dependency/read_uid_cmd.txt

#echo "Please copy this command to scriptor stdin , and put your card on it and run until program stop:"
#echo ""

# execution
cardID=""
until [ "$cardID" != "" ]
do
	cardID="$(echo "FF CA 00 00 00" | scriptor | awk '{split($0,a,"<")} {split(a[2],b,":")} {print b[1]}')"
	sleep 3
done

# echo "Done ! This card ID is " $cardID
