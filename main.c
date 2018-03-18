// C headers 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
// Our headers
#include"node.h"
#include"rental.h"
#include"sort.h"
#include"main.h"

int main(){
	srand(time(NULL));

	Node* pAllHead = generateProperties(10);
	Node* pFavHead = NULL;
	Node** ppCurList = &pAllHead;
	
	printProperties(*ppCurList);
	askOpinion(*ppCurList);
	getChoice(pAllHead, pFavHead, ppCurList);

	return 0;
}

void getChoice(Node* pAllHead, Node* pFavHead, Node** ppCurList){
	char menuChoice[256] = "";

	// Keep looping back to the menu until the user requests to exit by entering q
	while(strcmp(menuChoice, "q") != 0){

		printf("\nCommand ('h' for help): ");
		scanf("%255s", menuChoice);
		
		// h: Print help menu
		if(strcmp(menuChoice, "h") == 0){
			printHelp();
		}
		// a: Sort list and then print them in tabular form. Then ask for opinion on first property
		else if(strcmp(menuChoice, "a") == 0){
			printProperties(*ppCurList);
			askOpinion(*ppCurList);
		}
		// f: Switch current list to favourites. Then ask for opinion on first property
		else if(strcmp(menuChoice, "f") == 0){
			printf("%s\n", "Switched to favourites list");
			ppCurList = &pFavHead;
			printProperties(*ppCurList);
			askOpinion(*ppCurList);
		}
		// d: Switch to default list, 50/50 chance of adding new property then print all properties
		else if(strcmp(menuChoice, "d") == 0){
			printf("%s\n", "Switched to default list");
			ppCurList = &pAllHead;
			// 50/50 chance to add a new property to the default list
			if(randInt(0, 1) == 1)
				pushNode(&pAllHead, defineProperty());
		}
		// Sort methods
		else if(menuChoice[0] == 's'){
			sortByDistance(&pAllHead);
		}
		// l: Remove the just viewed property from the current list then display the next property
		else if(strcmp(menuChoice, "l") == 0){
			if(getCount(*ppCurList) > 0) {
				removeNode(ppCurList, 0);
				printf("\nRental property deleted\n");
				askOpinion(*ppCurList);
			}else
				printf("\nNo more rental properties\n");
		}

		// r: Swipe right, remove current item from default list and add it to favourites list
		else if(strcmp(menuChoice, "r") == 0){
			if(getCount(*ppCurList) > 0) {
				pushNode(&pFavHead, removeNode(ppCurList, 0));
			}else
				printf("\nNo more rental properties\n");
		}
	}
}

void printHelp(){
	printf("\nValid commands are:\n");
	printf("\t h - display this help\n");
	printf("\t a - display all the rental properties on the current list \n");
	printf("\t f - switch to the favourites list\n");
	printf("\t d - switch to the default list\n");
	printf("\t l - 'swipe left' on the current rental property\n");
	printf("\t r - 'swipe right' on the current rental property\n");
	printf("\t n - skip to the next rental property\n");
	printf("\t sa - set the sorting to 'by address'\n");
	printf("\t sn - set the sorting to 'by number of rooms'\n");
	printf("\t sr - set the sorting to 'by rent'\n");
	printf("\t sd - set the sorting to 'by distance'\n");
	printf("\t q - quit the program\n");
}

void printProperties(Node* pRentalsHead){
	float km = 0;
	if(pRentalsHead != NULL){
		printTabs();
		for(Node* pPropNode = pRentalsHead; pPropNode != NULL; pPropNode = pPropNode->pNext){
			km = pPropNode->pRental->distance / 1000.00;
			printf("%2d %-24s \t\t %7d \t %9d \t %6.2f km \n", pPropNode->pRental->addrNum, pPropNode->pRental->addrName, pPropNode->pRental->numRooms, pPropNode->pRental->rentCost, km);
		}
	}else
		printf("\n%s\n", "There are no properties in this list");
}

void printTabs() {
	printf("\n");
	printf("%-27s \t\t %7s \t %7s \t %6s\n", "Address", "# Rooms", "Rent/Room", "Distance");
	printf("%s \t\t %s \t %s \t %s \n", "--------------------------", "-------", "---------", "---------");
}

int randInt(int min, int max){
	return (rand() % (max + 1 - min) + min);
}

void askOpinion(Node* pNode){
	if(pNode != NULL){
		float km = pNode->pRental->distance / 1000.00;
		printf("\n%s\n", "What do you think about this rental property?");
		printf("\tAddr: %d %s, # Rooms: %d, Rent/Room: $%d, Distance: %.2f km\n", pNode->pRental->addrNum, pNode->pRental->addrName, pNode->pRental->numRooms, pNode->pRental->rentCost, km);
	}else
		printf("\nNo more rental properties\n");
}
