#pragma once

#include "ofMain.h"

class mainMenu
{
public:
	//Load the media
	void fontLoader();
	void imageLoader();

	//Draw the Menu screen where you press a key to start the game
	void drawGameStartString();
	void displayGameStart();
	
	//Draw the you win screen
	void drawYouWinString();
	void displayYouWin();
	void hoverWin();

	//Draw the game over screen
	void drawGameOverString();
	void displayGameOver();

	//Draw the screen where you choose the game modes
	void displayChooseScreen();

	//Display the control Screen
	void displayControls();
	
	//Draw the black borders when in menus
	void drawEdges();

	//The text changes color when you hover over them
	void hover();

	int hoverRestartColorRed, hoverRestartColorGreen, hoverRestartColorBlue;
	int hoverExitColorRed, hoverExitColorGreen, hoverExitColorBlue;

	ofTrueTypeFont bigText, bigTextForGameOverScreen, bigTextForYouWinScreem, mediumTextForYouWin,control, quit, restart;
	ofImage chooseScreen;

	bool hoverRestartState, hoverExitState;

	mainMenu(void);
	~mainMenu(void);
};

