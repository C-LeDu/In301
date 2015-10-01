#include <stdio.h>

int main () {
	int x, y, z, res;
	z =0;
	printf (" Que vaut X? \n " );
	scanf ("%d", &x);
	printf (" Que vaut Y? \n " );
	scanf ("%d", &y);
	
	while (x!= 1) {
		if (x%2 ==0) {
			x = x/2; y = 2*y;
		}
		else {
			x = x-1; z = z+y;
		}
	} 
	res = y +z;
	printf ("le resultat vaut %d \n", res );
}
