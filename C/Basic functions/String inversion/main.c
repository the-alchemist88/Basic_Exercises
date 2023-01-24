#include <stdio.h>
#include <stdlib.h>

char* invert_string(char*);

int main()
{
	char s[100];    // define a buffer to store user string
	char* inverted; // define a string buffer to store inverted string
	printf("Enter a string to invert:\n");
	gets(s);		//read user string into char array
	inverted = invert_string(s);
	printf("Inverted string: \n%s\n",inverted);
	return 0;
}

char* invert_string(char* s)
{
	int i,n;
	char temp;
	for(n=0; s[n]!= '\0'; n++); // count the letters of the string
	for(i=0;i<n/2;i++) 			//swap letters from the beginning with the end, n/2 times
	{							//index will be 1 less than quantity of letters since it begins from 0(so n-1)
		temp=s[n-1-i]; 			//in order not to lose data, first assign last index to a temp variable
		s[n-1-i]=s[i]; 			//assign first index to last
		s[i]=temp; 				//assign last index to first
	}

	return s;
}