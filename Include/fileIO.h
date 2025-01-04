#ifndef FILEIO_H
#define FILEIO_H
#include <stdio.h>
#include <string.h>
#include "data_processing.h"

FILE *data;
int jumlahProd;
void readFile (){
    
    data = fopen("Product_Catalogue.csv","r");
    int i = 0;
    if (data == NULL)
    {
        /* code */
        perror("An error has occured");
    }
    char line[1024];
    int index = 0;

    // Skip the header line
    fgets(line, sizeof(line), data);

    while (fscanf(data,"%d,%29[^,],%d,%ld",&products[i].ID,products[i].productName,&products[i].stock,&products[i].price) == 4 && !feof(data))
    {
        i++;
    }
    jumlahProd = i + 1;
    fclose(data);        
}

void updateData(){
   char header[1024];
   FILE *file = fopen("Product_Catalogue.csv","r");

   if (fgets(header,sizeof(header),file) == NULL)
   {
    /* code */
        perror("Error reading a header");
        fclose(file);
        return;
   }
   file = fopen("Product_Catalogue.dat","w");
   fputs(header,file);

   for (int i = 0; i < jumlahProd; i++)
   {
    /* code */
        fprintf(file,"\n%d,%d,%d",
        products[i].ID,
        products[i].productName,
        products[i].stock,
        products[i].price
        );
   }
   fclose(file);
   printf("Data updated");       
}
void deleteData(struct Product* temp, int Size){
     char header[1024];
   FILE *file = fopen("Product_Catalogue.csv","r");

   if (fgets(header,sizeof(header),file) == NULL)
   {
    /* code */
        perror("Error reading a header");
        fclose(file);
        return;
   }
   file = fopen("Product_Catalogue.csv","w");
   fputs(header,file);

   for (int i = 0; i < Size; i++)
   {
    /* code */
        fprintf(file,"\n%d,%s,%d,%ld",
        temp[i].ID,
        temp[i].productName,
        temp[i].stock,
        temp[i].price
        );
   }
   fclose(file);
   printf("\nData Deleted\n\n");       
}


void appendData(struct Product Data){
// Check for extra \n in the name
    size_t len = strlen(Data.productName);
    if (len > 0 && Data.productName[len - 1] == '\n') {
        Data.productName[len - 1] = '\0';
    }
    FILE *file = fopen("Product_Catalogue.csv","a");

    fprintf(file,"\n%d,%s,%d,%ld",
        Data.ID,
        Data.productName,
        Data.stock,
        Data.price
    );
    fclose(file);
}


#endif
