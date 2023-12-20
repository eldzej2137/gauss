#include "gauss.h"
#include <math.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int eliminate(Matrix *mat, Matrix *b){
    /**
  	 * Tutaj należy umieścić właściwą implemntację.
		 */
	int ir,ic,i;
	// tworzymy macierz rozszerzoną
	Matrix *ext = createMatrix(mat->r, mat->c+1);
	for (ir=0; ir<mat->r; ir++){
		for (ic=0; ic<mat->c; ic++)
			ext->data[ir][ic]=mat->data[ir][ic];
		ext->data[ir][mat->c]=b->data[ir][0];
	}
	int max_abs_index;
	for (i=0; i<ext->r-1; i++){
		// wybór elementu głównego (nie robimy tego w przedostatniej
		// kolumnie, bo w niej zostanie tylko jeden element)
		max_abs_index=i;
		for (ir=i+1; ir<ext->r; ir++){
			if (fabs(ext->data[ir][i])>fabs(ext->data[max_abs_index][i]))
				max_abs_index=ir;
		}
		// zamieniamy miejscami pierwszy wiersz z tym, który zawiera element główny
		double *tmp = malloc(ext->c*sizeof(double));
		if (max_abs_index!=i){
			for (ic=i; ic<ext->c; ic++){
				tmp[ic]=ext->data[i][ic];
				ext->data[i][ic]=ext->data[max_abs_index][ic];
				ext->data[max_abs_index][ic]=tmp[ic];
			}
		}
		free(tmp);
		// teraz od każdego wiersza odejmujemy górny przemnożony przez
		// odpowiednią wartość
		for (ir=i+1; ir<ext->r; ir++){
			for (ic=i; ic<ext->c; ic++){
				if (ext->data[i][i]!=0)
					ext->data[ir][ic]-=ext->data[i][ic]*ext->data[ir][i]/ext->data[i][i];
				else
					return 1;
			}
		}
	}
	// teraz zamieniamy wartości w macierzach wejściowych (mat, b)
	for (ir=0; ir<mat->r; ir++){
		for (ic=0; ic<mat->c; ic++)
			mat->data[ir][ic]=ext->data[ir][ic];
		b->data[ir][0]=ext->data[ir][mat->c];
	}
	
	return 0;
}

