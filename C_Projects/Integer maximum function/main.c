#include <stdio.h>

int maximum(int x, int y, int z);//function declaration

int main(void){
int number1; //first integer
int number2; //second integer
int number3; //third integer
printf("Enter three integers:\n");
scanf("%d%d%d",&number1,&number2,&number3);
// number1, number2 and number3 are arguments to the maximum function call
printf("Maximum is: %d\n",maximum(number1,number2,number3));
maximum(number1,number2,number3);
return 0; //indicates successful termination
}

int maximum(int x, int y, int z)//Function maximum definition
{
int max=x; // assume x is the greatest
if (y>max){ // if y is greater than max, assign y to max
max = y;
}
if (z>max) { // if z is larger than max, assign z to max */
max=z;
}
return max; // max is largest value
//return max;
}
