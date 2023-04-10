#ifndef EVENTOS_H
#define EVENTOS_H

#include <conio2.h>

#include "Cenas.h"
#include "Trainers.h"

class Eventos:public Cenas
{
	public:
		
		int proxima, plinha;
		
		void interaction(int px, int py, int cena, int mapa[16][16]);
		void eventomapa(int px, int py, int cena, int mapa[16][16]);
		
		bool mudarCena(int px, int py, int cena, int mapa[16][16]);
		void texto(char escrevido[200]);
};

void Eventos::interaction(int px, int py, int cena, int mapa[16][16]){
	
	int cima = px-1;
	int baixo = px+1;
	int direito = py+1;
	int esquerda = py-1;
	
	struct textos{
		
		char ec = 136, eh = 130, ah = 160, an = 198, ced = 135, oh = 162, nm = 157;
		
		char ligarPC[200] = " \t ligou o PC.\0";
		
		char maefala1[200] = " Vai no laboratório pra pegar o teu inicial.";
		char placasa[200] = " O cara não sabe onde é a própria casa.";
		
		char placaRival[200] = " Casa do inimigo.";
		
		char segredo[200] = " Segredo gigatonico.";
		
	}txt;
	
//	txt.ligarPC[1] = txt.nm;
	txt.maefala1[15] = txt.oh;
	
	txt.placasa[9] = txt.an;
	txt.placasa[22] = txt.eh;
	txt.placasa[28] = txt.oh;
	
	switch(cena){
		
		case 0:
			if(px == 1 && esquerda == 1){
				texto(txt.ligarPC);
				
			}
			break;
			
		case 1:
			if( (px == 3 && esquerda == 4) || (py == 4 && cima == 3) || (py == 4 && baixo == 3)){
				texto(txt.maefala1);
				
			} else if( (px == 1 && esquerda == 1) || (py == 1 && cima == 1) ){
				texto(txt.segredo);
				
			}
			
			break;
		case 2:
			if(mapa[px][py-1] == 11 || mapa[px][py+1] == 11 || mapa[px+1][py] == 11 || mapa[px-1][py] == 11){
				texto(txt.placasa);
				
			}
			break;
		case 3:
			if(mapa[px][py-1] == 11 || mapa[px][py+1] == 11 || mapa[px+1][py] == 11 || mapa[px-1][py] == 11){
				texto(txt.placaRival);
				
			}
			break;
	}
	
}

void Eventos::texto(char escrevido[200]){
	
	int n1, n2, pula=1;
	
	int caixatext[6][52] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
						    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

	gotoxy(1,plinha);
	
	for(n1 = 0; n1 < 6; n1++){
		for(n2 = 0; n2 < 52; n2++){
			
			switch(caixatext[n1][n2]){
				case 1:
					textbackground(DARKGRAY);
					cprintf(" ");
					break;
				
				case 0:
					textbackground(LIGHTGRAY);
					cprintf(" ");
					break;
			}
		}
		printf("\n");
	}
	
	gotoxy(2,plinha+pula);
	n1 = 0;
	n2 = 0;
	textbackground(LIGHTGRAY);
	textcolor(BLACK);
	
	while(escrevido[n1] != '\0'){
		if(escrevido[n1] == '\n'){
				pula++;
				gotoxy(2,plinha+pula);
				n1++;
		}
		else if(escrevido[n1] == '\t'){
			while(nome[n2] != '\0'){
				printf("%c",nome[n2]);
				Sleep(30);
				n2++;
			}
			n2=0;
			n1++;
		}
		Sleep(30);
		printf("%c",escrevido[n1]);
		n1++;
			
	}
	getch();
	
}

bool Eventos::mudarCena(int px, int py, int cena, int mapa[16][16]){
	
	switch(cena){
		case 0:
			
			if(px == 0){
				proxima = 1;
				
				return 1;
			}
			break;
			
		case 1:
			
			if(px == 0){
				proxima = 0;
				
				return 1;
			
			}else if(px == 5){
				proxima = 2;
				
				return 1;
			}
			break;
		
		case 2:
			
			if(px == 5 && py == 5){
				proxima = 1;
				
				return 1;
				
			}else if(py == 11){
				proxima = 3;
				
				return 1;	
			
			}else if(px == 8){
				proxima = 7;
				
				return 1;
			
			}else if(px == 0){
				proxima = 9;
				
				return 1;
			}
			 
			break;
			
		case 3:
			
			if(py == 0){
				proxima = 2;
				
				return 1;
			
			}else if(px == 5 && py == 6){
				proxima = 4;
				
				return 1;
				
			} else if(px == 8){
				proxima = 6;
				
				return 1;
				
			} else if(px == 0){
				proxima = 9;
				
				return 1;
			}
			break;
			
		case 4:
			
			if(px == 0){
				proxima = 5;
				
				return 1;
			
			}else if(px == 5){
				proxima = 3;
				
				return 1;
			}
		case 5:
			
			if(px == 0){
				proxima = 4;
				
				return 1;
			}
			break;
			
		case 6:
			
			if(px == 0){
				proxima = 3;
				
				return 1;
				
			} else if(py == 0){
				proxima = 7;
				
				return 1;
			}
			break;
		
		case 7:
			
			if(px == 0){
				proxima = 2;
				
				return 1;
				
			} else if(py == 11){
				proxima = 6;
				
				return 1;
				
			} else if(px == 6 && py == 4){
				proxima = 8;
				
				return 1;
			}
			break;
			
		case 8:
			
			if(px == 7){
				proxima = 7;
				
				return 1;
			}
			break;
		
		case 9:
			
			if(px == 8){
				
				if(py == 5 || py == 6)
					proxima = 2;
					
				else if(py == 7 || py == 8)
					proxima = 3;
					
				return 1;
			}
	}
}

void Eventos::eventomapa(int px, int py, int cena, int mapa[16][16]){
	
	char solo[200] = "Parado ai";
	
	switch(cena){
		
		case 9:
			if(partyn == 0 && px == 3){
				
				texto(solo);
				
			}
		break;
	}
}

#endif
