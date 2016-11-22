#!/bin/bash -x
cardID=""
until [ "$cardID" != "" ]
do
	cardID="$(echo "FF CA 00 00 00" | scriptor | awk '{split($0,a,"<")} {split(a[2],b,":")} {print b[1]}')"
	sleep 3
done 

reflect="$(echo ${cardID} | awk '{gsub(" ","_")} { print $0 }')"

# make database unique
cat "data/userdata.db" | sort | uniq > data/userdata1.db

cp data/userdata1.db data/userdata.db && rm data/userdata1.db

detect="$(cat "data/userdata.db" | grep "${reflect}" | wc -l )"

echo $detect

if [ "$detect" -eq "0" ]; then
	echo "No , enroll again"
else
	echo "Yes , it exist"
	# Implement open door function - open the gate
	sudo ./open
fi

bash scanUser.sh
