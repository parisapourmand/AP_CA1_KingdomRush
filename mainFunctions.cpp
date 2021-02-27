#include "mainFunctions.hpp"
using namespace std;

bool playLevels(Window &w, int level)
{
	time_t start_time;
	time(&start_time);

	PLAYER player;
	player.life = INITIAL_LIFE;
	player.money = INITIAL_MONEY;

	bool theSlots[8];
	for(int i=0;i<8;i++)
		theSlots[i]=0;
	vector<int> thePointsX;
	vector<int> thePointsY;
	if(level==1)
		initializePointsOne(thePointsX,thePointsY);
	else
		initializePointsTwo(thePointsX,thePointsY);

	vector<ATTACK> theAttacks;
	initializeAttack(theAttacks,level);

	vector<ENEMY> theEnemies;
	for(int x=0;x<theAttacks.size();x++)
		for(int y=0;y<theAttacks[x].number;y++)
			theEnemies.push_back(initializeEnemy(theAttacks[x]));
	for(int m=0;m<theEnemies.size();m++){
		int random= m % 5;
		if(level==1){
			theEnemies[m].x = START_1X - ENEMY_sizeX;
			theEnemies[m].y = START_1Y - ENEMY_sizeY;
			theEnemies[m].x+=40*random;
			theEnemies[m].y+=10*random;
		}
		else{
			theEnemies[m].x = START_2X - ENEMY_sizeX;
			theEnemies[m].y = START_2Y - ENEMY_sizeY;		
			theEnemies[m].x+=10*random;
			theEnemies[m].y+=40*random;
		}
	}

	vector<TOWER> theTowers;
	vector<BULLET> theBullets;

	Event event = w.pollForEvent();
	int counter= 0;
	while(event.type() != QUIT){
		if(level==1)
			w.draw_bg("levels/level1-map.png",0,0);
		else
			w.draw_bg("levels/level2-map.png",0,0);
		if(event.type() == LCLICK){	
			int pressX = event.mouseX();
			int pressY = event.mouseY();
			int slotNum;
			if(level==1)
				slotNum =checkPointOne(pressX,pressY,theSlots);
			else
				slotNum =checkPointTwo(pressX,pressY,theSlots);				
			if(slotNum!=-1)
			{
				do {
					event = w.pollForEvent();
					if (event.type() == KEY_PRESS){
						if(checkMoney(event.pressedKey(),pressX,pressY,player)) {
							TOWER temp=initializeTower(pressX,pressY,event.pressedKey());
							theTowers.push_back(temp);
							theSlots[slotNum]=1;
						}
						break;
					}
				}while(event.type() != QUIT);
			}
		}
		for(int z = 0; z < theBullets.size(); z++)
		{	
			if(theBullets[z].enemy->life<1)
			{
				 if(theBullets[z].enemy->life == -100)
					initializeBulletsEnemy(theBullets[z], theEnemies);
				else
				{
					theBullets.erase(theBullets.begin()+z);
					z--;
				}
			}
			else
			{
				bool hit=moveBullet(theBullets[z], player);
				if(hit){
					theBullets.erase(theBullets.begin()+z);
					z--;
				}
			}					
		}
		for(int j=0;j<theEnemies.size();j++)	
		{
			if(theEnemies[j].life <=0 )
			{
				theEnemies.erase(theEnemies.begin()+j);
				j--;
			}	
		}
		for(int j=0;j<theEnemies.size();j++){
			theEnemies[j].direction= moveEnemy(theEnemies[j],thePointsX,thePointsY,start_time);
			if(theEnemies[j].count > thePointsX.size()-1 ){
				player.life-= theEnemies[j].power;
				theEnemies.erase(theEnemies.begin()+j);
				j--;
			}
			if(player.life<1)
				return false;
		}
			if(theEnemies.size()<1)
				return true;
		drawTower(w, theTowers);				
		drawEnemy(w, theEnemies);
		drawBullet(w, theBullets);
		writeLifeMoney(w,player);
		w.update_screen();
		usleep(10000);
		event = w.pollForEvent(); 

		for(int n = 0; n < theTowers.size(); n++)
			if(counter % (theTowers[n].delay/10) == 0)
				theBullets.push_back(initializeBullets(theTowers[n]));
		counter++;
	}
	exit(0);
}



bool losePage(Window &w){
	Event event = w.pollForEvent();
	while(event.type() != QUIT){
		w.draw_bg("bg/lose.png",0,0);
		w.draw_png("bg/playAgain.png", 250, 550, 300, 80);
		event = w.pollForEvent();
		if (event.type() == QUIT)
			exit(0);
		if (event.type()==LCLICK)
		{				
			if ( (event.mouseX()<550 && event.mouseX()>250) &&  (event.mouseY()<630 && event.mouseY()>550) )
				return true;
		}
		w.update_screen();
		Delay(1);
	}
	exit(0);
}

bool winPage(Window &w){
	Event event = w.pollForEvent();
	while(event.type() != QUIT){
		w.draw_bg("bg/win.png",0,0);
		w.draw_png("bg/playAgain.png", 250, 550, 300, 80);
		event = w.pollForEvent();
		if (event.type() == QUIT)
			exit(0);
		if (event.type()==LCLICK)
		{				
			if ( (event.mouseX()<550 && event.mouseX()>250) &&  (event.mouseY()<630 && event.mouseY()>550) )
				return true;
		}
		w.update_screen();
		Delay(1);
	}
	exit(0);
}