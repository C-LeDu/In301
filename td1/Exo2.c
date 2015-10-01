#include <stdio.h>

int main () {
	int seconde_init, seconde, heure, minute;
	printf ("Votre temps en secondes ?");
	scanf ("%d", &seconde_init );
	heure = seconde_init /3600;
	minute = (seconde_init %3600)/60;
	seconde = (seconde_init %3600)%60;
	printf ("%d est égal à %d heure %d minute %d seconde", seconde_init, heure, minute, seconde);
	return 0;
}
