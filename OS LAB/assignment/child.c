#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
  pid_t p1,p2;
  int y=0;
  p1=fork();
  
  if(p1>0){
    wait(NULL);
    y=y-1;
    printf("This is parent. Process Id=%d,y=%d\n",getpid(),y);
    execl("/bin/ls","home/Desktop",NULL);
  }
  else if(p1==0){
  y++;
  printf("This is child.Process Id = %d,Parent process =%d,y=%d\n",getppid(),getpid(),y);
   
   char *a[]={NULL};
   execv("/home/Desktop/gcc.c",a);
   exit(0);
   }
   else{
   printf("fork creation failed\n");
   }

}
