#include<stdio.h>
#include<stdlib.h>
#include"node.h"
#include"rental.h"

Property* defineProperty(){
	Property* tempProp = createPropertyNode();
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

	tempProp->addrName = chosenStreet.streetName;
	tempProp->addrNum = randInt(1, 200);
	tempProp->numRooms = randInt(1, 4);
	tempProp->rentCost = (50 * randInt(4,12));
	tempProp->distance = (chosenStreet.baseDistance + tempProp->addrNum) / 1000.00;
	return tempProp;
}

Property* generateProperties(int numProps){
	// The head of the linked list
	Property* pHead = defineProperty();
	for(int i = 0; i < numProps; i++){
		//pushNode defined in node.c
		pushNode(&pHead, defineProperty());
	}
	return pHead;
}

void addProperty(Property* pHead){
	pushNode(&pHead, defineProperty());
}

void printReadable(Property* pProperty){
	printf("\tAddr: %d %s, # Rooms: %d, Rent/Room: $%d, Distance: %.2f km\n", pProperty->addrNum, pProperty->addrName, pProperty->numRooms, pProperty->rentCost, pProperty->distance);
}
