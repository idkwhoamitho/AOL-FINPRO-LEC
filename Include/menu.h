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
            float sales = item[i].price * products[productIndex].quantity;
            
            printf("%-12d %-18d %-19s %-11.2f %-13d %-11.2f\n", 
                item[i].id, 
                products[productIndex].supplier_id, 
                item[i].item_name, 
                item[i].price, 
                products[productIndex].quantity,
                sales);
        }
    }
    printf("===================================================================================\n");
}

void showRecordMenu() {
    int rowsToShow;
    printf("Enter the number of rows to display (max %d): ", jumlahItem);
    scanf("%d", &rowsToShow);

    if (rowsToShow > jumlahItem) {
        rowsToShow = jumlahItem;
    }

    printf("-----------------------------------------------------------------------------------\n");
    printf("%-12s %-18s %-19s %-11s %-13s %s\n", "ITEM_ID", "SUPPLIER_ID",  "ITEM_NAME", "PRICE", "QUANTITY", "SALES");
//    printf("%-12s %-18s %-19s %-11s %-13s\n", "ITEM_ID", "SUPPLIER_ID", "ITEM_NAME", "PRICE", "QUANTITY");
    printf("-----------------------------------------------------------------------------------\n");

    float totalPrice = 0.0;
    int totalQuantity = 0;

    for (int i = 0; i < rowsToShow; i++) {
        int productIndex = -1;
        getProductById(item[i].id, jumlahProd, &productIndex);

        if (productIndex != -1) {
            float sales = item[i].price * products[productIndex].quantity;
            
            printf("%-12d %-18d %-19s %-11.2f %-13d %-11.2f\n", 
                item[i].id, 
                products[productIndex].supplier_id, 
                item[i].item_name, 
                item[i].price, 
                products[productIndex].quantity,
                sales);

            totalPrice += sales;
            totalQuantity += products[productIndex].quantity;
        }
    }

    printf("-----------------------------------------------------------------------------------\n");
    printf("%-12s %-18s %-19s %-11s %-13d %5.2f\n", "Grand Total", "",  "", "", totalQuantity, totalPrice);
//    printf("%-12s %-18s %-19s %-11.2f %-13d\n", "Grand Total", "", "", totalPrice, totalQuantity);
    printf("===================================================================================\n");
}

void SelectData() {
    int choice;
    printf("INVENTORY SYSTEM\n");
    printf("SELECT DATA MAIN MENU\n\n");
    printf("1. Select by Item ID\n");
    printf("2. Select by Supplier ID\n");
    printf("3. Back to Main Menu\n\n");
    printf("Your Choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int itemId;
        printf("Enter the Item ID to select: ");
        scanf("%d", &itemId);

        // Find the item by ID
        int itemIndex = -1;
        for (int i = 0; i < jumlahItem; i++) {
            if (item[i].id == itemId) {
                itemIndex = i;
                break;
            }
        }

        if (itemIndex != -1) {
            // Display the item details
            printf("-----------------------------------------------------------------------------------\n");
            printf("%-12s %-25s %-19s %-11s\n", "ITEM_ID", "ITEM_NAME", "PRICE", "QUANTITY");
            printf("-----------------------------------------------------------------------------------\n");

            // Find the corresponding product for the item
            int productIndex = -1;
            getProductById(item[itemIndex].id, jumlahProd, &productIndex);

            if (productIndex != -1) {
                printf("%-12d %-25s %-19.2f %-11d\n",
                    item[itemIndex].id,
                    item[itemIndex].item_name,
                    item[itemIndex].price,
                    products[productIndex].quantity);
            } else {
                printf("No inventory record found for Item ID %d.\n", itemId);
            }
            printf("===================================================================================\n");
        } else {
            printf("Item with ID %d not found.\n\n", itemId);
        }

    } else if (choice == 2) {
        int supplierId;
        printf("Enter the Supplier ID to select: ");
        scanf("%d", &supplierId);

        // Find the supplier by ID
        int supplierIndex = -1;
        for (int i = 0; i < jumlahSupplier; i++) {
            if (supplier[i].id == supplierId) {
                supplierIndex = i;
                break;
            }
        }

        if (supplierIndex != -1) {
            // Display the supplier details
            printf("-----------------------------------------------------------------------------------\n");
            printf("%-30s %-30s %-30s\n", "SUPPLIER_ID", "SUPPLIER_NAME", "PHONE_NUMBER");
            printf("-----------------------------------------------------------------------------------\n");

            printf("%-30d %-30s %-30s\n",
                supplier[supplierIndex].id,
                supplier[supplierIndex].name,
                supplier[supplierIndex].phone_number);
            printf("===================================================================================\n");
        } else {
            printf("Supplier with ID %d not found.\n\n", supplierId);
        }

    } else if (choice == 3) {
        return; // Go back to the main menu
    } else {
        printf("Invalid choice. Please try again.\n");
    }
}

