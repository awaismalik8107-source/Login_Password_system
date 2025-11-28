#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "COLORS.c"
#include <unistd.h>
#include "login.h"

char login_usernames[20];
char login_authority[20];

void loading_screen()
{
  
    {
        printf("\n\n\n\n\t\t\t");
        for(int i=0;i<30;i++)
        {
            printf(BHBLU"*"reset);
        }
        printf(BHBLU"\n\t\t\t*\t\t\b\b\b\b"BMAG"%-15s"BHBLU"\t\b\b\b*\n\t\t\t*\t\t\b\b\b\b"BMAG"%-15s"BHBLU"\t\b\b\b*\n\t\t\t*\t\t\b\b\b\b "BMAG"%-15s"BHBLU"\t\b\b\b*\n\t\t\t"reset,"WELCOME","TO OUR","STORE");

        
        for(int i=0;i<30;i++)
        {
            printf(BHBLU"*"reset);
        }

        printf("\n\n\n");

    }
}



void loading()
{
    printf(BOLD"\t\tLoading...\n\t\t\t"reset);
    for(int i=0;i<40;i++)
    {  
    if(i<20)
    {
    printf("_");
    fflush(stdout);
    usleep(100000);
    }
    if(i<=25 && i>20)
    {
    printf("_");
    fflush(stdout);
    usleep(495000);
    }
    if(i>25 && i<40)
    {
    printf("_");
    fflush(stdout);
    usleep(5000);
    }
    }
}



void load()
{
    loading_screen();
    loading();
    system("clear");

}



int Login_username(char *login_username)
{
    char password[20], temp[256];
    char check_username[20], check_password[20], authority[20];
    int found;

    for(;;)
    {
        found = 0;

        printf(BLU"HOME>"MAG"LOGIN\n\n\n"reset);

        printf(BOLD"Username:- "reset);
        scanf("%19s", login_username);

        printf(BOLD"Password:- "reset);
        scanf("%19s", password);

        FILE *userlist = fopen("User-List.txt", "r");
        if(!userlist)
        {
            printf(RED"User file not found!"reset"\n");
            return 0;
        }

        while(fgets(temp, sizeof(temp), userlist))
        {
            char *ptr;

            ptr = strstr(temp, "username:-");
            if(ptr)
            {
                ptr += strlen("username:-");
                sscanf(ptr, " %19s", check_username);
            }

            if(strcasecmp(login_username, check_username) != 0)
                continue;  

           
            ptr = strstr(temp, "Password:-");
            if(ptr)
            {
                ptr += strlen("Password:-");
                sscanf(ptr, " %19s", check_password);
            }

            
            ptr = strstr(temp, "Authority level:-");
            if(ptr)
            {
                ptr += strlen("Authority level:-");
                sscanf(ptr, " %19s", authority);
            }

            found = 1;
            break;
        }

        fclose(userlist);

        if(!found)
        {
            printf(RED"\n\nUser Not Found"reset);
            printf("\n\nReturning in 3s...");
            fflush(stdout);
            sleep(3);
            continue;
        }

        if(strcmp(password, check_password) != 0)
        {
            printf(RED"\n\nWrong Password"reset);
            printf("\n\nReturning in 3s...");
            fflush(stdout);
            sleep(3);
            continue;
        }

        
        strcpy(login_usernames, login_username);
        strcpy(login_authority, authority);

        printf(BOLD"\n\nLogging in as %s (%s)...\n"reset, login_usernames, login_authority);
        loading();
        system("clear");
        return 1;
    }
}


void Login()
 {
    char username[20];
    load();  
    Login_username(username);
    strcpy(login_usernames, username);
    
}
