#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
int main(){
  struct dirent * pDir;
  DIR *openD;
  openD = opendir(".");

  
  char directs[] = "Directories:\n";
  char regs[] = "Regular Files:\n";
  while((pDir = readdir(openD)) != NULL){
    if((pDir->d_type) == DT_DIR){
      //char *temp = strcat("\t", pDir->d_name);
      strcat(directs, pDir->d_name);
    }else{
      //char *temp = strcat("\t", pDir->d_name);
      strcat(regs, pDir->d_name);
    }
  }

  printf("%s\n",strcat(directs, regs));

  closedir(openD);
  return 0;
}
