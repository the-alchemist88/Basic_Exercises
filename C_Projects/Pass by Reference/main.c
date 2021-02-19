#include <stdio.h>
#include <stdlib.h>

struct DataSet{//
    char data1;
    int data2;
    char data3;
    short data4;
}data;

void displayMemberElements(struct DataSet *pdata);//  prototype of a function that takes a struct pointer as an argument

int main(){

data.data1=0x11;//assigning some values to variables inside the struct
data.data2=0xFFFFEEEE;
data.data3=0x22;
data.data4=0xABCD;

displayMemberElements(&data);//sending the address of "data" structure as a parameter to function
                             //in order to print them out using address of "data" rather than value

    return 0;
}
void displayMemberElements(struct DataSet *pdata){//definition of the function that reaches the variables inside
                                                  //the struct via pointer "pdata"
    printf("data1 = %X\n",pdata->data1);
    printf("data2 = %X\n",pdata->data2);
    printf("data3 = %X\n",pdata->data3);
    printf("data4 = %X\n",pdata->data4);

}
