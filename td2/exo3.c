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
	if (l == NULL || l->suivant == NULL) return 1;
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

/*Liste ajout_trie(Liste l,int v) {
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
}*/

int alea (int n) {
	int a; 
	a= rand()%(n+1);
	return a;
}


void test_liste (int n) {
	Liste l1 = NULL;
	Liste l2 = NULL;
	Liste l3 = NULL;
	int v;
	while ((v=alea (n))!=0){
		l1 = ajout_debut (l1,v);
		l2 = ajout_fin (l2,v);
		l3 = ajout_trie_recursif (l3,v);
	}
	affiche_liste(l1);
	affiche_liste(l2);
	affiche_liste(l3);
}

Liste alea_liste (int n) {
	Liste l = init_liste_vide ();
	int v; 
	while ((v=alea (n))!=0){
		l = ajout_trie_recursif (l,v);
	}
	return l;
}

int nombre_element(Liste l) {
	if (test_liste_vide(l)) return 0;
	return 1+nombre_element(l->suivant);
}

int recherche_element (Liste l, int v) {
	while (l!=NULL) {
		if (l->val == v) return 1;
		l = l->suivant;
	}
	return 0;
}

/*Liste suppr_element (Liste l, int v) {  // ici on suprime uniquement le premier element de la liste egal a v
	Liste tmp = l;
	Liste suppr =init_liste_vide ();
	if (test_liste_vide(l) || recherche_element (l,v) ==0) return l;
	if (l->val ==v) {
		suppr = l;
		l = l->suivant;
		free (suppr);
		return l;
		}
	while (l->suivant->val != v) {
		l = l->suivant;
	}
	suppr = l->suivant;
	l->suivant = l->suivant->suivant;
	free (suppr);
	return tmp;
}*/

Liste suppr_element (Liste l,int v) { //ici on supprime TOUT les elmt de la liste egal à v
	Liste tmp;
	if (test_liste_vide (l)) return l;
	l->suivant = suppr_element (l->suivant, v);
	if ( l->val == v) {
		tmp = l->suivant;
		free (l);
		l=tmp;
	}
	return l;
}

Liste concat_liste (Liste l1, Liste l2) {
	Liste tmp = l1; 
	if (l1==NULL) return l2;
	while (l1->suivant != NULL) l1 = l1->suivant;
	l1->suivant = l2;
	return tmp;
}

/*Liste concat_liste (Liste l1, Liste l2) {
	if (test_liste_vie (l1)) return l2;
	l1->suivant = concat_liste (l1->suivant, l2);
	return l2;
  } */

Liste concat_liste_trie (Liste l1, Liste l2) {
	Liste tmp;
	if (test_trie (l1)) {
		while (l2!=NULL) {
			ajout_trie_recursif (l1, l2->val);
			tmp = l2;
			l2 = l2->suivant;
			free (tmp);
		}
	}
	return l1;
}

Liste tri_bulle (Liste l) {
	
}

int main () {
	srand(time(NULL));
	Liste liste = alea_liste (10);
	Liste liste2 = alea_liste(10);
	affiche_liste (liste);
	printf ( "La liste contient %d elements \n", nombre_element(liste));
	printf (  "La liste contient 9 = %d \n", recherche_element (liste, 9));
	liste = suppr_element (liste, 3);
	affiche_liste (liste);
	affiche_liste (liste2);
	printf ( "La liste contient %d elements \n", nombre_element(liste2));
	liste = concat_liste_trie (liste, liste2);
	affiche_liste (liste);
	printf ( "La liste contient %d elements \n", nombre_element(liste));
	return 0;
}
