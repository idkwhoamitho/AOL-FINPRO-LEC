#ifndef MENU_H
#define MENU_H
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "fileIO.h"
#include <windows.h>
void printProductsCatalogue(){
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Product Name", "Stock", "Price");
    printf("------------------------------------------------------------\n");
    // int size = 6;
    // data = fopen("Product_Catalogue.csv","r");
    readFile();
    int i = 0;
    for(int i = 0; i < jumlahProd;i++)
    {
        /* code */
    	Sleep(50);
        printf("%-5d %-20s %-10d %-10.2d\n", products[i].ID, products[i].productName, products[i].stock, products[i].price);
        // i++;
    }
    // fclose(data);
        
}
void printSortedProducts(){
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Product Name", "Stock", "Price");
    printf("------------------------------------------------------------\n");
    
    for (int i = 0; i < jumlahProd; i++)
    {
        /* code */
    	Sleep(50);
        printf("%-5d %-20s %-10d %-10.2d\n", products[i].ID, products[i].productName, products[i].stock, products[i].price);
    }
}


void displayLogo() {
    const char* rainbow[] = {
        "\033[31m", // Merah
        "\033[33m", // Kuning
        "\033[32m", // Hijau
        "\033[36m", // Cyan
        "\033[34m", // Biru
        "\033[35m",  // Ungu
        "\033[31m"
    };
    
    const char* reset = "\033[0m";

    printf("\n	*****************************************\n");
	Sleep(150);
    printf("	*                ");
	Sleep(150);
    for (int i = 0; i < 7; i++) {
        printf("%s%c", rainbow[i], "SHOPINT"[i]);
        Sleep(125);
    }
    printf("%s     	        *\n", reset);
	Sleep(150);
    printf("	*****************************************\n");
    
    			


    printf("     %s _____ _    _  ____  _____ _____ _   _ _______ _%s\n", rainbow[2], reset);
	Sleep(50);
    printf("    %s / ____| |  | |/ __ \\|  __ \\_   _| \\ | |__   __| |  %s\n", rainbow[4], reset);
	Sleep(50);
    printf("    %s| (___ | |__| | |  | | |__) || | |  \\| |  | |  | |%s\n", rainbow[3], reset);
	Sleep(50);
    printf("    %s \\___ \\|  __  | |  | |  ___/ | | | . ` |  | |  | |%s\n", rainbow[5], reset);
	Sleep(50);
    printf("   %s  ____) | |  | | |__| | |    _| |_| |\\  |  | |  |_|%s\n", rainbow[0], reset);
	Sleep(50);
    printf("    %s|_____/|_|  |_|\\____/|_|   |_____|_| \\_|  |_|  (_)%s\n", rainbow[1], reset);
    printf("\n");

    printf("\033[34m	    Your One-Stop Shop for Everything!     \033[0m\n");
	Sleep(150);
    printf("\033[32m 			Made By:\n");
	printf("			  Adi\n");
    printf("			 Ronald\n");
    printf("			 Carlos\033[0m\n");
    printf("\033[33m----------------------------------------------------------\033[0m\n");
	Sleep(150);
    printf("\033[37m	Press Enter to start your shopping journey...\033[0m");
}

void displayLogoend() {
    const char* rainbow[] = {
        "\033[31m", // Merah
        "\033[33m", // Kuning
        "\033[32m", // Hijau
        "\033[36m", // Cyan
        "\033[34m", // Biru
        "\033[35m",  // Ungu
        "\033[31m"
    };
    
    const char* reset = "\033[0m";

    printf("\n	*****************************************\n");
	Sleep(150);
    printf("	*                ");
	Sleep(150);
    for (int i = 0; i < 7; i++) {
        printf("%s%c", rainbow[i], "SHOPINT"[i]);
        Sleep(125);
    }
    printf("%s     	        *\n", reset);
	Sleep(150);
    printf("	*****************************************\n");
    
    			


    printf("     %s _____ _    _  ____  _____ _____ _   _ _______ _%s\n", rainbow[2], reset);
	Sleep(50);
    printf("    %s / ____| |  | |/ __ \\|  __ \\_   _| \\ | |__   __| |  %s\n", rainbow[4], reset);
	Sleep(50);
    printf("    %s| (___ | |__| | |  | | |__) || | |  \\| |  | |  | |%s\n", rainbow[3], reset);
	Sleep(50);
    printf("    %s \\___ \\|  __  | |  | |  ___/ | | | . ` |  | |  | |%s\n", rainbow[5], reset);
	Sleep(50);
    printf("   %s  ____) | |  | | |__| | |    _| |_| |\\  |  | |  |_|%s\n", rainbow[0], reset);
	Sleep(50);
    printf("    %s|_____/|_|  |_|\\____/|_|   |_____|_| \\_|  |_|  (_)%s\n", rainbow[1], reset);
    printf("\n");

    printf("\033[34m	    Your One-Stop Shop for Everything!     \033[0m\n");
	Sleep(150);
    printf("\033[32m 			Made By:\n");
	printf("			  Adi\n");
    printf("			 Ronald\n");
    printf("			 Carlos\033[0m\n");
    printf("\033[33m----------------------------------------------------------\033[0m\n");
	Sleep(150);
    printf("\033[37m	    Thank you for using our software!\033[0m\n\n\n\n\n");
}

