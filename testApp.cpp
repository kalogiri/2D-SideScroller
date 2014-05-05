#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	//Spawners
	spawnCount = 0;
	spawnBulletItem = false;
	spawnOne = false;
	spawnTwo = false;
	spawnThree = false; 
	spawnTimer = false;
	spawnBackgroundParticles = false;

	//Movement
	up = false;
	down = false;
	right = false;
	left = false;
	allowMove = false;

	//Bullets
	keyShoot = false;
	allowShoot = false;

	//Game states
	chooseScreen = true;
	endlessMode = false;
	storyMode = false;
	menuScreen = false;
	gameWait = false;
	gameReset = false;
	gameStart = false;
	gameEnd = false;
	gameWin = false;
	bossStage = false;
	
	
	//Loaders for media
	b.fontLoader();
	_boss.imageLoader();
	c.fontLoader();
	c.imageLoader();
	m.fontLoader();
	m.imageLoader();
	shoot.loadSound("bulletShoot.wav");
	move.loadSound("__move.wav");
	hit.loadSound("bulletHit.wav");
	menu.loadSound("menuMusic.wav");
	timerPickup.loadSound("getTimer.wav");

	//Plays the music on a loop if the game has run from the menu screen
	if(chooseScreen == true) {
		menu.setLoop(true);
		menu.play();
	}
	ofBackground(92,1,106);
}

//--------------------------------------------------------------
void testApp::spawner() {
	//The timing of the spawns is done here
	spawnCount+=0.5;
	spawnBackgroundParticles = true;
	_boss.readTime();
	//Start of the game.
	if(_boss.getTime() > 0) {
		t.resetBar = false;
	}

	//Spawns the first core and the timer
	if(_boss.getTime() > 400) {
		spawnOne = true;
		spawnTimer = true;
	}
	
	//Spawns the second core and stops the spawn of the first core 
	if(_boss.getTime() > 800) {
		spawnTwo = true;
		spawnOne = false;
	}

	//Spawns the third core and stops the first and the second core
	if(_boss.getTime() > 1600) {
		spawnThree = true;
		spawnTwo = false;
		spawnOne = false;
	}

	//Spawns all three enemies and the bullets start spawning aswell.
	if(_boss.getTime() > 2400) {
		spawnThree = true;
		spawnTwo = true;
		spawnOne = true;
		if(storyMode == true) {
			spawnBulletItem = true;
		}
	}
	
	//Stops the spawn of everything and starts the boss stage if the story mode is true
	if(_boss.getTime() > 3200) {
		if(storyMode == true) {
			spawnOne = false;
			spawnTwo = false;
			spawnThree = false;
			spawnTimer = false;
			spawnBulletItem = false;
			bossStage = true;
		}
	}
}

//--------------------------------------------------------------
//The player's bullet.
void testApp::bulletDraw(){//Sets the bullet object onto the canvas
    for(int i = 0; i < bullets.size(); i++) {
        bullets[i].update();
        bullets[i].display();
		if(bullets[i].pos.x >= ofGetWidth()) {
			bullets[i].pos.set(0,500);
			bullets[i].vel.set(0,0);
		}//endIf
    }//endFor
}//endBulletDraw

void testApp::bulletUpdate(){
    bullets.push_back(bullet());
    bullets[bullets.size()-1].setBulletXPos(c.returnBulletXps());
    bullets[bullets.size()-1].setBulletYPos(c.returnBulletYps());
	b.totalBullets--;

}//endBulletUpdate

//--------------------------------------------------------------
//The bullet pick up item
void testApp::bulletItemDraw() {
	for(int i = 0; i < bulletItems.size(); i+=300) {
		bulletItems[i].updateBulletItem();
		bulletItems[i].displayBulletItem();
		if(bulletItems[i].pos.x < 0) {
				ti[i].pos.set(-50,0);
				ti[i].vel.set(0,0);

		}//endIf
	}//endFor
}//end bulletItemDraw

void testApp::bulletItemUpdate() {
	if(spawnBulletItem == true) {
		for(int i = 0; i < 1; i++) {
			bulletItems.push_back(bullet());
		}//endFor
		bulletItemDraw();
		
	}//endIf
}//endBulletItemUpdate

//--------------------------------------------------------------

//The background particles
void testApp::particleDraw() {
    for (int i = 0; i < particle.size(); i++) {
        particle[i].update();
        particle[i].display();
    }//endFor
}//endParticleDraw

