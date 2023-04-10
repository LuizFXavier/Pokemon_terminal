#ifndef PLAYER_H
#define PLAYER_H

#include <conio2.h>
#include <windows.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_Z 122

class Player
{
	public:
		
		const int pixel = 1; 
		
		int posx = 1, posy = 9;
		bool gender = 0;
		int partyn = 0;
		char nome[11] = "benMassa";
		
		int controles(int mapa[16][16]);
};

int Player::controles(int mapa[16][16]){
	
	int c = 0;
	
	int cim = posx-1;
	int bax = posx+1;
	int dir = posy+1;
	int esq = posy-1;
	
	switch(c=getch()){
		
		case KEY_UP:
			if(posx-1 < 0 || mapa[posx-1][posy] == 5 || mapa[posx-1][posy] == 6 || mapa[posx-1][posy] == 7){
				
				printf("\a");
				return 0;
				
			}else{
				posx--;
				return 1;
			}
			
			break;
		
		case KEY_DOWN:
			if(mapa[posx+1][posy] == 5 || mapa[posx+1][posy] == 6 || mapa[posx+1][posy] == 7){
			
				printf("\a");
				return 0;
			
			}else{
				posx++;
				return 1;
			}	
			
			break;
		
		case KEY_LEFT:
			if(posy-1 < 0 || mapa[posx][posy-1] == 5 || mapa[posx][posy-1] == 6 || mapa[posx][posy-1] == 7){
			
				printf("\a");
				return 0;
			
			}else{
				posy--;
				return 1;
			}
			
			break;
			
		case KEY_RIGHT:
			if(mapa[posx][posy+1] == 5 || mapa[posx][posy+1] == 6 || mapa[posx][posy+1] == 7){
			
				printf("\a");
				return 0;
			
			}else{
				posy++;
				return 1;
			}
			
			break;
		
		case KEY_Z:
			return 2;
		
		default:
			return 0;
	}
}


#endif
