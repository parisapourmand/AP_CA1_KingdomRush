#include "functions.hpp"
using namespace std;

int checkPointOne(int &x,int &y,bool* slot){
	if((x< SLOT0_1X+SLOT_WIDTH && x> SLOT0_1X-SLOT_WIDTH && y < SLOT0_1Y+SLOT_HIGHT && y> SLOT0_1Y-SLOT_HIGHT) && slot[0]==0){
		x=SLOT0_1X;
		y=SLOT0_1Y;
		return 0;
	}
	if((x< SLOT1_1X+SLOT_WIDTH && x> SLOT1_1X-SLOT_WIDTH && y < SLOT1_1Y+SLOT_HIGHT && y> SLOT1_1Y-SLOT_HIGHT) && slot[1]==0){
		x=SLOT1_1X;
		y=SLOT1_1Y;
		return 1;
	}
	if((x< SLOT2_1X+SLOT_WIDTH && x> SLOT2_1X-SLOT_WIDTH && y < SLOT2_1Y+SLOT_HIGHT && y> SLOT2_1Y-SLOT_HIGHT) && slot[2]==0){
		x=SLOT2_1X;
		y=SLOT2_1Y;
		return 2;
	}
	if((x< SLOT3_1X+SLOT_WIDTH && x> SLOT3_1X-SLOT_WIDTH && y < SLOT3_1Y+SLOT_HIGHT && y> SLOT3_1Y-SLOT_HIGHT) && slot[3]==0){
		x=SLOT3_1X;
		y=SLOT3_1Y;
		return 3;
	}
	if((x< SLOT4_1X+SLOT_WIDTH && x> SLOT4_1X-SLOT_WIDTH && y < SLOT4_1Y+SLOT_HIGHT && y> SLOT4_1Y-SLOT_HIGHT) && slot[4]==0){
		x=SLOT4_1X;
		y=SLOT4_1Y;
		return 4;
	}
	if((x< SLOT5_1X+SLOT_WIDTH && x> SLOT5_1X-SLOT_WIDTH && y < SLOT5_1Y+SLOT_HIGHT && y> SLOT5_1Y-SLOT_HIGHT) && slot[5]==0){
		x=SLOT5_1X;
		y=SLOT5_1Y;
		return 5;
	}
	if((x< SLOT6_1X+SLOT_WIDTH && x> SLOT6_1X-SLOT_WIDTH && y < SLOT6_1Y+SLOT_HIGHT && y> SLOT6_1Y-SLOT_HIGHT) && slot[6]==0){
		x=SLOT6_1X;
		y=SLOT6_1Y;
		return 6;
	}
	if((x< SLOT7_1X+SLOT_WIDTH && x> SLOT7_1X-SLOT_WIDTH && y < SLOT7_1Y+SLOT_HIGHT && y> SLOT7_1Y-SLOT_HIGHT) && slot[7]==0){
		x=SLOT7_1X;
		y=SLOT7_1Y;
		return 7;
	}
	else
		return -1;
}

int checkPointTwo(int &x,int &y,bool* slot){
	if((x< SLOT0_2X+SLOT_WIDTH && x> SLOT0_2X-SLOT_WIDTH && y < SLOT0_2Y+SLOT_HIGHT && y> SLOT0_2Y-SLOT_HIGHT) && slot[0]==0){
		x=SLOT0_2X;
		y=SLOT0_2Y;
		return 0;
	}
	if((x< SLOT1_2X+SLOT_WIDTH && x> SLOT1_2X-SLOT_WIDTH && y < SLOT1_2Y+SLOT_HIGHT && y> SLOT1_2Y-SLOT_HIGHT) && slot[1]==0){
		x=SLOT1_2X;
		y=SLOT1_2Y;
		return 1;
	}
	if((x< SLOT2_2X+SLOT_WIDTH && x> SLOT2_2X-SLOT_WIDTH && y < SLOT2_2Y+SLOT_HIGHT && y> SLOT2_2Y-SLOT_HIGHT) && slot[2]==0){
		x=SLOT2_2X;
		y=SLOT2_2Y;
		return 2;
	}
	if((x< SLOT3_2X+SLOT_WIDTH && x> SLOT3_2X-SLOT_WIDTH && y < SLOT3_2Y+SLOT_HIGHT && y> SLOT3_2Y-SLOT_HIGHT) && slot[3]==0){
		x=SLOT3_2X;
		y=SLOT3_2Y;
		return 3;
	}
	if((x< SLOT4_2X+SLOT_WIDTH && x> SLOT4_2X-SLOT_WIDTH && y < SLOT4_2Y+SLOT_HIGHT && y> SLOT4_2Y-SLOT_HIGHT) && slot[4]==0){
		x=SLOT4_2X;
		y=SLOT4_2Y;
		return 4;
	}
	if((x< SLOT5_2X+SLOT_WIDTH && x> SLOT5_2X-SLOT_WIDTH && y < SLOT5_2Y+SLOT_HIGHT && y> SLOT5_2Y-SLOT_HIGHT) && slot[5]==0){
		x=SLOT5_2X;
		y=SLOT5_2Y;
		return 5;
	}
	if((x< SLOT6_2X+SLOT_WIDTH && x> SLOT6_2X-SLOT_WIDTH && y < SLOT6_2Y+SLOT_HIGHT && y> SLOT6_2Y-SLOT_HIGHT) && slot[6]==0){
		x=SLOT6_2X;
		y=SLOT6_2Y;
		return 6;
	}
	if((x< SLOT7_2X+SLOT_WIDTH && x> SLOT7_2X-SLOT_WIDTH && y < SLOT7_2Y+SLOT_HIGHT && y> SLOT7_2Y-SLOT_HIGHT) && slot[7]==0){
		x=SLOT7_2X;
		y=SLOT7_2Y;
		return 7;
	}
	else
		return -1;
}


