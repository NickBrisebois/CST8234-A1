// C headers 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
// Our headers
#include"node.h"
#include"main.h"
#include"rental.h"
#include"sort.h"

int main(){
	srand(time(NULL));

	Property* pAllHead = generateProperties(10);
	Property* pFavHead = NULL;
	Property* pCurList = pAllHead;

	getChoice(pAllHead, pFavHead, pCurList);

	return 0;
}

void getChoice(Property* pAllHead, Property* pFavHead, Property* pCurList){
	char menuChoice[256] = "";

	// Keep looping back to the menu until the user requests to exit by entering q
	while(strcmp(menuChoice, "q") != 0){
		printf("Command ('h' for help): ");
		scanf("%255s", menuChoice);

		if(strcmp(menuChoice, "h") == 0){
			printHelp();
		}else if(strcmp(menuChoice, "a") == 0){
			printProperties(pCurList);
		}else if(strcmp(menuChoice, "f") == 0){
			printf("%s\n", "Switched to favourites list");
			pCurList = pFavHead;
		}else if(strcmp(menuChoice, "d") == 0){
			printf("%s\n", "Switched to default list");
			if(randInt(0, 1) == 1)
				addProperty(pAllHead);
			pCurList = pAllHead;
		}
	}
}

void printHelp(){
	printf("Valid commands are:\n");
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

void printProperties(Property* pRentalsHead){
	if(pRentalsHead != NULL){
		printTabs();
		for(Property* pPropNode = pRentalsHead; pPropNode != NULL; pPropNode = pPropNode->pNextProp){
			printf(" %2d %-24s \t\t %7d \t %9d \t %9f\n", pPropNode->addrNum, pPropNode->addrName, pPropNode->numRooms, pPropNode->rentCost, pPropNode->distance);
		}
	}else
		printf("%s\n", "There are no properties in this list");
}

void printTabs() {
	printf("%-27s \t\t %7s \t %7s \t %9s\n", "Address", "# Rooms", "Rent/Room", "Distance");
	printf("%s \t\t %s \t %s \t %s \n", "--------------------------", "-------", "---------", "---------");
}

int randInt(int min, int max){
	return (rand() % (max + 1 - min) + min);
}

