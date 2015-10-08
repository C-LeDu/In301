#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct Tableau {
	int taille;
	int tab[100];
};

int alea (int n) {
	int a; 
	a= rand()%(n+1);
	return a;
}

struct Tableau init (struct Tableau Tab){ 
	int i;
	Tab.taille = 10;
	for (i=0; i<=(Tab.taille-1) ; i++) {
		Tab.tab[i]= alea(20);
	}
	return Tab;
}

void affiche (struct Tableau Tab){ //affiche ce que contient le tableau
	int i; 
	for (i=0; i<=(Tab.taille-1) ; i++) {
		printf("La case %d du Tableau contient %d \n",i,Tab.tab[i]);
	}
}

int produit (struct Tableau Tab) {
	int i,prod;
	prod =1; 
	for (i=0; i<=(Tab.taille-1) ; i++) {
		prod=prod*Tab.tab[i];
	}
	return prod;
}

int mini (struct Tableau Tab) {
	int i, min;
	min = Tab.tab[0];
	for (i=1; i<=(Tab.taille-1) ; i++) {
		if (Tab.tab[i]<min) {
			min= Tab.tab[i];
		}
	}
	return min;
}

struct Tableau decalage_droite (struct Tableau Tab){
	Tab.taille = Tab.taille +1;
	int i; 
	for (i=(Tab.taille-1);i>=1; i--){
		Tab.tab[i] = Tab.tab[i-1];
	}
	Tab.tab[0] = 0;
	return Tab;
}

struct Tableau tri (struct Tableau Tab){
	int i,j, min;
	min =Tab.tab[0];
	for (i=0; i<Tab.taille; i++){
		//finir à partir de la
	}
}

int main () {
	
	printf ("la taille d'un struct Tableau est %d \n \n", sizeof (struct Tableau));
	srand(time(NULL));
	
	struct Tableau T;
	T = init (T);
	affiche(T);
	printf("\nLe produit des elm du Tableau vaut %d \n", produit(T));
	printf("La valeur minimum du Tableau vaut %d \n", mini(T));
	T = decalage_droite (T);
	affiche(T);
	return 0;
}