void testApp::particleDisplay() {
	if(spawnBackgroundParticles == true) {
	 for(int i = 0; i <= 1; i++) {
			particle.push_back(particles());
			if(particle[i].pos.x < 0) {
				particle.erase(particle.begin());
			}//endIf
			if(particle.size() > 800){
				particle.erase(particle.begin());
			}//endIf
		}//endFor
	}//endIf
    particleDraw();
}//endParticleDisplay

//The enemies/core's
//--------------------------------------------------------------
void testApp::enemyOneDraw(){
	//Enemy one
	for(int i = 0; i < eneOne.size(); i+=50) {
		eneOne[i].update();
		eneOne[i].display();
		if(eneOne[i].pos.x < 0) {
				eneOne[i].pos.set(-50,0);
				eneOne[i].vel.set(0,0);
			}
		}
	}

void testApp::enemyOneUpdate(){
	for(int i = 0; i < 1; i++) {
		if(spawnOne == true) {
		eneOne.push_back(enemyOne());
		}
	}
	enemyOneDraw();
}

//--------------------------------------------------------------
void testApp::enemyTwoDraw(){
	for(int i = 0; i < eneTwo.size(); i+=100) {
		eneTwo[i].update();
		eneTwo[i].display();
		if(eneTwo[i].pos.x < 0) {
				eneTwo[i].pos.set(-50,0);
				eneTwo[i].vel.set(0,0);
			}
		}
	
}

void testApp::enemyTwoUpdate(){
	for(int i = 0; i < 1; i++) {
		if(spawnTwo == true) {
		eneTwo.push_back(enemyTwo());
		}
	}
	enemyTwoDraw();
}


//--------------------------------------------------------------
void testApp::enemyThreeDraw(){
	for(int i = 0; i < eneThree.size(); i+=150) {
		eneThree[i].update();
		eneThree[i].display();
		if(eneThree[i].pos.x < 0) {
				eneThree[i].pos.set(-50,0);
				eneThree[i].vel.set(0,0);
			}
		}
	}

void testApp::enemyThreeUpdate(){
	for(int i = 0; i < 1; i++) {
		if(spawnThree == true) {
		eneThree.push_back(enemyThree());
		}
	}

	enemyThreeDraw();
}


//--------------------------------------------------------------
void testApp::timerObjectDraw(){
	for(int i = 0; i < ti.size(); i+=500) {
		ti[i].updateTimerObject();
		ti[i].drawTimerObject();
		if(ti[i].pos.x < 0) {
				ti[i].pos.set(-50,0);
				ti[i].vel.set(0,0);
			}
		}
	}

void testApp::timerObjectUpdate(){
	for(int i = 0; i < 1; i++) {
		if(spawnTimer == true) {
		ti.push_back(timer());
		}
	}
	timerObjectDraw();
}

/*******************************--COLLISION DETECTION--******************************/

//--------------------------------------------------------------
void testApp::bulletItemandPlayerCollide(){
	for(int i = 0; i < bulletItems.size(); i++) {
		bulletItems[i].collisionDetectWithPlayer(c.pos, c.width, c.height);
		
	}
}

//--------------------------------------------------------------
void testApp::timerCollideWithPlayer(){
	for(int i = 0; i < ti.size(); i++) {
		ti[i].collisionDetect(c.pos,c.width,c.height);
		}
}

//--------------------------------------------------------------
void testApp::enemyCollideWithPlayer(){
	
	for(int i = 0; i < eneOne.size(); i++) {
		eneOne[i].collisionDetect(c.pos, c.width, c.height);
		}

	for(int j = 0; j < eneTwo.size(); j++) {
		eneTwo[j].collisionDetect(c.pos, c.width, c.height);
		}

	for(int k = 0; k < eneThree.size(); k++) {
		eneThree[k].collisionDetect(c.pos, c.width, c.height);
		}
}

//--------------------------------------------------------------
//Boss bullet
void testApp::beamCollides() {
	_boss.collisionDetect(c.pos, c.width, c.height);
}

void testApp::bulletCollidesWithBoss() {
	for(int i = 0; i<bullets.size(); i++) {
			bullets[i].collisionDetect(_boss.enemy_position, _boss.enemyWidth, _boss.enemyHeight);
	}//for i
}



