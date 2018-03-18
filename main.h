#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED


/**
 * Generates a random integer between min and max
 */
int randInt(int min, int max);

/**
 * Handles the main menu, gets user input and calls respective functions
 */
void getChoice(Node* pAllHead, Node* pFavHead, Node** ppCurList);

/**
 * Simply prints the help menu 
 */
void printHelp();

/**
 * Prints all properties in the given linked list
 */
void printProperties(Node* pRentalsHead);

/**
 * Prints the top tabs for printProperties
 */
void printTabs();

/**
 * Get users's opinion the the property at the head of the given list
 */
void askOpinion(struct _Node* pNode);

/**
 * Generate a random int between two given numbers
 */
int randInt(int min, int max);

#endif
