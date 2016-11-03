#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){
	int totalLen=0;
	FILE *db;
	db = fopen("data/userdata.db","a");
	// argv[1] = userName
	char *prefix = "UserName:";
	char *cardid = argv[1];
	char *username = (char *)malloc((strlen(prefix)+strlen(cardid))*sizeof(char));
	strcat(username,prefix);
	strcat(username,cardid);
	fprintf(db, "%s\n", username);
	fclose(db);
}