bool checkMoney(char c,int x,int y,PLAYER &player){
	if(c=='a' && player.money >= ARCHER_COST ){
		player.money -= ARCHER_COST;
		return true;
		}
	if(c=='c' && player.money >= CANON_COST ){
		player.money -= CANON_COST;
		return true;
		}
	if(c=='i' && player.money >= ICY_COST ){
		player.money -= ICY_COST;
		return true;
		}
	if(c=='m' && player.money >= MAGE_COST ){
		player.money -= MAGE_COST;
		return true;
		}
	return false;
}

TOWER initializeTower(int x,int y,char c){
	TOWER choosen;
	choosen.x = x;
	choosen.y = y;
	switch (c){
		case 'a':
			choosen.damage= ARCHER_DAMAGE;
			choosen.cost= ARCHER_COST;
			choosen.delay= ARCHER_DELAY;
			choosen.magical= ARCHER_MAGICAL;
			choosen.physical= ARCHER_PHYSICAL;
			choosen.pic = "towers/archer.png";
			break;
		case 'c':
			choosen.damage= CANON_DAMAGE;
			choosen.cost= CANON_COST;
			choosen.delay= CANON_DELAY;
			choosen.magical= CANON_MAGICAL;
			choosen.physical= CANON_PHYSICAL;
			choosen.pic = "towers/canon.png";
			choosen.range = CANON_RANGE;
			break;	
		case 'm':
			choosen.damage= MAGE_DAMAGE;
			choosen.cost= MAGE_COST;
			choosen.delay= MAGE_DELAY;
			choosen.magical= MAGE_MAGICAL;
			choosen.physical= MAGE_PHYSICAL;
			choosen.pic = "towers/mage.png";
			break;	
		case 'i':
			choosen.damage= ICY_DAMAGE;
			choosen.cost= ICY_COST;
			choosen.delay= ICY_DELAY;
			choosen.magical= ICY_MAGICAL;
			choosen.physical= ICY_PHYSICAL;
			choosen.pic = "towers/icy.png";
			choosen.range = ICY_RANGE;
			break;
	}
	return choosen;
}

void drawTower(Window &w,vector<TOWER> &theTowers){
	for(int i=0;i< theTowers.size();i++){
			w.draw_png(theTowers[i].pic,theTowers[i].x-TOWER_sizeX/2,theTowers[i].y-TOWER_sizeY/2,TOWER_sizeX,TOWER_sizeY);
	}
}