//--------------------------------------------------------------
void testApp:: playerShoot(){
		bulletUpdate();
}
//--------------------------------------------------------------
void testApp::update(){

	//Bullet Item collides with player
	for(int h = 0; h < bulletItems.size(); h++) {
		if(bulletItems[h].returnCollidedWithPlayer()) {
			bulletItems[h].itemPos.set(500,500);
			b.totalBullets++;
		}
	}

	//Each enemy does different damage to the player, one being the that outputs the lowest damage where as the third one being the most damaging of all
	//Enemy one collides with player
	for(int i = 0; i<eneOne.size(); i++) {
		if(eneOne[i].returnCollided()) {
			eneOne[i].pos.set(500,500);
			c.deathCount++;
		}
	}

	//Enemy two collides with player
	for(int j = 0; j<eneTwo.size(); j++) {
		if(eneTwo[j].returnCollided()) {
			eneTwo[j].pos.set(500,500);
			c.deathCount+=2;
		}
	}

	//Enemy three collides with player
	for(int j = 0; j<eneThree.size(); j++) {
		if(eneThree[j].returnCollided()) {
			eneThree[j].pos.set(500,500);
			c.deathCount+=3;
		}
	}

	//timer
	for(int k = 0; k<ti.size(); k++) {
		if(ti[k].returnCollided()) {
			ti[k].pos.set(500,500);
			timerPickup.play();
		}
		if(ti[k].returnResetBar()) {
			t.dimX = 0;
			t.colB = 255;
			t.colG = 255;
			t.colR = 255;
			
		}
	}

	//Bullet Collides with Boss
	for(int l = 0; l < bullets.size(); l++) {
		if(bullets[l].returnCollided()) {
			cout<<_boss.deathCount<<endl;
			_boss.deathCount++;
			hit.play();
			bullets[l].pos.set(0,0);
			bullets[l].vel.set(0,0);
			
		}//if
	}//for i

	//Beam collides with player
	if(_boss.returnCollided()) {
		c.deathCount++;
	}

	beamCollides();
	bulletItemandPlayerCollide();
	enemyCollideWithPlayer();
	timerCollideWithPlayer();
	bulletCollidesWithBoss();
	c.update();
	
}

//--------------------------------------------------------------
void testApp::draw(){
	//Draws the main screen
	if(chooseScreen == true) {
		m.displayChooseScreen();
	}
	
	//Setting the screen where the player can press space to start regardless of mode chosen
	if(endlessMode == true || storyMode == true) {
		menuScreen = true;
	}

	//Displays the menu screen
	if(menuScreen == true) {
		m.displayGameStart();
		m.drawGameStartString();
		m.drawEdges();
		chooseScreen = false;
	}

	//Starts the game when the player presses space
	if(menuScreen == false && chooseScreen == false) {
		gameStart = true;
	}

	//When the game starts
	if(gameStart == true) {
		ofBackground(92,1,106);
		allowMove = true;
		particleDisplay();
		bulletItemUpdate();
		enemyOneUpdate();
		enemyTwoUpdate();
		enemyThreeUpdate();
		timerObjectUpdate();
		playerMove();
		bulletDraw();
		spawner();
		g.display();
		t.timerBarDisplay();
		t.timerBarColorUpdate();
		c.display();
		if(storyMode == true) {
			_boss.enterBoss();
			b.displayString();
		}
		
		
	}

	//If the timer bar gets filled or the player dies through other means displays the game over screen
	if(c.getDead() == true || t.getDead() == true) {
		gameEnd = true;
		gameWin = false;
		gameStart = false;
		spawnCount = 0;
		spawnOne = false;
		spawnTwo = false;
		spawnThree = false;
		spawnTimer = false;
	}

	//If the boss is killed displays the you win screen
	if(_boss.getDead() == true) {
		gameWin = true;
		gameStart = false;
		spawnCount = 0;
		spawnOne = false;
		spawnTwo = false;
		spawnThree = false;
		spawnTimer = false;
	}

	//If the player dies, clear all the vectors, stop all the sounds and all the other functionality
	if(gameEnd == true) {
		bossStage = false;
		allowShoot = false;
		m.displayGameOver() ;
		m.drawGameOverString();
		m.drawEdges();
		eneOne.clear();
		eneTwo.clear();
		eneThree.clear();
		particle.clear();
		ti.clear();
		bullets.clear();
		menu.stop();
		move.stop();
		hit.stop();
	}
	
	//If the player wins, clear all the vectors, stop all the sounds and all the other functionality
	if(gameWin == true) {
		bossStage = false;
		allowShoot = false;
		m.displayYouWin();
		m.drawYouWinString();
		m.drawEdges();
		eneOne.clear();
		eneTwo.clear();
		eneThree.clear();
		particle.clear();
		ti.clear();
		bullets.clear();
		menu.stop();
		move.stop();
		hit.stop();
	}

	//If restart is chosen by the player, reset everything to the initial game start state
	if(gameReset == true) {
		ofBackground(92,1,106);
		menu.play();
		eneOne.clear();
		eneTwo.clear();
		eneThree.clear();
		particle.clear();
		bullets.clear();
		ti.clear();
		c.reset();
		t.reset();
		_boss.reset();
		gameWait = true;
		gameWin = false;
		gameStart = false;
		gameReset = false;
		gameEnd = false;
		bossStage = false;
		chooseScreen = false;
	}
}

