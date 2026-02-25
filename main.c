#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_command(char *commandstr,int *loop)
{
  if(strcmp(commandstr,"exit")==0)
   *loop=0;
  else if(strncmp(commandstr,"echo ",5)==0)
  printf("%s\n",commandstr+5);
  else printf("%s command not found\n",commandstr); 
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
    command[strcspn(command, "\n")] = 0;

    check_command(command,&loop);


  }
 

}
