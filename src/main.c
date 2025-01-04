#include <stdio.h>
#include "data_processing.h"
#include "menu.h"
#include "fileIO.h"
//DATA OPERATION ZONE

//FILE IO ZONE


//MENU ZONE



void allmenu(){
    printProductsCatalogue();
    int choose = -1;
    while(1){
    	Sleep(50);
        printf("\n		Main Menu\n");
        printf("\033[33m------------------------------------------\033[0m\n");
    	Sleep(50);
        printf("\n1. Sort By ID");
    	Sleep(50);
        printf("\n2. Sort By Price");
    	Sleep(50);
        printf("\n3. Sort By Stocks");
    	Sleep(50);
        printf("\n4. Buy");
    	Sleep(50);
        printf("\n5. Add product");
    	Sleep(50);
    	printf("\n6. Add existing Products");
    	Sleep(50);
    	printf("\n7. Delete product");
    	Sleep(50);
        printf("\n0. Exit");
    	Sleep(50);
        printf("\nYour choice: ");
        scanf("%d",&choose);

        if(choose == 0){
        	system("cls || clear"); break;
		} else if(choose == 2){
			sortProductByPrice(jumlahProd); system("cls || clear"); printSortedProducts();
		} else if(choose == 1){
			sortProductById(jumlahProd); system("cls || clear"); printSortedProducts();
		} else if(choose == 3){
			sortProductByStock(jumlahProd); system("cls || clear"); printSortedProducts();	
		} else if(choose == 4){
			system("cls || clear"); transactionMenu();
		} else if(choose == 5){
			system("cls || clear"); addDataMenu(); system("cls || clear");readFile(); printSortedProducts();
		} else if(choose == 6){
			system("cls || clear"); AddExistingDataMenu(); system("cls || clear");readFile(); printSortedProducts();
		} else if(choose == 7){
			system("cls || clear"); DeleteDataMenu(); system("cls || clear");readFile(); printSortedProducts();
		}

    
    }
    displayLogoend();
}




int main(int argc, char const *argv[])
{
    /* code */
    system("cls || clear");
    displayLogo();

    getchar();
    system("cls || clear");
    allmenu();

    return 0;
}