//--------------------------------------------------------------
//Allowing the player to move.
void testApp::playerMove(){
	if(allowMove == true) {
		 if(up == true) {
			c.vel.y-= 0.1;
		}
    
		if(down == true) {
			c.vel.y+= 0.1;
		}
    
		if(right == true) {
			c.vel.x+= 0.1;
		}
    
		if(left == true) {
			c.vel.x-= 0.1;
		}
	}

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    /*
     left arrow key = 356
     up arrow key = 357
     right arrow key = 358
     down arrow key = 359
     w = 119
     a = 97
     s = 115
     d = 100
     */
    //cout<< key << endl;
    //Movement of the player
	
	if(chooseScreen == true) {
		if (key == '1') {
			endlessMode = true;
		}	

		if(key == '2') {
			storyMode = true;
		}
	}

    if(key == 119 || key == 357) {//Up
        up = true;
		move.play();
    }//if
    if(key == 97|| key == 356) {//Left
        left = true;
		move.play();
    }//if
    if (key == 115|| key == 359) {//Down
        down = true;
		move.play();
    }//if
    if(key == 100|| key == 358) {//Right
        right = true;
		move.play();
    }//if
	if(key == 32) {//Space key
		if(chooseScreen == false) {
			gameStart = true;
		}
	}//end if spac

    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if(key == 119 || key == 357) {//Up
        up = false;
    }//if
    if(key == 97|| key == 356) {//Left
        left = false;
    }//if
    if (key == 115|| key == 359) {//Down
        down = false;
    }//if
    if(key == 100|| key == 358) {//Right
        right = false;
    }//if
	if(key == 32) {//Space key
		//
	}//if
    
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	//Shooting the bullets when pressing a mouseButton
    //button 0 = left mouse button
    //button 1 = middle mouse button
    //button 3 = right mouse button
	
	//Restart
    if(button == 0) {
		t.resetBar = true;
		if(ofGetMouseX() >= 251 && ofGetMouseX() < 302 && 
		   ofGetMouseY() >= 236 && ofGetMouseY() < 250) {
			if(gameStart == false) {
				if(gameWait == true) {
					gameStart = true;
					gameWait = false;
				}//end if gameWait
				gameReset = true;
				gameStart = true;
			}//end if gameStart = false
		}//end if restart button detection
		
		//Exit
		if(ofGetMouseX() >= 310 && ofGetMouseX() < 335 && 
		   ofGetMouseY() >= 236 && ofGetMouseY() < 250) {
			if(gameStart == false) {
				exitApp();
			}//end if gameStart = false
		}//end if exit button detection

		//When player wins the game
		if(gameWin == true) {
			t.resetBar = true;
			//Restart
			if(ofGetMouseX() >= 251 && ofGetMouseX() < 302 && 
			   ofGetMouseY() >= 256 && ofGetMouseY() < 270) {
				if(gameStart == false) {
					if(gameWait == true) {
						gameStart = true;
						gameWait = false;
					}//end if gameWait
					gameReset = true;
					gameStart = true;
				}//end if gameStart = false
			}//end if restart button detection
		
			//Exit
			if(ofGetMouseX() >= 310 && ofGetMouseX() < 335 && 
			   ofGetMouseY() >= 256 && ofGetMouseY() < 270) {
				if(gameStart == false) {
					exitApp();
				}//end if gameStart = false
			}//end if exit button detection
		}//endGameWin

		if(bossStage == true) {
			allowShoot = true;
		}
		//Here this allows the player to shoot if the number of bullets is greater than 0
		if(b.getTotalBullets() <= 0) {
			allowShoot = false;
		}//endIf

		if(allowShoot == true) {
			shoot.play();
			bulletUpdate();
		}

		

		
    }//end if left mouseButton
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
