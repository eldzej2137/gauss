#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b)
{

	int i, j;
	double x_val;
	// offset is a counter of how many subtractions should be made
	int offset = 0;
	for (i = x->r - 1; i >= 0; i--)
	{
		x_val = 0;
		// doing <offset> subtractions of elements with higher column index than current row
		for (j = i + offset; j > i; j--)
		{
			x_val -= x->data[j][0] * mat->data[i][j];
		}
		// evaluating x by first adding b value of corresponding x and then dividing over element in diagonal
		x_val += b->data[i][0];
		x_val /= mat->data[i][i];
		x->data[i][0] = x_val;
		// with each next x found, offset should be increased by 1
		offset++;
	}

	return 0;
}
