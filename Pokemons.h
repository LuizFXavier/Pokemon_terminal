#ifndef POKEMONS_H
#define POKEMONS_H

#include <time.h>

class Pokemons
{
	public:
		Pokemons(int espec);
		void statuslevel(int nivel);
		
		char nespecie[20];
		int especie;
		char apelido[20];
		int tipo;
		char ntipo[20];
		int level;
		
		int defesa = 0;
		int ataque = 0;
		int spatk = 0;
		int spdef = 0;
		int velocity = 0;
		int hpmax = 0;
		
		int mdef;
		int matk;
		int mspatk;
		int mspdef;
		int mvel;
		int mhp;
};

Pokemons::Pokemons(int espec){
	
	int k,l;
	
	struct pkm{
		char bulba[20] = "Bulbassauro";
		char caterp[20] = "Caterpie";
	}nomespec;
	
	struct tipos{
		int grama = 1;
		int inseto = 4;
		char ngrama[15] = "grama";
		char ninseto[15] = "inseto";
	}tp;
	
	
	switch(espec){
		case 1:
			especie = espec;
		
			for(k=0; k<20; k++)
				nespecie[k] = nomespec.bulba[k];
			
			tipo = tp.grama;
			for(k=0; k<15; k++)
				ntipo[k] = tp.ngrama[k];
			
			break;
		
		case 10:
			especie = espec;
		
			for(k=0; k<20; k++)
				nespecie[k] = nomespec.caterp[k];
			
			tipo = tp.grama;
			for(k=0; k<15; k++)
				ntipo[k] = tp.ninseto[k];
			
			break;
	}
	
	
}

void Pokemons::statuslevel(int nivel){
	
	int lv = nivel;
	int t;
	int aumento[6];
	
	srand(time(NULL));
	
	while(lv > 0){
		
		for(t=0; t<6; t++)
			aumento[t] = (rand() % 4);
			
		defesa += aumento[0];
		ataque += aumento[1];
		spatk += aumento[2];
		spdef += aumento[3];
		velocity  += aumento[4];
		hpmax  += aumento[5];
		
		lv--;
	}
	
	switch(tipo){
		case 1:
			spatk += 2;
			spdef += 3;
			break;
		
	}
}
#endif
