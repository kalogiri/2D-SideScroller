#include "mainMenu.h"

//This class is the main menu of the game

mainMenu::mainMenu(void){
	hoverRestartState = false;
	hoverExitState = false;
	hoverRestartColorRed = 92;
	hoverRestartColorGreen = 1;
	hoverRestartColorBlue = 106; 
	hoverExitColorRed = 92;
	hoverExitColorGreen = 1;
	hoverExitColorBlue = 106; 
}

void mainMenu::fontLoader() {
	bigText.loadFont("BebasNeue.otf", 62);
	bigTextForGameOverScreen.loadFont("BebasNeue.otf", 75);
	bigTextForYouWinScreem.loadFont("BebasNeue.otf", 53);
	mediumTextForYouWin.loadFont("BebasNeue.otf", 33);
	control.loadFont("BebasNeue.otf", 15);
	restart.loadFont("BebasNeue.otf", 15);
	quit.loadFont("BebasNeue.otf", 15);
}

void mainMenu::imageLoader() {
	chooseScreen.loadImage("chooseScreenNoGlow2.png");
}

//Choose Screen
void mainMenu::displayChooseScreen() {
	chooseScreen.draw(0,0);
}

//Start Screen
void mainMenu::drawGameStartString() {
	ofSetColor(92,1,106);
	ofFill();
	bigText.drawString("Press",120,190);
	bigText.drawString("Space",285,190);
	bigText.drawString("To",120,270);
	bigText.drawString("Start",195,270);
}

void mainMenu::displayGameStart() {
	ofSetColor(0);
	ofFill();
	ofRect(100,90,400,220);
	drawEdges();
}

//Game Over Screen
void mainMenu::drawGameOverString() {
	
	ofSetColor(92,1,106);
	ofFill();
	bigTextForGameOverScreen.drawString("Game",132,210);
	bigTextForGameOverScreen.drawString("Over",312,210);
	ofSetColor(hoverRestartColorRed,hoverRestartColorGreen,hoverRestartColorBlue);
	restart.drawString("Restart",251,251);
	ofSetColor(hoverExitColorRed,hoverExitColorGreen,hoverExitColorBlue);
	quit.drawString("Exit",310,251);
}

void mainMenu::displayGameOver() {
	ofBackground(92,1,106);
	ofSetColor(0);
	ofFill();
	ofRect(100,90,400,220);
	drawEdges();
	hover();
}

//You win Screen
void mainMenu::drawYouWinString() {
	ofSetColor(30,255,0);
	ofFill();
	bigTextForYouWinScreem.drawString("Congratulation",115,155);
	mediumTextForYouWin.drawString("You have completed",115,193);
	mediumTextForYouWin.drawString("The Objective",115,235);
	ofSetColor(hoverRestartColorRed,hoverRestartColorGreen,hoverRestartColorBlue);
	restart.drawString("Restart",251,271);
	ofSetColor(hoverExitColorRed,hoverExitColorGreen,hoverExitColorBlue);
	quit.drawString("Exit",310,271);
}

void mainMenu::displayYouWin() {
	cout<<"MouseX: "<<ofGetMouseX()<<endl<<"MouseY: "<<ofGetMouseY(); 
	ofBackground(30,255,0);
	ofSetColor(0);
	ofFill();
	ofRect(100,90,400,220);
	drawEdges();
	hoverWin();
}

//Hover functions for buttons displayed in you win screen
void mainMenu::hoverWin() {
	//Exit
	if(ofGetMouseX() >= 310 && ofGetMouseX() < 335 && 
	   ofGetMouseY() >= 256 && ofGetMouseY() < 270) {
		hoverExitState = true;
	} else { hoverExitState = false; }

	if(hoverExitState == true) {
		hoverExitColorRed = 19;
		hoverExitColorGreen = 163;
		hoverExitColorBlue = 0; 
	} else {
		hoverExitColorRed = 30;
		hoverExitColorGreen = 255;
		hoverExitColorBlue = 0; 
	}
	//Restart
	if(ofGetMouseX() >= 251 && ofGetMouseX() < 302 && 
	   ofGetMouseY() >= 256 && ofGetMouseY() < 270) {
		hoverRestartState = true;
	} else { hoverRestartState = false; }

	if(hoverRestartState == true) {
		hoverRestartColorRed = 19;
		hoverRestartColorGreen = 163;
		hoverRestartColorBlue = 0; 
	} else {
		hoverRestartColorRed = 30;
		hoverRestartColorGreen = 255;
		hoverRestartColorBlue = 0; 
	}
}

//Hover function for rest of the screens
void mainMenu::hover() {
	//Exit
	if(ofGetMouseX() >= 310 && ofGetMouseX() < 335 && 
	   ofGetMouseY() >= 236 && ofGetMouseY() < 250) {
		hoverExitState = true;
	} else { hoverExitState = false; }

	if(hoverExitState == true) {
		hoverExitColorRed = 147;
		hoverExitColorGreen = 1;
		hoverExitColorBlue = 169; 
	} else {
		hoverExitColorRed = 92;
		hoverExitColorGreen = 1;
		hoverExitColorBlue = 106; 
	}
	//Restart
	if(ofGetMouseX() >= 251 && ofGetMouseX() < 302 && 
	   ofGetMouseY() >= 236 && ofGetMouseY() < 250) {
		hoverRestartState = true;
	} else { hoverRestartState = false; }

	if(hoverRestartState == true) {
		hoverRestartColorRed = 147;
		hoverRestartColorGreen = 1;
		hoverRestartColorBlue = 169; 
	} else {
		hoverRestartColorRed = 92;
		hoverRestartColorGreen = 1;
		hoverRestartColorBlue = 106; 
	}
}

//Draws the edges of the screen when displaying the screens
void mainMenu::drawEdges() {
	ofSetColor(0);
	ofFill();
	ofRect(0,0,600,40);
	ofRect(0,360,600,40);
}
mainMenu::~mainMenu(void){
}
