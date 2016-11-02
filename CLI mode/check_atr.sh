#!/bin/bash

read -p "Please input your card type: " card_type

echo ""
echo "This is your card type: "
cat pcsc-tools-1.4.27/smartcard_list.txt | grep -C 1 "${card_type}"