void displaymenu(){
	
}
void transactionMenu(){
    char choose;
    int id,index, sold;
    long int pay,total;
    total = 0;
    printProductsCatalogue();
    while (1)
    {
        /* code */
        printf("\n input the id of a product: ");
        scanf("%d",&id);
        getProductById(id, jumlahProd, &index);
        if (index == -1) {
            printf("Invalid product ID. Please try again.\n");
            continue;
        }
        printf("\nHow much? ");
        scanf("%d",&sold);
        if (products[index].stock <= 0 ){
                /* code */
                printf("Product's sold out!");
                continue;
            }
        if (sold > products[index].stock){
        	printf("Not enough stock available! Only %d left.\n", products[index].stock);
            continue;
        }
        products[index].stock -= sold;
        total += products[index].price * sold;          
        getchar();
        printf("Did you want to continue the transaction ?(Y/N): ");
        scanf(" %c",&choose);
        if(choose == 'N' || 'n') {
            printf("\ntotal Price: %ld",total);
            printf("\nplease input your money: ");
            scanf("%ld",&pay);
            if(pay < total){
                printf("\nYou don't have enough money to pay!");
                products[index].stock += sold;
                getchar();
                break;
            }
            else{
                if(pay > total) printf("\nYour return: %d\n",pay - total);
                updateData();
                getchar();
                break;
            }
        };

    }
}

void AddExistingDataMenu(){
    char choose;
    int id,index, add;
    printProductsCatalogue();
    while (1)
    {
        /* code */
        printf("\n input the id of a product: ");
        scanf("%d",&id);
        getProductById(id, jumlahProd, &index);
        if (index == -1) {
            printf("Invalid product ID. Please try again.\n");
            continue;
        }
        printf("\n How much item : ");
        if(scanf("%d",&add) != 1){
            printf("Invalid input. Please enter a valid integer for the quantity.\n");
            while (getchar() != '\n'); 
            continue;
        }
        getchar();
		products[index].stock += add;
        printf("Did you want to continue adding existing products ?(Y/N): ");
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
    printProductsCatalogue();
    while (1)
    {
        /* code */
        printf("\n input the id of a product: ");
        scanf("%d",&id);
        getProductById(id, jumlahProd, &index);
        if (index == -1) {
            printf("Invalid product ID. Please try again.\n");
            continue;
        }
    	printf("\nAre you sure you want to delete the data ?(Y/N) ");
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
    		deleteData(temp, jumlahProd - 1);
       		jumlahProd--;
        	printf("Did you want to continue to delete products ?(Y/N): ");
        	scanf(" %c",&choose2); getchar();
        	if(choose2 == 'N' || choose2 =='n') {
            	break;
        	}
		}
    }
}

void addDataMenu(){
    struct Product Data;
    char choose;
    while (1)
    {
        /* code */
        getchar();
        int isValid;
        do
        {            
            printf("\nProduct Name: "); 
            fgets(Data.productName, sizeof(Data.productName), stdin);
                size_t len = strlen(Data.productName);
                if (len > 0 && Data.productName[len - 1] == '\n') {
                    Data.productName[len - 1] = '\0';
                }

            for(int i = 0;i< strlen(Data.productName);i++){
                if(!isalpha(Data.productName[i])) isValid = 0;
                else 
                    isValid = 1;
            }
            if (isValid == 0)
            {
                /* code */
                int choose;
                printf("Did the product name contain number? (Y/N)");
                scanf(" %c",&choose);
                if(choose == 'N' || choose =='n') {
                    getchar();                
            	    continue;

        	    }
        	    else if(choose == 'Y' || choose =='y') {
            	    isValid = 1;
        	    }
            }
            
        } while (!isValid);
       
        do{
             printf("Price: ");
            scanf("%ld",&Data.price);
        }while(Data.price <= 0);       
        do
        {
            printf("Stocks: ");
            scanf("%d",&Data.stock);
            /* code */
        } while (Data.stock < 0);
        
        Data.ID = products[jumlahProd-1].ID + 1;
        jumlahProd++;
        appendData(Data);
        

        getchar();
        printf("Did you want to add another product? (Y/N): ");
        scanf(" %c",&choose);
        if (choose == 'N' || 'n')
        {
            /* code */
            break;
        }
        
    }
    
}

#endif
