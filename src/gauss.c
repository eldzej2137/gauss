#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

/*
// Dopiszę dwie funkcje: na obliczanie wyznacznika i na sprawdzenie,
// czy wszystko pod główną przekątną jest zerem.

// Ta funkcja oblicza wyznacznik w sposób rekurencyjny:
// na podst. rozwinięcia Laplace'a i metody Sarrusa dla macierzy 3x3.
int det(Matrix *mat){
	if (mat->r!=mat->c)
		return NULL;
	else {
		int w=0;
		int wymiar=mat->r;
		double **dane=mat->dane;
		if (wymiar==3){
			w+=dane[0][0]*dane[1][1]*dane[2][2];
			w+=dane[0][1]*dane[1][2]*dane[2][0];
			w+=dane[0][2]*dane[1][0]*dane[2][1];
			w-=dane[2][0]*dane[1][1]*dane[0][2];
			w-=dane[2][1]*dane[1][2]*dane[0][0];
			w-=dane[2][2]*dane[1][0]*dane[0][1];
		}
		else {
			Matrix *minor=createMatrix(wymiar-1,wymiar-1);
			int i,j;
			// muszę napisać funkcję w mat_io do 'elementu głównego'
			// bo tutaj się przyda
			// narazie założę, że macierz jest ustawiona dobrze
			for (i=1;i<wymiar;i++){
				if (dane[i][0]!=0){
					for (j=0;j<wymiar;j++)
						dane[i][j]-=dane[0][j]*(dane[i][0]/dane[0][0]);
				}
			}
			for (i=0;i<wymiar-1;i++){
				for (j=0;j<wymiar-1;j++)
					minor->dane[i][j]=dane[i+1][j+1];
			}
			return dane[0][0]*det(minor);
		}
	}
}
*/

int eliminate(Matrix *mat, Matrix *b){
    /**
  	 * Tutaj należy umieścić właściwą implemntację.
		 */
	
		return 0;
}

