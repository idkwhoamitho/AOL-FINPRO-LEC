#ifndef MENU_H
#define MENU_H
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "fileIO.h"
#include <windows.h>

void printRecord(struct Item* items, int rows, float price){
    printf("------------------------------------------------------------------------------\n");
    printf("%-12s %-18s %-19s %-11s %-13s %s\n", "ITEM_ID", "SUPPLIER_ID",  "ITEM_NAME", "PRICE", "QUANTITY", "SALES");
    printf("------------------------------------------------------------------------------\n");
    float total_quantity = 0;	
    for(int i = 0; i < rows;i++)
    {
        if(items[i].price <= price && items[i].quantity + total_quantity <= quantity){
        printf("A%-11d S%-17d %-19s %-11d %-13d %d\n", items[i].id, items[i].item_name, items[i].quantity, items[i].price);
        total_quantity += items[i].quantity;
        i++;
        }
    }
	printf("==============================================================================\n");
}

void printRecordAll(struct Item* items){
    printf("-----------------------------------------------------------------------------------\n");
    printf("%-12s %-18s %-19s %-11s %-13s %s\n", "ITEM_ID", "SUPPLIER_ID",  "ITEM_NAME", "PRICE", "QUANTITY", "SALES");
    printf("-----------------------------------------------------------------------------------\n");
    float total_quantity = 0;	
    for(int i = 0; i < rows;i++)
    {
    	printf("A%-11d S%-17d %-19s %-11d %-13d %d\n", items[i].id, items[i].item_name, items[i].quantity, items[i].price);
        total_quantity += items[i].quantity;
        i++;
    }
    printf("===================================================================================\n");
}

void ModifyExistingDataMenu(){
    char choose, price, quantity;
    int id, new_price, new_quantity;
//    printProductsCatalogue();
    while (1)
    {
        printf("\n input the id of an Item: ");
        scanf("%d",&id);
//        getProductById(id, jumlahProd, &index);
        if (index == -1) {
            printf("Invalid product ID. Please try again.\n");
            continue;
        }
    	printf("\n Do you want to Modify the Price ? (Y/N) : ");
        scanf(" %c",&price);
        if(price == Y || price == y){
        	printf("\n What is the new Price ?: ");
	        scanf(" %d",&new_price);
		}
    	printf("\n Do you want to Modify the Quantity ? (Y/N) : ");
        scanf(" %c",&quantity);
        if(quantity == Y || quantity == y){
        	printf("\n What is the new Quantity ?: ");
	        scanf(" %d",&new_quantity);
		}
		
        printf("Did you want to continue modifying existing products ?(Y/N): ");
        scanf(" %c",&choose);
        if(choose == 'N' || 'n') {
            updateData();
            break;
        }
    }
}

void DeleteDataMenu(){
    char choose1, choose2;
    int id,index;
//    printProductsCatalogue();
    while (1)
    {
    	printf("INVENTORY SYSTEM\n");
        printf("INSERT RECORD MAIN MENU\n\n");
        printf("1. Supplier\n");
        printf("2. Item\n");
        printf("3. Back to Main Menu\n\n");
        printf("Your Choice: ");
        scanf("%d", &choose);
        
        if(choose == 1){
        printf("\n input the id of an inventory: ");
        scanf("%d",&id);
//        getProductById(id, jumlahProd, &index);
        if (index == -1) {
            printf("Invalid product ID. Please try again.\n");
            continue;
        }
    	printf("\nAre you sure you want to delete the Supplier data ?(Y/N) ");
		scanf(" %c",&choose1);
        getchar();
        if(choose1 == 'N' || choose1 == 'n'){
	    	break;
		} else {
			struct Product temp[jumlahProd - 1];
            int tempindex = 0;
        	for(int i = 0;i < jumlahProd;i++){
        		if(i != index){
            		temp[tempindex++] = products[i];
        		}
	    	}
//    		deleteData(temp, jumlahProd - 1);
       		jumlahProd--;
        	printf("Did you want to continue to delete data ?(Y/N): ");
        	scanf(" %c",&choose2); getchar();
        	if(choose2 == 'N' || choose2 =='n') {
            	break;
        	}
		}
            
        } else if(choose == 2){
        printf("\n input the id of an Supplier: ");
        scanf("%d",&id);
//        getProductById(id, jumlahProd, &index);
        if (index == -1) {
            printf("Invalid product ID. Please try again.\n");
            continue;
        }
    	printf("\nAre you sure you want to delete the Item data ?(Y/N) ");
		scanf(" %c",&choose1);
        getchar();
        if(choose1 == 'N' || choose1 == 'n'){
	    	break;
		} else {
			struct Product temp[jumlahProd - 1];
            int tempindex = 0;
        	for(int i = 0;i < jumlahProd;i++){
        		if(i != index){
            		temp[tempindex++] = products[i];
        		}
	    	}
//    		deleteData(temp, jumlahProd - 1);
       		jumlahProd--;
        	printf("Did you want to continue to delete data ?(Y/N): ");
        	scanf(" %c",&choose2); getchar();
        	if(choose2 == 'N' || choose2 =='n') {
            	break;
        	}
		}
                      
        } else if(choose == 3){
            break;
        }
    }
}	

#endif
