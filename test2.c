#include <stdio.h>

char auth_file[50]="data/auth.csv";


//authentication
bool auth(int user_type,char user_name[50],char password[50]){
	int match=0;
	int user_type_in_file;
	char user_name_in_file[50];
	char password_in_file[50];
	char securityQ_in_file[50];
	FILE *auth_file=fopen(auth_file,"r");
	if (file == NULL) {
        printf("Error opening the file.\n");
        return 0;
    }
	char read_line[100];

	do{
        fscanf(auth_file,"%d,%[^,],%[^,],%s", &user_type_in_file, user_name_in_file, password_in_file, securityQ_in_file);
	}while((match==1)||feof(auth_file));

    return match;
}

int main(){
    char user_name[50];
    char password[50];
    int user_type;
    printf("Enter user type: ");
    scanf("%d",&user_type);
    printf("Enter user name: ");
    scanf("%s",user_name);
    printf("Enter password: ");
    scanf("%s",password);
    if(auth(user_type,user_name,password)){
        printf("Authentication successful\n");
    }
    else{
        printf("Authentication failed\n");
    }
    return 0;
}