#include <stdio.h>

int main(int argc, char *argv[])
{
	char car1;                          		
	scanf("%c",&car1);               
	int num1 =(int)car1;           // cast the character caputred into int ascii code
	int num2 =(int)(*argv[1]);     // cast the argument into an int ascii code
	int result = num1-num2;        // get the difference between the characters
	printf("%d \n" , result);      // print results on the standard out
	return 0;	
}