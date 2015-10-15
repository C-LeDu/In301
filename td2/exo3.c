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

int test_trie (Liste l){
	if (l == NULL) return 1;
	if (l->val > (l->suivant)->val) return 0;
	else return test_trie(l->suivant);
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

int main () {
	Liste liste;
	liste = init_liste_vide();
	affiche_liste (liste);
	liste = ajout_debut(liste, 2);
	affiche_liste (liste);
	liste = ajout_fin (liste, 6);
	affiche_liste(liste);
	liste = ajout_trie (liste, 1);
	affiche_liste(liste);
	return 0;
}
