#include "rsdl.hpp"
#include <fstream>
#include <vector>
#include <string> 
#include <ctime>
#include <cmath>
#include <unistd.h>
using namespace std;


#define ENEMY_sizeX 50
#define ENEMY_sizeY 50
#define TOWER_sizeX 70
#define TOWER_sizeY 70
#define TOWER_RANGE 85

#define BULLET_SIZEX 15
#define BULLET_SIZEY 22
#define BULLET_VELOCITY 5

#define INITIAL_LIFE 15
#define INITIAL_MONEY 220

#define ARCHER_DAMAGE 50
#define ARCHER_COST 70
#define ARCHER_DELAY 700
#define ARCHER_MAGICAL false
#define ARCHER_PHYSICAL true

#define CANON_DAMAGE 140
#define CANON_COST 120
#define CANON_DELAY 2000
#define CANON_MAGICAL false
#define CANON_PHYSICAL true
#define CANON_RANGE 50

#define MAGE_DAMAGE 140
#define MAGE_COST 90
#define MAGE_DELAY 1500
#define MAGE_MAGICAL true
#define MAGE_PHYSICAL false

#define ICY_DAMAGE 30
#define ICY_COST 80
#define ICY_DELAY 2000
#define ICY_MAGICAL true
#define ICY_PHYSICAL false
#define ICY_RANGE 50

#define ORC 1
#define ORC_LIFE 200
#define ORC_VELOCITY 4
#define ORC_PRIZE 5
#define ORC_POWER 1
#define ORC_MAGIC false
#define ORC_PHYSIC false

#define WOLF 2
#define WOLF_LIFE 100
#define WOLF_VELOCITY 7
#define WOLF_PRIZE 4
#define WOLF_POWER 1
#define WOLF_MAGIC false
#define WOLF_PHYSIC false

#define ARMORED 3
#define ARMORED_LIFE 450
#define ARMORED_VELOCITY 2
#define ARMORED_PRIZE 8
#define ARMORED_POWER 3
#define ARMORED_MAGIC false
#define ARMORED_PHYSIC true

#define DEMON 4
#define DEMON_LIFE 400
#define DEMON_VELOCITY 2
#define DEMON_PRIZE 8
#define DEMON_POWER 3
#define DEMON_MAGIC true
#define DEMON_PHYSIC false

#define SLOT_HIGHT 20
#define SLOT_WIDTH 30

#define START_1X 730
#define START_1Y 283
#define END_1X 350
#define END_1Y 700

#define SLOT0_1X 488
#define SLOT1_1X 346
#define SLOT2_1X 145
#define SLOT3_1X 300
#define SLOT4_1X 354
#define SLOT5_1X 435
#define SLOT6_1X 533
#define SLOT7_1X 440

#define SLOT0_1Y 220
#define SLOT1_1Y 222
#define SLOT2_1Y 343
#define SLOT3_1Y 373
#define SLOT4_1Y 512
#define SLOT5_1Y 485
#define SLOT6_1Y 588
#define SLOT7_1Y 631

#define TURN1_1X 530
#define TURN2_1X 530
#define TURN3_1X 405
#define TURN4_1X 395
#define TURN5_1X 202
#define TURN6_1X 200
#define TURN7_1X 480
#define TURN8_1X 490
#define TURN9_1X 330

#define TURN1_1Y 265
#define TURN2_1Y 115
#define TURN3_1Y 115
#define TURN4_1Y 263
#define TURN5_1Y 285
#define TURN6_1Y 420
#define TURN7_1Y 387
#define TURN8_1Y 515
#define TURN9_1Y 545

#define START_2X 500
#define START_2Y 0
#define END_2X 506
#define END_2Y 720

#define SLOT0_2X 477
#define SLOT1_2X 395
#define SLOT2_2X 305
#define SLOT3_2X 505
#define SLOT4_2X 408
#define SLOT5_2X 480
#define SLOT6_2X 382
#define SLOT7_2X 595

#define SLOT0_2Y 270
#define SLOT1_2Y 269
#define SLOT2_2Y 267
#define SLOT3_2Y 415
#define SLOT4_2Y 418
#define SLOT5_2Y 561
#define SLOT6_2Y 556
#define SLOT7_2Y 610

#define TURN1_2X 502
#define TURN2_2X 180
#define TURN3_2X 222
#define TURN4_2X 609
#define TURN5_2X 545
#define TURN6_2X 255
#define TURN7_2X 270
#define TURN8_2X 531

#define TURN1_2Y 175
#define TURN2_2Y 194
#define TURN3_2Y 318
#define TURN4_2Y 345
#define TURN5_2Y 473
#define TURN6_2Y 475
#define TURN7_2Y 604
#define TURN8_2Y 635



typedef struct TOWER{
	int x,y;
	string pic;
	int damage;
	int cost;
	int delay;
	int range=0;
	bool magical;
	bool physical;
} TOWER;

typedef struct ATTACK{
	int enemyType;
	int wait;
	int number;
}ATTACK;

typedef struct ENEMY{
	ATTACK attack;
	int type;
	float x;
	float y;
	char direction;
	int count=0;
	int velocity;
	int life;
	int prize;
	int power;
	bool magicArmor;
	bool physicalArmor;
}ENEMY;

typedef struct BULLET{
	float x,y;
	float angle;
	TOWER *tower;
	ENEMY *enemy;
} BULLET;

typedef struct PLAYER{
	int life;
	int money;
}PLAYER;



int checkPointOne(int &x,int &y,bool* slot);
int checkPointTwo(int &x,int &y,bool* slot);
bool checkMoney(char c,int x,int y,PLAYER &player);
bool checkRange(ENEMY &enemy,TOWER &tower);

TOWER initializeTower(int x,int y,char c);	
void initializeAttack(vector<ATTACK> &attack, int level);
void initializePointsOne(vector<int> &thePointsX,vector<int> &thePointsY);
void initializePointsTwo(vector<int> &thePointsX,vector<int> &thePointsY);
ENEMY initializeEnemy(ATTACK &attack);
BULLET initializeBullets(TOWER &tower);
void initializeBulletsEnemy(BULLET &bullet, vector<ENEMY> &theEnemies);

char moveEnemy(ENEMY &enemy,vector<int> &thePointsX,vector<int> &thePointsY,time_t startTime);
bool moveBullet(BULLET &bullet, PLAYER &player);	

void drawTower(Window &w,vector<TOWER> &theTowers);
void drawEnemy(Window &w, vector<ENEMY> &enemy);
void drawBullet(Window &w, vector<BULLET> &theBullets);
void writeLifeMoney(Window &w,PLAYER &player);