#include <stdio.h> 
#include <stdlib.h>   
int main(){ 
   pid_t  pid; 
   pid = fork(); 
   
   if (pid == 0){ 
  
      printf("child process, pid = %u\n",getpid()); 
  
      char * argv_list[] = {"ls","exec.out","a.out",NULL}; 
      execv("exec.out",argv_list); 
      exit(0); 
   }
   else
    printf("parent process, pid = %u\n",getpid());

   
   return 0; 
} 