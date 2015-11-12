#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*************  Constantes   *****************************/
#define NbPriorite 10    //nombre total de priorités
#define Nmax       8    //nombre de requêtes générées


/**************  Définition des structures ***************/

struct requete{
  int numero;    // numéro de la requête
  int priorite;  // priorité de la requête
};
typedef struct requete Requete;



/* Définir ici la structure Fap1 et Fap2 */

struct fap1 {
	Requete req;			
	struct fap1* suivant;
};
typedef struct fap1* Fap1;

struct fap2 {
	Fap1 T[NbPriorite];
};
typedef struct fap2 Fap2;



/**************  Fonctions de manipulation des structures *******/

// file initialisée vide
Fap1 initialiseFile1(){
	return NULL;	
}

// file initialisée vide
Fap2 initialiseFile2(){
	Fap2 file2;
	int i;
	for (i=0; i<NbPriorite ; i++){
		file2.T[i] = initialiseFile1();
	}
	return file2;
}

void afficheFile1(Fap1 f){
	if (f==NULL) printf ("Liste de requete vide\n\n");
	else {
		printf(" La requete à %d pour numero et %d pour prioritée \n", f->req.numero, f->req.priorite);
		afficheFile1 (f->suivant);
	}
}


void afficheFile2(Fap2 f){
  /* à compléter */
}

int rechercheNumeroMax (Fap1 f) {
	int NumeroMax =0;
	if (f==NULL) return 1;
	while (f->suivant != NULL ){
		if ( f->req.numero>NumeroMax) NumeroMax =f->req.numero;
		f= f->suivant;
	}
	if( f->req.numero>NumeroMax) NumeroMax =f->req.numero;
	return NumeroMax;
}

Fap1 ajoutFile1(Fap1 f, Requete r){
    Fap1 tmp = f;
	Fap1 newr = malloc(sizeof(Fap1));
	if (f == NULL) {
		r.numero = 1;
		newr->req = r;
		newr->suivant = NULL;
		return newr;
	}
	while (f->suivant!=NULL &&f->suivant->req.priorite < r.priorite) {
		f = f->suivant;
	}
	r.numero = rechercheNumeroMax(tmp) +1;
	newr->req = r;
	newr->suivant = f->suivant;
	f->suivant = newr;
    return tmp;
}



Fap2 ajoutFile2(Fap2 f, Requete r){
  /* à compléter */
}


Fap1 traiteRequete1(Fap1 f){
	if (f == NULL || f->suivant == NULL) return NULL;
	if (f->suivant ->suivant == NULL) {
		free(f->suivant ->suivant);
		f->suivant = NULL;	
		return f;
	}
	traiteRequete1 (f->suivant);
	return f;
}


Fap2 traiteRequete2(Fap2 f){
    /* à compléter */
}



void libereMemoire1(Fap1 f){
  if ( f != NULL) {
	  libereMemoire1(f->suivant);
	  free (f);
  }
}

void libereMemoire2(Fap2 f){
  /* à compléter */
}





/************** Génération des requêtes pour simulation *****************/

//retourne un entier aléatoire entre 0 et n-1
int alea(int n){
  return rand()%n;
}

Requete generationRequete(){
  static int numero = 0;
  Requete r;
  numero++;
  r.numero = numero;
  r.priorite = alea(NbPriorite);
  return r;
}



/************ Simulation file *****************************/


//structure 1
void simulationFile1(){
  Fap1 f1 = initialiseFile1();
  int compteur = 0;
  Requete r;
  while(compteur < Nmax){
    if(alea(2) == 0){ //traitement requête avec proba 0.5
      f1 = traiteRequete1(f1);
    }
    else{ //génération d'une nouvelle requête avec proba 0.5
      compteur++;
      r = generationRequete();
      f1 = ajoutFile1(f1, r);
    }
    afficheFile1(f1);
  }
  libereMemoire1(f1);
  printf("#######################################\n");
}


//structure 2
void simulationFile2(){
  Fap2 f2 = initialiseFile2();
  int compteur = 0;
  Requete r;
  while(compteur < Nmax){
    if(alea(2) == 0){ //traitement requête avec proba 0.5
      f2 = traiteRequete2(f2);
    }
    else{ //génération d'une nouvelle requête avec proba 0.5
      compteur++;
      r = generationRequete();
      f2 = ajoutFile2(f2, r);
    }
    afficheFile2(f2);
  }
  libereMemoire2(f2);
  printf("########################################\n");
}


/*************  Fonction main *******************************/

int main(){
  srand(time(NULL));

  /********  à décommenter pour lancer une simulation *********/
  simulationFile1();
    
  //simulationFile2();


  
  return 0;
}






