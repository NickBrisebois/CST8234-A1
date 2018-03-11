// C headers 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
// Our headers
#include"main.h"
#include"node.h"
#include"rental.h"
#include"sort.h"

int main(){
	srand(time(NULL));
	
	Property* pAllHead = NULL;
	pushNode(&pAllHead, createPropertyNode());
	pushNode(&pAllHead, createPropertyNode());
	pushNode(&pAllHead, createPropertyNode());

	for(Property* pPropNode = pAllHead; pPropNode != NULL; pPropNode = pPropNode->pNextProp){
		printf("%s", pPropNode->addrName);
	}

	getChoice();

	return 0;
}

void getChoice(){
	char menuChoice[256] = "";

	// Keep looping back to the menu until the user requests to exit by entering q
	while(strcmp(menuChoice, "q") != 0){
		printf("Command ('h' for help): ");
		scanf("%255s", menuChoice);

		if(strcmp(menuChoice, "h") == 0){
			printHelp();
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
