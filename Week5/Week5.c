#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void showBytes(unsigned char* data, size_t size){
  unsigned char* p = data;
  for(int i=0;i<size;i++){
    printf("%.2x ",*(p+i));
  }
}

void showIntBytes(int* data, size_t size){
  unsigned char* p = (unsigned char*) data;
  for(int i=0;i<size;i++){
    printf("%.2x ",*(p+i));
  }
}

int main(){
  char filename[200];
  printf("Enter the path for and input file:");
  if(scanf("%s", filename)!=1) {printf("\n ERROR: Enter the path correctly\n ");}
    FILE *fp =fopen(filename,"r");
    char name[50];
    char goal[50];
    printf("Name                               Goals\n");
    while(fscanf(fp, "%s %s", name, goal) != EOF){
      int intGoal=atoi(goal);
      showBytes(name, strlen(name));
      printf("                    ");
      showIntBytes(&intGoal, sizeof(int));
      printf("\n");
    }

}
