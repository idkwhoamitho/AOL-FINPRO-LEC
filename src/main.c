#include <stdio.h>
#include "data_processing.h"
#include "menu.h"
#include "fileIO.h"

void allmenu(){
	readInventoryFile();
	readItemFile();
	readSupplierFile();
    int choice, choose;
    while(1){
    printf("INVENTORY SYSTEM\n");
    printf("INVENTORY DATA MAIN MENU\n\n");
    printf("What do you want to do?\n");
    printf("1. Insert Record\n");
    printf("2. Show Record\n");
    printf("3. Select Data\n");
    printf("4. Delete Record\n");
    printf("5. Update Record\n");
    printf("6. Exit\n\n");
    printf("Your Choice: ");
    scanf("%d", &choice);

    if(choice == 1){
        printf("INVENTORY SYSTEM\n");
        printf("INSERT RECORD MAIN MENU\n\n");
        printf("1. Iventory\n");
        printf("2. Supplier\n");
        printf("3. Item\n");
        printf("4. Back to Main Menu\n\n");
        printf("Your Choice: ");
        scanf("%d", &choose);

        if(choose == 1){
        	struct Inventory inventoryData;
            printf("1. Insert the item id: ");
            scanf("%d",&inventoryData.item_id);
            printf("2. Insert the supplier id: ");
            scanf("%d",&inventoryData.supplier_id);
            printf("3. Insert the quantity: ");
            scanf("%d",&inventoryData.quantity);
        	products[jumlahProd] = inventoryData;
    	    jumlahProd++;
        	UpdateInventoryData();
            printf("\nSuccess\n\n");
            
        } else if(choose == 2){
       		struct Supplier supplierData;
            printf("1. Insert the supplier id: ");
            scanf("%d",&supplierData.id);
            printf("2. Insert the supplier name: ");
            scanf("%s",&supplierData.name);
            printf("3. Insert the supplier phone number: ");
            scanf("%s",&supplierData.phone_number);
        	supplier[jumlahSupplier] = supplierData;
        	jumlahSupplier++;
        	UpdateSupplierData();
            printf("\nSuccess\n\n");
            
        } else if(choose == 3){
            struct Item itemData;
            printf("1. Insert the item id: ");
            scanf("%d",&itemData.id);
            printf("2. Insert the item name: ");
            scanf("%s",&itemData.item_name);
            printf("3. Insert the price (.00): ");
            scanf("%f",&itemData.price);
        	item[jumlahItem] = itemData;
        	jumlahItem++; 
        	UpdateItemData();
            printf("\nSuccess\n\n");
            
        } else if(choose == 4){
            continue;
        }
    
    } else if(choice == 2){
        printf("INVENTORY SYSTEM\n");
        printf("SHOW RECORD MAIN MENU\n\n");
        
        
//        printRecordAll();
        showRecordMenu();
        
        
    } else if(choice == 3){
	SelectData();
    } else if(choice == 4){
		DeleteDataMenu();	   
    } else if(choice == 5){    
		ModifyExistingDataMenu(); 
    } else if(choice == 6){
        break;
    }
    }
}

int main(int argc, char const *argv[])
{
    system("cls || clear");
    allmenu();

    return 0;
}
