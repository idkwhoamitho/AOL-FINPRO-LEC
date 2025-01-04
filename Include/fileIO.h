#ifndef FILEIO_H
#define FILEIO_H
#include <stdio.h>
#include <string.h>
#include "data_processing.h"

FILE *data;
int jumlahProd;
int jumlahItem;
int jumlahSupplier;

void readInventoryFile (){
    
    data = fopen("Inventory.dat","r");
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

    while (fscanf(data,"%d,%d,%d",&products[i].item_id,products[i].supplier_id,&products[i].quantity) == 4 && !feof(data))
    {
        i++;
    }
    jumlahProd = i + 1;
    fclose(data);        
}
void readItemFile (){
    
    data = fopen("Item.dat","r");
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

    while (fscanf(data,"%d,%s,%d",&item[i].id,item[i].item_name,&item[i].price) == 4 && !feof(data))
    {
        i++;
    }
    jumlahItem = i + 1;
    fclose(data);        
}

void readSupplierFile (){
    
    data = fopen("Supplier.dat","r");
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

    while (fscanf(data,"%d,%s,%s",&supplier[i].id,supplier[i].name,&supplier[i].phone_number) == 4 && !feof(data))
    {
        i++;
    }
    jumlahSupplier = i + 1;
    fclose(data);        
}

void UpdateInventoryData(){
   char header[1024];
   FILE *file = fopen("inventory.dat","r");

   if (fgets(header,sizeof(header),file) == NULL)
   {
    /* code */
        perror("Error reading a header");
        fclose(file);
        return;
   }
   file = fopen("inventory.dat","w");
   fputs(header,file);

   for (int i = 0; i < jumlahProd; i++)
   {
    /* code */
        fprintf(file,"\n%d,%d,%d",
        products[i].item_id,
        products[i].supplier_id,
        products[i].quantity
        );
   }
   fclose(file);
   printf("Data updated");       
}
void UpdateItemData(){
   char header[1024];
   FILE *file = fopen("item.dat","r");

   if (fgets(header,sizeof(header),file) == NULL)
   {
    /* code */
        perror("Error reading a header");
        fclose(file);
        return;
   }
   file = fopen("item.dat","w");
   fputs(header,file);

   for (int i = 0; i < jumlahProd; i++)
   {
    /* code */
        fprintf(file,"\n%d,%s,%d",
        item[i].id,
        item[i].item_name,
        item[i].price
        );
   }
   fclose(file);
   printf("Data updated");       
}
void UpdateSupplierData(){
   char header[1024];
   FILE *file = fopen("supplier.dat","r");

   if (fgets(header,sizeof(header),file) == NULL)
   {
    /* code */
        perror("Error reading a header");
        fclose(file);
        return;
   }
   file = fopen("supplier.dat","w");
   fputs(header,file);

   for (int i = 0; i < jumlahProd; i++)
   {
    /* code */
        fprintf(file,"\n%d,%s,%s",
        supplier[i].id,
        supplier[i].name,
        supplier[i].phone_number
        );
   }
   fclose(file);
   printf("Data updated");       
}



void deleteItemData(struct Item* temp, int Size){
     char header[1024];
   FILE *file = fopen("item.dat","r");

   if (fgets(header,sizeof(header),file) == NULL)
   {
    /* code */
        perror("Error reading a header");
        fclose(file);
        return;
   }
   file = fopen("item.dat","w");
   fputs(header,file);

   for (int i = 0; i < Size; i++)
   {
    /* code */
        fprintf(file,"\n%d,%s,%d",
        temp[i].id,
        temp[i].item_name,
        temp[i].price
        );
   }
   fclose(file);
   printf("\nData Deleted\n\n");       
}

void deleteSupplierData(struct Supplier* temp, int Size){
     char header[1024];
   FILE *file = fopen("supplier.dat","r");

   if (fgets(header,sizeof(header),file) == NULL)
   {
    /* code */
        perror("Error reading a header");
        fclose(file);
        return;
   }
   file = fopen("supplier.dat","w");
   fputs(header,file);

   for (int i = 0; i < Size; i++)
   {
    /* code */
        fprintf(file,"\n%d,%s,%s",
        temp[i].id,
        temp[i].name,
        temp[i].phone_number
        );
   }
   fclose(file);
   printf("\nData Deleted\n\n");       
}
void appendItemData(struct Item Data){
// Check for extra \n in the name
    size_t len = strlen(Data.item_name);
    if (len > 0 && Data.item_name[len - 1] == '\n') {
        Data.item_name[len - 1] = '\0';
    }
    FILE *file = fopen("item.dat","a");

    fprintf(file,"\n%d,%s,%d",
        Data.id,
        Data.item_name,
        Data.price
    );
    fclose(file);
}
void appendSupplierData(struct Supplier Data){
// Check for extra \n in the name
    size_t len = strlen(Data.name);
    if (len > 0 && Data.name[len - 1] == '\n') {
        Data.name[len - 1] = '\0';
    }
    FILE *file = fopen("Supplier.dat","a");

    fprintf(file,"\n%d,%s,%d",
        Data.id,
        Data.name,
        Data.phone_number
    );
    fclose(file);
}

void appendInventoryData(struct Inventory Data){

    FILE *file = fopen("Supplier.dat","a");

    fprintf(file,"\n%d,%s,%d",
        Data.item_id,
        Data.supplier_id,
        Data.quantity
    );
    fclose(file);
}

#endif
