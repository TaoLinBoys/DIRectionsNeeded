#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>

int main(){
  struct dirent * pDir;
  struct stat *fileS = (struct stat*)malloc(sizeof(struct stat));
  DIR *openD;
  int fileSize;

  //DIRECTORY TOTAL SIZE
  openD = opendir(".");
  while(pDir = readdir(openD)){
    if((pDir->d_type) == DT_REG){
      stat(pDir->d_name, fileS);
      fileSize += fileS->st_size;
    }
  }
  printf("Total File Size: %d\n", fileSize);
  free(fileS);
  closedir(openD);
  
  //PRINTING FILES
  openD = opendir(".");
  printf("Directories:\n");
  while(pDir = readdir(openD)){
    if((pDir->d_type) == DT_DIR){
      printf("\t%s\n",pDir->d_name);
    }
  }
  closedir(openD);

  openD = opendir(".");
  printf("Regular Files:\n");
  while(pDir = readdir(openD)){
    if((pDir->d_type) == DT_REG){
      printf("\t%s\n",pDir->d_name);
    }
  }
  closedir(openD);
  
  return 0;
}
