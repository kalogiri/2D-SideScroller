#include "timer.h"

//This class handles the timer object in the game.

timer::timer(void){
	dimX = 0;
	dimY = 10;
	colG = 255;
	colB = 255;
	colRDraw = 0;
	colBDraw = 0;
	colGDraw = 0;
	dead = false;
	collided = false;
	resetBar = false;
	pos.set(600,ofRandom(55,330));
	vel.set(ofRandom(-1,-3),0);
}

void timer::reset() {
	dimX = 0;
	colG = 255;
	colB = 255;
	dead = false;
}

void timer::timerBarDisplay() {
	ofSetColor(255);
	ofFill();
	ofRect(195,360,200,30);//background white
	ofSetColor(0);
	ofFill();
	ofRect(200,365,190,20);//The black bounding box
}

void timer::timerBarColorUpdate() {
	
	ofSetColor(255,colG,colB);
	ofFill();
	ofRect(205,370,dimX,dimY);
	colB-=0.25;
	colG-=0.25;

	if(resetBar == false) {
		dimX += 0.2;
	}

	if(resetBar == true) {
		dimX = 0;
		colG = 255;
		colB = 255;
	}

	if(colB < 20){ colB = 20; }
	if(colG < 20) { colG = 20; }
	if(dimX >= 180) {
		dead = true;
	} 
	cout<<resetBar<<endl;
}

bool timer::getDead() { return dead;}
void timer::collisionDetect(ofPoint playerPos, int playerWidth, int playerHeight) {
	if((pos.x >= playerPos.x && pos.x <= playerPos.x + playerWidth) &&
	   (pos.y >= playerPos.y && pos.y <= playerPos.y + playerHeight)) {
		collided = true;
		resetBar = true;
	} else {
		collided = false;
		resetBar = false;
	}
}

bool timer::returnCollided() { return collided;}
bool timer::returnResetBar() { return resetBar;}

void timer::updateTimerObject() {
	pos+=vel;
}

void timer::drawTimerObject(){
	//cout<<dead<<endl;
	ofSetColor(0,255,0);
	ofFill();
	ofRect(pos.x, pos.y, 10,10);
}

timer::~timer(void){
}
