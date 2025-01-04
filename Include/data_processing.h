#ifndef DATAPROCESSING_H
#define DATAPROCESSING_H
#include <stdio.h>

struct Item {
    int id;
    char item_name[50];
    float price;
};

struct Supplier {
    int id;
    char name[50];
    char phone_number[20];
};

struct Inventory {
    int item_id;
    int supplier_id;
    int quantity;
};
struct Inventory products[100];
struct Item item[100];
struct Supplier supplier[100];


// int product_size = sizeof(products)/sizeof(products[0]);



void getProductById(int id,int size,int *index){
	*index = -1;
    int i = 0;
    for (;i < size; i++)
    {
        /* code */
        if(products[i].item_id == id) {
            *index = i;
            break;
        }        
    }
    
    if(*index == -1) {
        printf("Product Not Found\n");
        return;
    }
}

void GetItemById(int id,int size,int *index){
	*index = -1;
    int i = 0;
    for (;i < size; i++)
    {
        /* code */
        if(item[i].id == id) {
            *index = i;
            break;
        }        
    }
    
    if(*index == -1) {
        printf("Product Not Found\n");
        return;
    }
}

void GetSupplierById(int id,int size,int *index){
	*index = -1;
    int i = 0;
    for (;i < size; i++)
    {
        /* code */
        if(supplier[i].id == id) {
            *index = i;
            break;
        }        
    }
    
    if(*index == -1) {
        printf("Product Not Found\n");
        return;
    }
}

void SortItemById(int jumlahProd){
    struct Item temp;
    int sortType = 0;
       while (1)
       {
            printf("Ascending or Descending ?\n");
            printf("Ascending = 1\n");
            printf("Descending = 2\n");
            printf("Your Choice : ");
            scanf("%d", &sortType);
            if(sortType == 1) break;
            else if(sortType == 2) break;
       }
    if(sortType == 1){
        for (int i = 0; i < jumlahProd - 1; i++)
        {
            /* code */
            for (int j = 0; j < jumlahProd - i -1; j++)
            {
                /* code */
                if(item[j].id > item[j+1].id){
                    temp = item[j];
                    item[j] = item[j + 1];
                    item[j + 1] = temp;
                }
            }
            
        }
        
    }

    else if(sortType == 2){
        for (int i = 0; i < jumlahProd - 1; i++)
        {
            /* code */
            for (int j = 0; j < jumlahProd - i -1; j++)
            {
                /* code */
                if(item[j].id < item[j+1].id){
                    temp = item[j];
                    item[j] = item[j + 1];
                    item[j + 1] = temp;
                }
            }
            
        }
        
    }
}
void sortProductById(int jumlahProd){
    struct Inventory temp;
    int sortType = 0;
       while (1)
       {
            printf("Ascending or Descending ?\n");
            printf("Ascending = 1\n");
            printf("Descending = 2\n");
            printf("Your Choice : ");
            scanf("%d", &sortType);
            if(sortType == 1) break;
            else if(sortType == 2) break;
       }
    if(sortType == 1){
        for (int i = 0; i < jumlahProd - 1; i++)
        {
            /* code */
            for (int j = 0; j < jumlahProd - i -1; j++)
            {
                /* code */
                if(products[j].item_id > products[j+1].item_id){
                    temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                }
            }
            
        }
        
    }

    else if(sortType == 2){
        for (int i = 0; i < jumlahProd - 1; i++)
        {
            /* code */
            for (int j = 0; j < jumlahProd - i -1; j++)
            {
                /* code */
                if(products[j].item_id < products[j+1].item_id){
                    temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                }
            }
            
        }
        
    }
}
void sorSupplierById(int jumlahProd){
    struct Supplier temp;
    int sortType = 0;
       while (1)
       {
            printf("Ascending or Descending ?\n");
            printf("Ascending = 1\n");
            printf("Descending = 2\n");
            printf("Your Choice : ");
            scanf("%d", &sortType);
            if(sortType == 1) break;
            else if(sortType == 2) break;
       }
    if(sortType == 1){
        for (int i = 0; i < jumlahProd - 1; i++)
        {
            /* code */
            for (int j = 0; j < jumlahProd - i -1; j++)
            {
                /* code */
                if(supplier[j].id > supplier[j+1].id){
                    temp = supplier[j];
                    supplier[j] = supplier[j + 1];
                    supplier[j + 1] = temp;
                }
            }
            
        }
        
    }

    else if(sortType == 2){
        for (int i = 0; i < jumlahProd - 1; i++)
        {
            /* code */
            for (int j = 0; j < jumlahProd - i -1; j++)
            {
                /* code */
                if(supplier[j].id < supplier[j+1].id){
                    temp = supplier[j];
                    supplier[j] = supplier[j + 1];
                    supplier[j + 1] = temp;
                }
            }
            
        }
        
    }
}


void sortProductByStock(int jumlahProd){
    struct Inventory temp;
     int sortType = 0;
       while (1)
       {
            printf("Ascending or Descending ?\n");
            printf("Ascending = 1\n");
            printf("Descending = 2\n");
            printf("Your Choice : ");
            scanf("%d", &sortType);
            if(sortType == 1) break;
            else if(sortType == 2) break;
       }
    if(sortType == 1){
        for (int i = 0; i < jumlahProd - 1; i++)
        {
            /* code */
            for (int j = 0; j < jumlahProd - i -1; j++)
            {
                /* code */
                if(products[j].quantity > products[j+1].quantity){
                    temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                }
            }
            
        }
    }
    else if(sortType == 2){
        for (int i = 0; i < jumlahProd - 1; i++)
        {
            /* code */
            for (int j = 0; j < jumlahProd - i -1; j++)
            {
                /* code */
                if(products[j].quantity < products[j+1].quantity){
                    temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                }
            }
        }
                    
    }
    
}
int GetItemQuantity(int id, int size){
    int index;
    getProductById(id,jumlahProd,&index);

    return products[index].quantity;
}

#endif
