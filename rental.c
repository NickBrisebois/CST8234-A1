#include<stdio.h>
#include<stdlib.h>
#include"node.h"
#include"rental.h"
#include"main.h"

Node* defineProperty(){
	Node* tempProp = createPropertyNode();
	Street streets[10] = {
		{randInt(100, 2000), "Magnolia Drive"},
		{randInt(100, 2000), "Garden Street"},
		{randInt(100, 2000), "Wood Street"},
		{randInt(100, 2000), "William Street"},
		{randInt(100, 2000), "Valley View Drive"},
		{randInt(100, 2000), "Fawn Lane"},
		{randInt(100, 2000), "Bayberry Drive"},
		{randInt(100, 2000), "Ridge Road"},
		{randInt(100, 2000), "Pinecrest Road"},
		{randInt(100, 2000), "Chandigarh Road"}
	};
	
	Street chosenStreet = streets[randInt(0,9)];

	tempProp->pRental->addrName = chosenStreet.streetName;
	tempProp->pRental->addrNum = randInt(1, 200);
	tempProp->pRental->numRooms = randInt(1, 4);
	tempProp->pRental->rentCost = (50 * randInt(4,12));
	tempProp->pRental->distance = (chosenStreet.baseDistance + tempProp->pRental->addrNum);
	return tempProp;
}

Node* generateProperties(int numProps){
	// The head of the linked list
	Node* pHead = defineProperty();
	for(int i = 0; i < numProps; i++){
		//pushNode defined in node.c
		pushNode(&pHead, defineProperty());
	}
	return pHead;
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

void askOpinion(Node* pNode){
	if(pNode != NULL){
		float km = pNode->pRental->distance / 1000.00;
		printf("\n%s\n", "What do you think about this rental property?");
		printf("\tAddr: %d %s, # Rooms: %d, Rent/Room: $%d, Distance: %.2f km\n", pNode->pRental->addrNum, pNode->pRental->addrName, pNode->pRental->numRooms, pNode->pRental->rentCost, km);
	}else
		printf("\nNo more rental properties\n");
}
