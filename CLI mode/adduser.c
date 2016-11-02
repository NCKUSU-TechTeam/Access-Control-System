#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){
	int totalLen=0;
	FILE *db;
	db = fopen("userdata.db","a");
	// argv[1] = userName
	char *prefix = "UserName:";
	for(int i=1; i<(argc) ;i++){
		totalLen += strlen(argv[i]);
	}
	char *username = (char *)malloc((totalLen+argc-2+strlen(prefix))*sizeof(char));
	strcat(username,prefix);
	for(int i=1; i<(argc) ;i++){
		strcat(username,argv[i]);
		strcat(username," ");
	}
	fprintf(db, "%s\n", username);
	fclose(db);
}
