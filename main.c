#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void check_command(char *commandstr,int *loop)
{
  char *tok;
  tok=strtok(commandstr," ");

  if(tok==NULL) return;

  if(strcmp(tok,"exit") ==0 )
  {
    *loop=0;
  }
  else if(strcmp(tok,"echo") ==0 )
  {
    while(tok)
    {
        tok=strtok(NULL," ");
        if(tok!=NULL)
        printf("%s ",tok);
        
    }
    printf("\n");
    
  }
  else if(strcmp(tok,"type") ==0 )
  {
    tok=strtok(NULL," ");
    if(tok==NULL) return;
    if(strcmp(tok,"echo") == 0 || strcmp(tok,"type") == 0 || strcmp(tok,"exit") == 0)
      printf("%s is a shell builtin\n",tok);
    else 
      printf("%s: not found\n",tok);

   }

   else printf("%s: command not found\n",tok);
}


int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  int loop=1;
  char command[100];
  while(loop)
  {
    printf("$ ");
    fgets(command, sizeof(command), stdin);
    //Eliminated "\0" from the string
    command[strcspn(command, "\n")] = 0;  

    check_command(command,&loop);


  }
 

}

