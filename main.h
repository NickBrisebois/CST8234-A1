#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

/**
 * Handles the main menu, gets user input and calls respective functions
 */
void getChoice(Property* pAllHead, Property* pFavHead, Property* pCurList);

/**
 * Simply prints the help menu 
 */
void printHelp();

/**
 * Prints all properties in the given linked list
 */
void printProperties(Property* pRentalsHead);

/*
 * Prints the top tabs for printProperties
 */
void printTabs();

#endif