void initializeAttack(vector<ATTACK> &attack, int level){
	string strLine;
	char temptype;
	ATTACK temp;
	ifstream myfile;

	if(level==1)
		myfile.open("levels/level1-waves.txt");
	else
		myfile.open("levels/level2-waves.txt");

	if (!myfile) {
    	cerr << "Unable to open file datafile.txt";
    	exit(1); 
	}
	int counter=0;
	 while(getline(myfile,strLine)){
	 		string tempwait="";
			string tempnum="";
	 		attack.push_back(temp);
			int i=0;
	 		for(i;strLine[i]!='-';i++)
	 			tempwait+=strLine[i];
	 		attack[counter].wait =stoi(tempwait);
	 		i++;
	 		for(i;strLine[i]!='-';i++)
	 			tempnum+=strLine[i];
	 		attack[counter].number =stoi(tempnum);
	 		i++;
	 		temptype=strLine[i];
	 		switch(temptype){
	 			case 'o':
	 				attack[counter].enemyType=ORC;
	 				break;
	 			case 'a':
	 				attack[counter].enemyType=ARMORED;
	 				break;
	 			case 'w':
	 				attack[counter].enemyType=WOLF;
	 				break;
	 			case 'd':
	 				attack[counter].enemyType=DEMON;
	 				break;
	 		}
	counter++;
	}
	myfile.close();
}

void initializePointsOne(vector<int> &thePointsX,vector<int> &thePointsY){
	thePointsX.push_back(TURN1_1X);
	thePointsX.push_back(TURN2_1X);
	thePointsX.push_back(TURN3_1X);
	thePointsX.push_back(TURN4_1X);
	thePointsX.push_back(TURN5_1X);
	thePointsX.push_back(TURN6_1X);
	thePointsX.push_back(TURN7_1X);
	thePointsX.push_back(TURN8_1X);
	thePointsX.push_back(TURN9_1X);
	thePointsX.push_back(END_1X);

	thePointsY.push_back(TURN1_1Y);
	thePointsY.push_back(TURN2_1Y);
	thePointsY.push_back(TURN3_1Y);
	thePointsY.push_back(TURN4_1Y);
	thePointsY.push_back(TURN5_1Y);
	thePointsY.push_back(TURN6_1Y);
	thePointsY.push_back(TURN7_1Y);
	thePointsY.push_back(TURN8_1Y);
	thePointsY.push_back(TURN9_1Y);
	thePointsY.push_back(END_1Y);
}	

void initializePointsTwo(vector<int> &thePointsX,vector<int> &thePointsY){
	thePointsX.push_back(TURN1_2X);
	thePointsX.push_back(TURN2_2X);
	thePointsX.push_back(TURN3_2X);
	thePointsX.push_back(TURN4_2X);
	thePointsX.push_back(TURN5_2X);
	thePointsX.push_back(TURN6_2X);
	thePointsX.push_back(TURN7_2X);
	thePointsX.push_back(TURN8_2X);
	thePointsX.push_back(END_2X);

	thePointsY.push_back(TURN1_2Y);
	thePointsY.push_back(TURN2_2Y);
	thePointsY.push_back(TURN3_2Y);
	thePointsY.push_back(TURN4_2Y);
	thePointsY.push_back(TURN5_2Y);
	thePointsY.push_back(TURN6_2Y);
	thePointsY.push_back(TURN7_2Y);
	thePointsY.push_back(TURN8_2Y);
	thePointsY.push_back(END_2Y);
}	

ENEMY initializeEnemy(ATTACK &attack){
	ENEMY enemy;
	switch(attack.enemyType){
		case ORC:
			enemy.attack=attack;
			enemy.type= ORC;
			enemy.velocity= ORC_VELOCITY;
			enemy.life= ORC_LIFE;
			enemy.prize= ORC_PRIZE;
			enemy.power= ORC_POWER;
			enemy.magicArmor= ORC_MAGIC;
			enemy.physicalArmor= ORC_PHYSIC;
			break;
		case WOLF:
			enemy.attack=attack;
			enemy.type= WOLF;
			enemy.velocity= WOLF_VELOCITY;
			enemy.life= WOLF_LIFE;
			enemy.prize= WOLF_PRIZE;
			enemy.power= WOLF_POWER;
			enemy.magicArmor= WOLF_MAGIC;
			enemy.physicalArmor= WOLF_PHYSIC;
			break;
		case ARMORED:
			enemy.attack=attack;
			enemy.type= ARMORED;
			enemy.velocity= ARMORED_VELOCITY;
			enemy.life= ARMORED_LIFE;
			enemy.prize= ARMORED_PRIZE;
			enemy.power= ARMORED_POWER;
			enemy.magicArmor= ARMORED_MAGIC;
			enemy.physicalArmor= ARMORED_PHYSIC;
			break;
		case DEMON:
			enemy.attack=attack;
			enemy.type= DEMON;
			enemy.velocity= DEMON_VELOCITY;
			enemy.life= DEMON_LIFE;
			enemy.prize= DEMON_PRIZE;
			enemy.power= DEMON_POWER;
			enemy.magicArmor= DEMON_MAGIC;
			enemy.physicalArmor= DEMON_PHYSIC;
			break;
	}
	return enemy;
}

