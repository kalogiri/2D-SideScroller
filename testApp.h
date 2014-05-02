#pragma once

#include "ofMain.h"
#include "enemyOne.h"
#include "enemyTwo.h"
#include "enemyThree.h"
#include "gui.h"
#include "player.h"
#include "timer.h"
#include "mainMenu.h"
#include "particles.h"
#include "bullet.h"
#include "boss.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

		//Spawner system for the items and enemies
		void spawner();
		bool spawnBulletItem;
		bool spawnOne;
		bool spawnTwo;
		bool spawnThree;
		bool spawnTimer;
		bool spawnBackgroundParticles;
		float spawnCount;

		//Background Particle
		void particleDraw();
		void particleDisplay();
		vector<particles> particle;
		particles p;
		
		//Timer
		void timerCollideWithPlayer();
		void timerObjectDraw();
		void timerObjectUpdate();
		vector<timer> ti;
		timer t;

		//Bullet
		void bulletDraw();
		void bulletUpdate();
		void bulletItemDraw();
		void bulletItemUpdate();
		void playerShoot();
		void bulletandEnemyCollide();
		void bulletItemandPlayerCollide();
		int totalBullets;
		bool allowShoot;
		bool keyShoot;
		vector<bullet>bullets;
		vector<bullet>bulletItems;
		bullet b;

		//Player
		void playerMove();
		bool up;
		bool down;
		bool left;
		bool right;
		bool allowMove;
		player c;

		//Enemies

		void enemyCollideWithPlayer();
		void bossSpawned();

		//Enemy One
		void enemyOneDraw();
		void enemyOneUpdate();
		vector<enemyOne> eneOne;
		enemyOne e1;
		
		//Enemy Two
		void enemyTwoDraw();
		void enemyTwoUpdate();
		vector<enemyTwo> eneTwo;
		enemyTwo e2;
		
		//Enemy Three
		void enemyThreeDraw();
		void enemyThreeUpdate();
		vector<enemyThree> eneThree;
		enemyThree e3;
		
		//Boss
		void bossDraw();
		void bossUpdate();
		void enterBoss();
		void bulletCollidesWithBoss();
		bool bossStage;
		boss _boss;

		//Boss Beam
		void beamCollides();
		
		//The GUI and the screens for different game states
		bool gameReset;
		bool gameWait;
		bool gameEnd;
		bool gameStart;
		bool menuScreen;
		bool chooseScreen;
		bool endlessMode;
		bool storyMode;
		bool gameWin;
		gui g;
		mainMenu m;

		//Sounds
		ofSoundPlayer shoot, move, hit;
		ofSoundPlayer menu;
		ofSoundPlayer timerPickup;

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);		
};
