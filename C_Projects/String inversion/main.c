#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[50], temporary;//declaration of char array, and char variable tempopary
    int i,n;//declaration of iteration and index variable
    printf("Enter a string : ");
    gets(s);//read the char array
    for(n=0; s[n]!= '\0'; n++); // count the letters of the string
        printf("The string has %d letters.\n",n);
    for(i=0;i<n/2;i++){//swap letters from the beginning with the end, n/2 times
                       //index will be 1 less than quantity of letters since it begins from 0(so n-1)
            temporary=s[n-1-i];//in order not to lose data, first assign last index to a temporary variable
            s[n-1-i]=s[i];//assign first index to last
            s[i]=temporary;//assign last index to first
    }
    printf("Inverted form of string : %s\n",s);
    return 0;
}
