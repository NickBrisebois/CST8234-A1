#include<stdio.h>
#include<stdlib.h>
#include"node.h"
#include"main.h"
#include"rental.h"

Property* defineProperty(){
	Property* tempProp = createPropertyNode();
	char* streetNames[10] = {"Magnolia Drive", "Garden Street", "Wood Street", "William Street", "Valley View Drive",
							"2nd Street East", "Street Road", "Fawn Lane", "Bayberry Drive", "Ridge Road"};
	tempProp->addrName = streetNames[randInt(0, 9)];
	tempProp->addrNum = randInt(0, 200);
	tempProp->numRooms = randInt(1, 4);
	tempProp->rentCost = (50 * randInt(4,12));
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