char moveEnemy(ENEMY &enemy,vector<int> &thePointsX,vector<int> &thePointsY,time_t startTime){
	if(enemy.life>0){
		time_t currTime;
		time(&currTime);
		if(difftime(currTime,startTime) >= enemy.attack.wait){
			float goalX=thePointsX[enemy.count];
			float goalY=thePointsY[enemy.count];
			float preX=enemy.x;
			float preY=enemy.y;
			float distance = sqrt(pow(goalX-enemy.x,2) +pow(goalY-enemy.y,2));
			enemy.x += ( ((goalX-enemy.x)/distance) *enemy.velocity )/5;
			enemy.y += ( ((goalY-enemy.y)/distance) *enemy.velocity )/5;
		
			float diffX = abs(goalX - preX);
			float diffY = abs(goalY - preY);
		
			if(enemy.x< goalX+20 && enemy.x> goalX-20 && enemy.y < goalY+20 && enemy.y> goalY-20)
				enemy.count++;
			if(diffX>=diffY){
				if(goalX > preX)
					return 'r';
				if(goalX < preX)
					return 'l';
			}
			else{
				if(goalY < preY)
					return 'u';
				if(goalY > preY)
					return 'd';
			}
		}	
	}
}

void drawEnemy(Window &w, vector<ENEMY> &enemy){
		for(int i=0;i< enemy.size();i++){
			switch(enemy[i].type){
				case ORC:
				if(enemy[i].life < 1)
					w.draw_png("enemy/orc/dead.png", enemy[i].x, enemy[i].y, ENEMY_sizeX, ENEMY_sizeY);
				else
					switch (enemy[i].direction){
						case 'l' :
							w.draw_png("enemy/orc/left.png", enemy[i].x, enemy[i].y, ENEMY_sizeX, ENEMY_sizeY);
							break;
						case 'r' :
							w.draw_png("enemy/orc/right.png",  enemy[i].x, enemy[i].y, ENEMY_sizeX, ENEMY_sizeY);
							break;
						case 'u' :
							w.draw_png("enemy/orc/back.png",  enemy[i].x, enemy[i].y, ENEMY_sizeX, ENEMY_sizeY);
							break;
						case 'd' :
							w.draw_png("enemy/orc/front.png",  enemy[i].x, enemy[i].y, ENEMY_sizeX, ENEMY_sizeY);
							break;
					}
				break;
	
				case WOLF:
				if(enemy[i].life < 1)
					w.draw_png("enemy/wolf/dead.png", enemy[i].x, enemy[i].y, ENEMY_sizeX, ENEMY_sizeY-15);
				else
					switch (enemy[i].direction){
						case 'l' :
							w.draw_png("enemy/wolf/left.png", enemy[i].x, enemy[i].y, ENEMY_sizeX, ENEMY_sizeY);
							break;
						case 'r' :
							w.draw_png("enemy/wolf/right.png", enemy[i].x, enemy[i].y, ENEMY_sizeX, ENEMY_sizeY);
							break;
						case 'u' :
							w.draw_png("enemy/wolf/back.png", enemy[i].x, enemy[i].y, ENEMY_sizeX, ENEMY_sizeY);
							break;
						case 'd' :
							w.draw_png("enemy/wolf/front.png", enemy[i].x, enemy[i].y, ENEMY_sizeX, ENEMY_sizeY);
							break;
						}
					break;
				case ARMORED:
				if(enemy[i].life < 1)
					w.draw_png("enemy/armored/dead.png", enemy[i].x, enemy[i].y, ENEMY_sizeX, ENEMY_sizeY);
				else
					switch (enemy[i].direction){
						case 'l' :
							w.draw_png("enemy/armored/left.png", enemy[i].x, enemy[i].y, ENEMY_sizeX, ENEMY_sizeY);
							break;
						case 'r' :
							w.draw_png("enemy/armored/right.png", enemy[i].x, enemy[i].y, ENEMY_sizeX, ENEMY_sizeY);
							break;
						case 'u' :
							w.draw_png("enemy/armored/back.png", enemy[i].x, enemy[i].y, ENEMY_sizeX, ENEMY_sizeY);
							break;
						case 'd' :
							w.draw_png("enemy/armored/front.png", enemy[i].x, enemy[i].y, ENEMY_sizeX, ENEMY_sizeY);
							break;
					}
				break;
	
				case DEMON:
				if(enemy[i].life < 1)
					w.draw_png("enemy/demon/dead.png", enemy[i].x, enemy[i].y, ENEMY_sizeX, ENEMY_sizeY-15);
				else
					switch (enemy[i].direction){
						case 'l' :
							w.draw_png("enemy/demon/left.png", enemy[i].x, enemy[i].y, ENEMY_sizeX, ENEMY_sizeY);
							break;
						case 'r' :
							w.draw_png("enemy/demon/right.png", enemy[i].x, enemy[i].y, ENEMY_sizeX, ENEMY_sizeY);
						
							break;
						case 'u' :
							w.draw_png("enemy/demon/back.png", enemy[i].x, enemy[i].y, ENEMY_sizeX, ENEMY_sizeY);
							break;
						case 'd' :
							w.draw_png("enemy/demon/front.png", enemy[i].x, enemy[i].y, ENEMY_sizeX, ENEMY_sizeY);
							break;
					}
				break;				
			} 
		}
}

