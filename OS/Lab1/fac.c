#include <stdio.h> 
#include <stdlib.h>   
int main(){ 
   pid_t  pid; 
   printf("Enter n\n");
   int n;
   scanf("%d",&n);
   pid = fork(); 
   
   if (pid == 0){ 
   int fac=1;
      for(int i =1;i<=n;i++)
      {
         fac=fac*i;
      }
      printf("%d",fac);

   }

   
   return 0; 
} 