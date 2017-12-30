
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
char command[1000];

while (1){
printf("shellebrate>>>");
scanf("%[^\n]%*c", command);
if (strcmp(command,"exit") == 0){
return 0;
}

char *arg[100];
int i=0;
char *tok;
tok=strtok(command," ");
while (tok!=NULL){
arg[i]=tok;
tok=NULL;
i++;
}
arg[i]=NULL;

char* path= "/bin/";
char progpath[1000];

strcpy(progpath, path);           
strcat(progpath, arg[0]);  
int f=fork();
 
if (f == 0){
execvp(progpath,arg);
}
else{
wait(NULL);
}
}
}
