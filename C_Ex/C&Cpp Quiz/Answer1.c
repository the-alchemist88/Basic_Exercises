#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "Product.txt" // filename to create under the current folder
#define DISCOUNT_RATE 5
#define LINE_LENGTH 100
#define TITLE_FORMAT_OUT "%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n\n"
#define TXT_FORMAT_OUT "%-15s%-15s%-15s%-15d%-15.2f%-15d%-15.2f\n"

static unsigned short product_counter = 1;

struct OrderRecord 
{
    char Name[LINE_LENGTH];
    char Surname[LINE_LENGTH];
    char Product[LINE_LENGTH];
    int Quantity;
    float Price;
    
};

void serialize(struct OrderRecord *s, FILE *f); // for saving to txt file
float discount(struct OrderRecord *p);

int main(int argc, char **argv)
{
    FILE* data = NULL;
    
    data = fopen (FILE_NAME, "w+");
    if(data == NULL) 
    {
        perror("Error on opening file:");
        exit(0);
    }
    printf("%s has been created\n", FILE_NAME);
    
    fprintf(data,TITLE_FORMAT_OUT,"Name","Surname","Product","Quantity","Old Price[$]","Discount[%]","New Price[$]");
    fclose(data);
    
    struct OrderRecord p1 = {
        .Name = "Hank",
        .Surname = "Rearden",
        .Product = "Bicycle",
        .Quantity = 7,
        .Price = 100.0
    };
    
    struct OrderRecord p2 = {
        .Name = "Dagny",
        .Surname = "Taggart",
        .Product = "Television",
        .Quantity = 10,
        .Price = 200.0
    };
    
    struct OrderRecord p3 = {
        .Name = "John",
        .Surname = "Galt",
        .Product = "Computer",
        .Quantity = 25,
        .Price = 300.0
    };
    
    serialize(&p1, data);
    serialize(&p2, data);
    serialize(&p3, data);

	return 0;
}

float discount(struct OrderRecord *p)
{
    float newPrice = (p->Price) * ( (100.0 - DISCOUNT_RATE) / 100.0) ; // %5 discount
    return newPrice;
}

void serialize(struct OrderRecord *p, FILE *f)
{
    f = fopen (FILE_NAME, "a");
    if(f == NULL) 
    {
        perror("Error on opening file:");
        exit(0);
    }
    printf("Text has been appended to %s, number of product added = %hu \n", FILE_NAME, product_counter);
    product_counter++;
    
    float newPrice = discount(p);
//    fseek(f, 0, SEEK_SET);

    fprintf(f, TXT_FORMAT_OUT, p->Name, p->Surname, p->Product, p->Quantity, p->Price, DISCOUNT_RATE, newPrice);
    
    fclose(f);
}