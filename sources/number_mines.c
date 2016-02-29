#include <math.h> //floor
#include "table.h"

//Calcul du nombre de mines dans la table
int 	number_mines(int nb_rows, int nb_columns)
{
	int nb_cases;
	int nb_mines;
	
	nb_cases = number_cases(nb_rows, nb_columns);
	nb_mines = floor(nb_cases / 10);
	return (nb_mines);
}