#include <stdio.h>
#include <stdbool.h>

bool is_primeNumber(int x);

int main()
{
	int a; //input parameter of the user
	printf("Please enter a positive integer to check whether it's a prime number:\n");
	scanf(" %d",&a);
	printf("%d ",a);
	is_primeNumber(a) ? puts("is a prime number") : puts("is not a prime number");
	return 0;
}

bool is_primeNumber(int x)
{ 
	if(x==2)//adding exception of the smallest prime number
		return true;
	for(int i=2;i<x;i++) //Checks the number until i<x
		if(x%i==0) //If remainder of division is equal to 0 then the number is not a prime number
			return false;
	return true; // otherwise the number is a prime number
}
