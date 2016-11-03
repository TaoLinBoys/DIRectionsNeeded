#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
int main(){
  struct dirent * pDir;
  DIR *openD;
  openD = opendir(".");

  printf("Directories:\n");
  while((pDir = readdir(openD)) != NULL){
    if((pDir->d_type) == DT_DIR){
      printf("\t%s\n",pDir->d_name);
    }
  }
  closedir(openD);

  openD = opendir(".");
  printf("Regular Files:\n");
  while((pDir = readdir(openD)) != NULL){
    if((pDir->d_type) == DT_REG){
      printf("\t%s\n",pDir->d_name);
    }
  }
  closedir(openD);
  
  return 0;
}
