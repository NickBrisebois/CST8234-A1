/* PROGRAM: Assignment 1 : Tinder for Rental Properties
   AUTHOR: Nick Brisebois & Harshdeep Singh 
   DATE:  March 18, 2018 
   PURPOSE: To allow a user to sort through a list of properties and either add them to their favourites list or delete them
   LEVEL OF DIFFICULTY: 4
   CHALLENGES: Sorting out the headers mainly. Still not sure how to make them work when included in any order as they should
   HOURS SPENT: 15 
*/

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
	Node* pCurNode = *ppCurList;
	void (*sortMethod)(Node** ppProps);
	char menuChoice[256] = "";
	int skipCount = 0;
	
	printProperties(*ppCurList);
	askOpinion(*ppCurList);

	// Keep looping back to the menu until the user requests to exit by entering q
	while(strcmp(menuChoice, "q") != 0){

		pCurNode = getNodeAtIndex(*ppCurList, skipCount);
		printf("\nCommand ('h' for help): ");
		scanf("%255s", menuChoice);
		
		// h: Print help menu
		if(strcmp(menuChoice, "h") == 0){
			printHelp();
		}

		// a: Sort list and then print them in tabular form. Then ask for opinion on first property
		else if(strcmp(menuChoice, "a") == 0){
			// Sort using the current sorting function
			(*sortMethod)(ppCurList);
			printProperties(*ppCurList);
			askOpinion(pCurNode);
		}

		// f: Switch current list to favourites. Then ask for opinion on first property
		else if(strcmp(menuChoice, "f") == 0){
			skipCount = 0;
			ppCurList = &pFavHead;
			pCurNode = getNodeAtIndex(*ppCurList, skipCount);
			printf("%s\n", "Switched to favourites list");
			printProperties(*ppCurList);
			askOpinion(pCurNode);
		}

		// d: Switch to default list, 50/50 chance of adding new property then print all properties
		else if(strcmp(menuChoice, "d") == 0){
			skipCount = 0;
			ppCurList = &pAllHead;
			pCurNode = getNodeAtIndex(*ppCurList, skipCount);
			printf("%s\n", "Switched to default list");
			// 50/50 chance to add a new property to the default list
			if(randInt(0, 1) == 1)
				pushNode(&pAllHead, defineProperty());
		}

		// s<n> Sort the current list in different ways
		else if(menuChoice[0] == 's'){
			skipCount = 0;
			switch(menuChoice[1]) {
				case 'r':
					sortMethod = &sortByRent;
					break;
				case 'd':
					sortMethod = &sortByDistance;
					break;
				case 'n':
					sortMethod = &sortByRooms;
					break;
				case 'a':
					sortMethod = &sortByAddress;
					break;
				default:
					printf("Unknown sorting method");
			}
			(*sortMethod)(ppCurList);
			pCurNode = getNodeAtIndex(*ppCurList, skipCount);
			printProperties(*ppCurList);
			askOpinion(pCurNode);
		}

		// l: Remove the just viewed property from the current list then display the next property
		else if(strcmp(menuChoice, "l") == 0){
			if(getCount(*ppCurList) > 0) {
				removeNode(ppCurList, skipCount);
				pCurNode = getNodeAtIndex(*ppCurList, skipCount);
				printf("\nRental property deleted\n");
				askOpinion(pCurNode);
			}else
				printf("\nNo more rental properties\n");
		}

		// r: Swipe right, remove current item from default list and add it to favourites list
		else if(strcmp(menuChoice, "r") == 0){
			// If current list is not the favourites list
			if(*ppCurList != pFavHead) {
				if(getCount(*ppCurList) > 0) {
					pushNode(&pFavHead, removeNode(ppCurList, skipCount));
					pCurNode = getNodeAtIndex(*ppCurList, skipCount);
					printf("Item added to favourites list");
				}else
					printf("\nNo more rental properties\n");
			}else
				printf("Item already in favourites");
		}

		// n: Skip to next property
		else if(strcmp(menuChoice, "n") == 0){
			if(pCurNode->pNext!= NULL)
				pCurNode = getNodeAtIndex(*ppCurList, ++skipCount);
			else
				printf("\nNo more rental properties\n");
			askOpinion(pCurNode);
		}
	
		// q: Quit by breaking out of main loop
		else if(strcmp(menuChoice, "q") == 0)
			break;

		// Command not found
		else{
			printf("Command is not recognized");
			printHelp();
		}
	}

	return 0;
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

int randInt(int min, int max){
	return (rand() % (max + 1 - min) + min);
}

