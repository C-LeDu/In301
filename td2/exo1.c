#include <stdio.h>

void permute( int* p1, int* p2) {
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void reinitPointeur(int* p){
	p = NULL;
}

int main () {

printf ("taille de char %d \n", sizeof(char));
printf ("taille de int %d \n", sizeof(int));
printf ("taille de double %d \n", sizeof(double));
printf ("taille de char* %d \n", sizeof(char*));
printf ("taille de void* %d \n", sizeof(void*));
printf ("taille de int* %d \n", sizeof(int*));
printf ("taille de int** %d \n", sizeof(int**));
printf ("taille de int[10] %d \n", sizeof(int[10]));
printf ("taille de char[7][3] %d \n \n", sizeof(char[7][3]));
//printf ("taille de int[] %d \n", sizeof(int[]));

char tab[10];
printf ("taille de tab %d \n", sizeof(tab));
printf ("taille de tab[0] %d \n", sizeof(tab[0]));
printf ("taille de &tab[0] %d \n", sizeof(&tab[0]));
printf ("taille de *&tab %d \n", sizeof(*&tab));
printf ("taille de *&tab[0] %d \n \n", sizeof(*&tab[0]));

char (*p)[10] = &tab;
printf ("taille de p %d \n", sizeof(p));
printf ("taille de *p %d \n", sizeof(*p));
printf ("taille de (*p)[2] %d \n", sizeof((*p)[2]));
printf ("taille de &(*p)[2] %d \n \n", sizeof(&(*p)[2]));

int a = 4; int b =12;
printf ("les valeurs de a et b sont %d et %d \n",a,b);
permute(&a,&b);
printf ("les valeurs de a et b sont maintenant %d et %d \n \n",a,b);

int c = 1;
int* p2 = &c;
printf ("taille de *p2 %d \n", sizeof(*p2));
reinitPointeur(p2);
printf ("taille de *p2 %d \n \n", sizeof(*p2));
}
