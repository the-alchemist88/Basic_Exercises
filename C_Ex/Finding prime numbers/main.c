#include <stdio.h>
#include <stdlib.h>

void prime_number_finder(int x);//function declaration

int main(){
    int a;//input parameter of the user
    printf("Please enter a positive integer to see the prime numbers until that number\n");
    scanf(" %d",&a);//taking the input

    prime_number_finder(a);//function call
    return 0;
}

void prime_number_finder(int x){//function definition
    printf("Prime numbers until %d :",x);
    if(x>=2)//adding exception of the smallest prime number
        printf(" 2");
    for(int j=3;j<=x;j++){//Starts counting the numbers up to argument "x" to check each of them
        for(int i=2;i<j;i++){//Checks the number whether its a prime or not by method of division
            if(j%i==0){//If remainder of division is equal to 0, print it and then break the for loop
                break;
            }
            else if(i<(j-1))//Skip printing until i<(x-1), if it still meets the condition
                continue;
            else{//So it's a prime number, print it and first for loop ends
                printf("%3d",j);
            }
        }
    }
}
