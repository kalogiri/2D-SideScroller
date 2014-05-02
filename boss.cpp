#include "boss.h"

boss::boss(void){
	//Boss
	enemy_position.set(601,50);
	enemy_velocity.set(-1,0);
	collided_with_bullet = false;
	enemyWidth = 200;
	enemyHeight = 300;
	deathCount = 0;
	dead = false;
	bossSpawn = false;
	time = 0;

	//Beam/Bullet
	bossBullet.set(750, 190);
	beamHeight = 10;
	beamWidth = 200;
	counter = 0;
	shootCounter = 0;
	counterStart = false;
	beamShot = false;
	fade = 255;
	collided = false;
}

//Starts the timer from the beginning of the game.
void boss::readTime() { time++; }

//Gets the current count of the timer variable, this is what controls the spawn times of everything in testApp.cpp file
int boss::getTime(){ return time; }

//Loads the image of the boss
void boss::imageLoader() {
	bossImage.loadImage("playerUse.png");
}

//Makes the boss move when the boss stage is true
void boss::update() {
	if(bossSpawn == true) {
		enemy_position += enemy_velocity;
	}
}

//Checks if the boss is dead or not
void boss::healthSystem() {
	if(deathCount >= 4) {
		dead = true;
	}
}

bool boss::getDead() { return dead; }

//Runs the boss bullet/beam code
void boss::beamRun() {
	ofPushMatrix();
	ofTranslate(bossBullet.x, bossBullet.y);
	ofSetColor(255,fade);
	ofFill();
	ofRect(0, 0, 20,2);
	ofPopMatrix();

	if(beamShot == true) {
		bossBullet.x -= 5;
	}

	if(counterStart == true) {
		counter++;
	}

	//The bullet fades the farther it travels
	if(counter >= 200) {
		fade -= 2;
	}

	if(fade <= 0) {
		bossBullet.set(750, ofRandom(100,300));
		counterStart = false;
		beamShot = false;
		counter = 0;
		fade = 255;
		shootCounter = 0;
	}

	if(enemy_position.x <= 550) {
		shootCounter++;
	}

	if(shootCounter == 100){
		beamShot = true;
		counterStart = true;
	}
}

//Collision detection of the beam/bullet with the player
void boss::collisionDetect(ofVec2f playerPos, int playerWidth, int playerHeight) {
	if((bossBullet.x >= playerPos.x && bossBullet.x  <= playerPos.x + playerWidth) &&
		(bossBullet.y >= playerPos.y && bossBullet.y<= playerPos.y + playerHeight)) {
		collided = true;
	} else {
		collided = false;
	}
}

bool boss::returnCollided() { return collided; }

//Displays all the necessary components
void boss::display() {
	if(bossSpawn == true) {
		beamRun();
		healthSystem();
		bossImage.draw(enemy_position.x,enemy_position.y,enemyWidth,enemyHeight);
	}
}



//--------------------------------------------------------------
void boss::enterBoss() {
	//The time when the boss spawns
	if(getTime() > 3200) {
		bossSpawn = true;
	}

	//Displays the boss and updates it's position when the boss spawn timer is true.
	if(bossSpawn == true) {
		display();
		update();
		if(enemy_position.x <= 500 ) {
			enemy_velocity.set(0,0);
		}
	}
}

//Reset function for boss when the game ends
void boss::reset() {
	enemy_position.set(601,50);
	enemy_velocity.set(-1,0);
	collided_with_bullet = false;
	bossBullet.set(750,ofRandom(100,300));
	counterStart = false;
	beamShot = false;
	counter = 0;
	fade = 255;
	shootCounter = 0;
	collided = false;
	deathCount = 0;
	dead = false;
	bossSpawn = false;
	time = 0;
}

boss::~boss(void){
}
