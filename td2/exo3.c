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

Liste ajout_début ( Liste l, int v){
	Element elt* = malloc(sizeof(Element));
	elt->val = v;
	elt->suivant = l;
	return elt;
}

int main () {
	
	return 0;
}