void ModifyExistingDataMenu(){
    int choose;
    while (1) {
        printf("INVENTORY SYSTEM\n");
        printf("MODIFY RECORD MAIN MENU\n\n");
        printf("1. Supplier\n");
        printf("2. Item\n");
        printf("3. Inventory\n");
        printf("4. Back to Main Menu\n\n");
        printf("Your Choice: ");
        scanf("%d", &choose);

        if (choose == 1) {
            int supplierId;
            printf("Enter the supplier id of the record to modify: ");
            scanf("%d", &supplierId);

            int index = -1;
            for (int i = 0; i < jumlahSupplier; i++) {
                if (supplier[i].id == supplierId) {
                    index = i;
                    break;
                }
            }

            if (index != -1) {
                char choice;
                printf("Do you want to modify the name? (Y/N): ");
                scanf(" %c", &choice);
                if (choice == 'Y' || choice == 'y') {
                    printf("Enter the new supplier name: ");
                    scanf("%s", supplier[index].name);
                }

                printf("Do you want to modify the phone number? (Y/N): ");
                scanf(" %c", &choice);
                if (choice == 'Y' || choice == 'y') {
                    printf("Enter the new supplier phone number: ");
                    scanf("%s", supplier[index].phone_number);
                }

                UpdateSupplierData(); 
                printf("Supplier record with id %d modified successfully.\n\n", supplierId);
            } else {
                printf("Supplier record with id %d not found.\n\n", supplierId);
            }

        } else if (choose == 2) {
            int itemId;
            printf("Enter the item id of the record to modify: ");
            scanf("%d", &itemId);

            int index = -1;
            for (int i = 0; i < jumlahItem; i++) {
                if (item[i].id == itemId) {
                    index = i;
                    break;
                }
            }

            if (index != -1) {
                char choice;
                printf("Do you want to modify the item name? (Y/N): ");
                scanf(" %c", &choice);
                if (choice == 'Y' || choice == 'y') {
                    printf("Enter the new item name: ");
                    scanf("%s", item[index].item_name);
                }

                printf("Do you want to modify the price? (Y/N): ");
                scanf(" %c", &choice);
                if (choice == 'Y' || choice == 'y') {
                    printf("Enter the new price: ");
                    scanf("%f", &item[index].price);
                }

                UpdateItemData();
                printf("Item record with id %d modified successfully.\n\n", itemId);
            } else {
                printf("Item record with id %d not found.\n\n", itemId);
            }

        } else if (choose == 3) {
            int itemId;
            printf("Enter the item id of the inventory record to modify: ");
            scanf("%d", &itemId);

            int index = -1;
            for (int i = 0; i < jumlahProd; i++) {
                if (products[i].item_id == itemId) {
                    index = i;
                    break;
                }
            }

            if (index != -1) {
                char choice;
                printf("Do you want to modify the supplier id? (Y/N): ");
                scanf(" %c", &choice);
                if (choice == 'Y' || choice == 'y') {
                    printf("Enter the new supplier id: ");
                    scanf("%d", &products[index].supplier_id);
                }

                printf("Do you want to modify the quantity? (Y/N): ");
                scanf(" %c", &choice);
                if (choice == 'Y' || choice == 'y') {
                    printf("Enter the new quantity: ");
                    scanf("%d", &products[index].quantity);
                }

                UpdateInventoryData();
                printf("Inventory record with item id %d modified successfully.\n\n", itemId);
            } else {
                printf("Inventory record with item id %d not found.\n\n", itemId);
            }

        } else if (choose == 4) {
            break; // Go back to the main menu
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void DeleteDataMenu(){
    int choose;
    while (1)
    {
        printf("INVENTORY SYSTEM\n");
        printf("DELETE RECORD MAIN MENU\n\n");
        printf("1. Supplier\n");
        printf("2. Item\n");
        printf("3. Inventory\n");
        printf("4. Back to Main Menu\n\n");
        printf("Your Choice: ");
        scanf("%d", &choose);
        
        if(choose == 1){
        int supplierId;
            printf("Enter the supplier id of the record to delete: ");
            scanf("%d", &supplierId);
            
            int index = -1;
            for (int i = 0; i < jumlahSupplier; i++) {
                if (supplier[i].id == supplierId) {
                    index = i;
                    break;
                }
            }

            if (index != -1) {
                for (int i = index; i < jumlahSupplier - 1; i++) {
                    supplier[i] = supplier[i + 1];
                }
                jumlahSupplier--;
                UpdateSupplierData();
                printf("Supplier record with id %d deleted successfully.\n\n", supplierId);
            } else {
                printf("Supplier record with id %d not found.\n\n", supplierId);
            }
        } else if(choose == 2){
        int itemId;
            printf("Enter the item id of the record to delete: ");
            scanf("%d", &itemId);
            
            int index = -1;
            for (int i = 0; i < jumlahItem; i++) {
                if (item[i].id == itemId) {
                    index = i;
                    break;
                }
            }

            if (index != -1) {
                for (int i = index; i < jumlahItem - 1; i++) {
                    item[i] = item[i + 1];
                }
                jumlahItem--;
                UpdateItemData();
                printf("Item record with id %d deleted successfully.\n\n", itemId);
            } else {
                printf("Item record with id %d not found.\n\n", itemId);
            }
        } else if(choose == 3){
        	int itemId;
            printf("Enter the item id of the inventory record to delete: ");
            scanf("%d", &itemId);
            
            int index = -1;
            for (int i = 0; i < jumlahProd; i++) {
                if (products[i].item_id == itemId) {
                    index = i;
                    break;
                }
            }

            if (index != -1) {
                for (int i = index; i < jumlahProd - 1; i++) {
                    products[i] = products[i + 1];
                }
                jumlahProd--;
                UpdateInventoryData();
                printf("Inventory record with item id %d deleted successfully.\n\n", itemId);
            } else {
                printf("Inventory record with item id %d not found.\n\n", itemId);
            }
        } else if(choose == 4){
            break;
        }
    }
}	

#endif