bool checkRange(ENEMY &enemy,TOWER &tower){ 
	float distance = sqrt( pow((tower.x - (enemy.x + ENEMY_sizeX/2)), 2) + pow((tower.y - (enemy.y + ENEMY_sizeY/2)), 2) );
	if(distance > TOWER_RANGE)
		return false;
	else
		return true;
}

BULLET initializeBullets(TOWER &tower){
	BULLET bullet;
	bullet.tower= &tower;
	bullet.x=tower.x;
	bullet.y=tower.y;
	bullet.enemy = new ENEMY;
	bullet.enemy->x = -1;
	bullet.enemy->y = -1;
	bullet.enemy->life=-100;
	return bullet;
}

void initializeBulletsEnemy(BULLET &bullet, vector<ENEMY> &theEnemies){
	for(int j=0;j<theEnemies.size();j++){
		if( checkRange(theEnemies[j], *(bullet.tower)) )
		{
			bullet.enemy = &theEnemies[j];
			return;
		}
	}
}

bool moveBullet(BULLET &bullet, PLAYER &player){
	bool hit=false;
	float goalX= bullet.enemy->x + ENEMY_sizeX/2;
	float goalY= bullet.enemy->y + ENEMY_sizeY/2;
	float preX= bullet.x;
	float preY= bullet.y;
	float rangeX= ENEMY_sizeX/2 ;
	float rangeY= ENEMY_sizeY/2 ;
	float distance = sqrt(pow(goalX-bullet.x,2) +pow(goalY-bullet.y,2));

	bullet.x += ( ((goalX-bullet.x)/distance) *BULLET_VELOCITY );
	bullet.y += ( ((goalY-bullet.y)/distance) *BULLET_VELOCITY );
	bullet.angle=atan((goalY-bullet.y)/(goalX-bullet.x))*180 / 3.14 + 90;
	
	if( bullet.x < goalX + rangeX && bullet.x > goalX - rangeX && bullet.y < goalY + rangeY && bullet.y > goalY - rangeY){
		if(bullet.tower->magical && bullet.enemy->magicArmor)
			bullet.enemy->life-=bullet.tower->damage/2;
		else if(bullet.tower->physical && bullet.enemy->physicalArmor)
			bullet.enemy->life-=bullet.tower->damage/2;
		else
			bullet.enemy->life-=bullet.tower->damage;
		hit=true;
	}
	if(bullet.enemy->life <= 0){
		player.money += bullet.enemy->prize;
		bullet=initializeBullets(*(bullet.tower));
	}

	return hit;
}

void drawBullet(Window &w,vector<BULLET> &theBullets){
	for(int i=0;i<theBullets.size();i++){
		int xBullet= theBullets[i].x-BULLET_SIZEX/2;
		int yBullet= theBullets[i].y-BULLET_SIZEY/2;
		if(theBullets[i].enemy->life != -100) {
			w.draw_png("bullet.png",xBullet,yBullet,BULLET_SIZEX,BULLET_SIZEY,theBullets[i].angle);
		}
	}
}	


void writeLifeMoney(Window &w,PLAYER &player){
	string life = to_string(player.life);
	string money = to_string(player.money);
	w.show_text("Lives:", 20, 5, RED, "OpenSans.ttf", 30);
	w.show_text(life, 105, 5, RED, "OpenSans.ttf", 30);

	w.show_text("Money:", 20, 35, YELLOW, "OpenSans.ttf", 30);
	w.show_text(money, 130, 35, YELLOW, "OpenSans.ttf", 30);
}