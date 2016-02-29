#include "table.h"

//Calcul nombre de cases de la table
int		number_cases(int nb_rows, int nb_columns)
{
	int	nb_cases;

	nb_cases = (nb_rows) * (nb_columns);
	return (nb_cases);
}