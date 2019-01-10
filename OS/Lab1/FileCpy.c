#include <stdio.h>
#include<stdlib.h>

void main(){

	char ch,src[30],des[30];
	FILE *s,*d;

	printf("Enter source path\n");
	gets(src);
	printf("ENter destination path\n");
	gets(des);


	s=fopen(src,"r");
	d=fopen(des,"w");
	while ((ch = fgetc(s)) != EOF)
      fputc(ch, d);

  printf("Sucess\n");

 
}