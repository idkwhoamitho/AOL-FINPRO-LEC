#ifndef MENU_H
#define MENU_H
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "fileIO.h"
#include <windows.h>

void printRecord(int rows, float price, int quantity){
    printf("------------------------------------------------------------------------------\n");
    printf("%-12s %-18s %-19s %-11s %-13s %s\n", "ITEM_ID", "SUPPLIER_ID",  "ITEM_NAME", "PRICE", "QUANTITY", "SALES");
    printf("------------------------------------------------------------------------------\n");
    float total_quantity = 0;	
    for(int i = 0; i < rows;i++)
    {
        if(item[i].price <= price && products[i].quantity + total_quantity <= quantity){
    	printf("A%-11d S%-17d %-19s %-11d %-13d %d\n", item[i].id, item[i].item_name, products[i].quantity, item[i].price);
//        printf("A%-11d S%-17d %-19s %-11d %-13d %d\n", item[i].id, item[i].item_name, items[i].price , items[i].price);
        total_quantity += products[i].quantity;
        i++;
        }
    }
	printf("==============================================================================\n");
}

void printRecordAll(){
    printf("-----------------------------------------------------------------------------------\n");
    printf("%-12s %-18s %-19s %-11s %-13s %s\n", "ITEM_ID", "SUPPLIER_ID",  "ITEM_NAME", "PRICE", "QUANTITY", "SALES");
    printf("-----------------------------------------------------------------------------------\n");
    float total_quantity = 0;	
    for(int i = 0; i < jumlahItem;i++)
    {
//    	printf("A%-11d S%-17d %-19s %-11d %-13d %d\n", item[i].id, item[i].item_name, products[i].quantity, item[i].price);
//        printf("A%-11d S%-17d %-19s %-11d %-13d %d\n", item[i].id, items[i].item_name, item[i].price , item[i].price);
        total_quantity += products[i].quantity;
        
        int productIndex = -1;
        getProductById(item[i].id, jumlahProd, &productIndex);
        
        if (productIndex != -1) {
            // Calculate sales as price multiplied by quantity
            float sales = item[i].price * products[productIndex].quantity;
            
            printf("%-12d %-18d %-19s %-11.2f %-13d %-11.2f\n", 
                item[i].id, 
                products[productIndex].supplier_id, 
                item[i].item_name, 
                item[i].price, 
                products[productIndex].quantity,
                sales); // Print the calculated sales
        }
    }
    printf("===================================================================================\n");
}

void ModifyExistingDataMenu(){
    char choose, price, quantity;
    int id, new_price, new_quantity, index;
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
        if(price == 'Y' || price == 'y'){
        	printf("\n What is the new Price ?: ");
	        scanf(" %d",&new_price);
		}
    	printf("\n Do you want to Modify the Quantity ? (Y/N) : ");
        scanf(" %c",&quantity);
        if(quantity == 'Y' || quantity == 'y'){
        	printf("\n What is the new Quantity ?: ");
	        scanf(" %d",&new_quantity);
		}
		
        printf("Did you want to continue modifying existing products ?(Y/N): ");
        scanf(" %c",&choose);
        if(choose == 'N' || 'n') {
//            updateData();
            break;
        }
    }
}

void DeleteDataMenu(){
    char choose1, choose2;
    int id,index, choose;
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
//			struct Product temp[jumlahProd - 1];
//            int tempindex = 0;
//        	for(int i = 0;i < jumlahProd;i++){
//        		if(i != index){
//            		temp[tempindex++] = products[i];
//        		}
//	    	}
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
//			struct Product temp[jumlahProd - 1];
//            int tempindex = 0;
//        	for(int i = 0;i < jumlahProd;i++){
//        		if(i != index){
//            		temp[tempindex++] = products[i];
//        		}
//	    	}
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
