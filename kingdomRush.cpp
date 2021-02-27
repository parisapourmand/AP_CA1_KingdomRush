#include "mainFunctions.hpp"
#include "rsdl.hpp"
#include <iostream>
using namespace std;

int main()
{
	Window w(800,800,"Kingdom Rush");
	Event event = w.pollForEvent();
	while(event.type() != QUIT){
		bool play = false;
		while(!play){
			w.draw_bg("bg/kingdomRush.png",0,0);
			w.draw_png("bg/play.png", 200, 600, 400, 80);
			event = w.pollForEvent();
			if (event.type() == QUIT)
				return 0;
			if (event.type()==LCLICK)
			{				
				if ( (event.mouseX()<570 && event.mouseX()>240) &&  (event.mouseY()<680 && event.mouseY()>600) )
					play=true;
			}
			w.update_screen();
			Delay(1);
		}
		if (playLevels(w,1)){
			if(playLevels(w,2))
				if(winPage(w))
					play=true;
			else
				if(losePage(w))
					play = true;
		}		
		else {
			event = w.pollForEvent();
			if(losePage(w))
				play = true;
		}
	}
	return 0;
}