#include <stdio.h>
#include <stdlib.h>

void prime_number(int x);//function declaration

int main(){
    int a;//input parameter of the user
    printf("Please enter a positive integer to check whether it's a prime number:\n");
    scanf(" %d",&a);//taking the input
    prime_number(a);//function call
    return 0;
}

void prime_number(int x){ //Function definition
    if(x==2)//adding exception of the smallest prime number
        printf("2 is a prime number");
    for(int i=2;i<x;i++){//Checks the number until i<x
		if(x%i==0){//If remainder of division is equal to 0, print it and then break the for loop
			printf("%d is not a prime number",x);
			break;
		}
		else if(i<(x-1))//Skip printing until i<(x-1), if it still meets the condition
			continue;
		else//So it's a prime number, print it and for loop ends
			printf("%d is a prime number",x);
    }
}
