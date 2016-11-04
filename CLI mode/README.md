# Access Control System

## Usage
- Install dependency for Card scanning , and run `pcsc_scan` to check card ID:
```shell=bash
$ bash install.sh
```
   - you can `ctrl+c` to exit `pcsc_scan`.


- And if want to check card type , using :
```shell=bash
$ bash check_atr.sh
```
- If you want to add User into database , using :
```shell=bash
$ bash addUser.sh
```
- If you want to scan User from database , using :
```shell=bash
$ bash scanUser.sh
```
<img src='http://g.gravizo.com/g?
 digraph G {
   install[shape=box,label="install.sh"];
   scanUser[label="scanUser.sh"];
   addUser[label="addUser.sh"];
   addUser_c[[label="src/addUser.c"]];
   database[shape=box,label="data/userdata.db"];
   check_atr[label="check_atr.sh"];
   install -> check_atr [style=dotted];
   check_atr -> ATR;
   install -> scanUser [style=dotted];
   scanUser -> database [style=bold,label="check id"];
   database -> scanUser [style=dotted,label="show"];
   addUser -> addUser_c;
   addUser_c -> database;
 }
'/>
