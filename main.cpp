#include <iostream>

#include "Cenas.h"
#include "Eventos.h"
#include "Pokemons.h"
 
using namespace std;

int cenAtual = 0, cenAnt = 1;  

Cenas *mapa = new Cenas;   
Player *jogador = new Player;
Eventos *even = new Eventos;
Pokemons *bulbassauro = new Pokemons(1);
//Trainers *inseto = new Trainers(1,1);

int main(int argc, char** argv) { 
	
	bool troca = 0;
	int i, j; 
	      
	bulbassauro->statuslevel(100);
	
//	cout<<inseto->pkm[0].defesa<<endl<<inseto->pkm[0].ataque<<endl<<inseto->pkm[0].spatk<<endl<<inseto->pkm[0].spdef<<endl<<inseto->pkm[0].velocity<<endl<<inseto->pkm[0].hpmax;
	
//	cout<<endl<<endl<<endl<<inseto->pkm[1].defesa<<endl<<inseto->pkm[1].ataque<<endl<<inseto->pkm[1].spatk<<endl<<inseto->pkm[1].spdef<<endl<<inseto->pkm[1].velocity<<endl<<inseto->pkm[1].hpmax;
	getchar(); 
	
	mapa->setcenario(cenAtual);
	
	mapa->playerposition(cenAtual, cenAnt,troca);  
	
	mapa->posx = jogador->posx;   
	mapa->posy = jogador->posy;
	
	even->gender = jogador->gender;    
	
	while(1){      
		
		mapa->setcenario(cenAtual);
		
		even->plinha = mapa->final;  
	 	
		mapa->playerposition(cenAtual, cenAnt, troca);             
		troca = 0;
		
		jogador->posx = mapa->posx;   
		jogador->posy = mapa->posy;
		
		mapa->imprimir(); 
		  
		movimento:    
		
		switch(jogador->controles(mapa->cenario)){  
			case 1:
				textbackground(BLACK);
				system("cls");
				break;	
			
			case 2:
				even->interaction(jogador->posx, jogador->posy, cenAtual, mapa->cenario); 
				textbackground(BLACK);
				system("cls");
				
				break;
				
			default:     
				goto movimento;
				break;
		}
		
		
		mapa->posx = jogador->posx;
	 	mapa->posy = jogador->posy; 
		
		if(even->mudarCena(jogador->posx, jogador->posy, cenAtual, mapa->cenario)){
			troca = 1;
			cenAnt = cenAtual;
			cenAtual = even->proxima;
		}
		even->eventomapa(jogador->posx, jogador->posy, cenAtual, mapa->cenario);
		
	}
	return 0;
}

void inicio(){
	
	char initxt[200] = " Tens uns pokemon nO MUNDO, tu tem que pegar todos.\n\n Tu é uma [0]fêmea ou um [1]macho?";
	char pnome[200] = "E qual o teu nome? (max10): ";
	
even->plinha = 1;
even->texto(initxt);

cin>>even->gender;

even->texto(pnome);

cin>>even->nome;
	
if(even->gender == 0){
	cenAtual = 5;
}else{
	cenAtual = 0;
}	
}
