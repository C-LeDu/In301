#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct Element {
	int val;
	struct Element* suivant;
};

typedef struct Element Element;
typedef Element* Liste;

Liste init_liste_vide () {
	return NULL;
}

int test_liste_vide (Liste l){
	if (l==NULL) return 1;
	else return 0;
}

void affiche_liste (Liste l) {
	if (test_liste_vide(l)) printf("Fin \n");
	else {
		printf ("%d ", l->val);
		affiche_liste( l->suivant);
	}
}

Liste ajout_debut (Liste l, int v){
	Element* elt = malloc(sizeof(Element));
	elt->val = v;
	elt->suivant = l;
	return elt;
}

Liste ajout_fin (Liste l, int v) {
	Liste tmp = l;
	Element* elt = malloc(sizeof(Element));
	elt->val = v;
	elt->suivant = NULL;
	if (l==NULL) return elt;
	while (l->suivant !=NULL) l = l->suivant;
	l->suivant = elt;
	return tmp;
}

Liste ajout_fin_recursif (Liste l, int v) {
	if (test_liste_vide(l)) return ajout_debut(l,v);
	else {
		l->suivant = ajout_fin_recursif (l->suivant,v);
		return l;
	}
}

int test_trie (Liste l){
	if (l == NULL) return 1;
	if (l->val > (l->suivant)->val) return 0;
	else return test_trie(l->suivant);
}

Liste ajout_trie_recursif (Liste l, int v) {
	if (test_trie(l)) {
		if (test_liste_vide(l) || v<= l->val) return ajout_debut(l,v);
		l->suivant = ajout_trie_recursif (l->suivant,v);
		return l;
	}
	else return ajout_debut (l,v);
}

Liste ajout_trie(Liste l,int v) {
	if (test_trie (l)){
		Liste tmp = l;
		Element* elt = malloc(sizeof(Element));
		elt->val = v;
		if (l->val >= v) return ajout_debut (l,v); 			// le 1er element est inf
		while (l->suivant != NULL && (l->suivant)->val <v ) l = l->suivant;
		elt->suivant = l->suivant;
		l->suivant = elt;
		return tmp;
	}
	else return ajout_debut(l,v);
}

int alea (int n) {
	int a; 
	a= rand()%(n+1);
	return a;
}

Liste init_liste_alea_debut (Liste l, int n){
	int v;
	while ((v=alea (n))!= 0){
		l = ajout_debut (l,v);
	}
	return l ;
}

Liste init_liste_alea_fin (Liste l, int n) {
	int v;
	while ((v=alea (n))!= 0){
		l = ajout_fin_recursif (l,v);
	}
	return l ;
}

Liste init_liste_alea_trie (Liste l, int n) {
	int v;
	while ((v=alea (n))!= 0){
		l = ajout_trie (l,v);
	}
	return l ;
}

int main () {
	srand(time(NULL));
	Liste liste;
	liste= init_liste_vide ();
	liste = init_liste_alea_trie(liste, 20);
	affiche_liste (liste);
	return 0;
}
