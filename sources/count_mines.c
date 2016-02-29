#include "table.h"

void 	count_mines(int nb_rows,int nb_columns, Case cases[nb_rows][nb_columns])
{
    	count_mines_inside(nb_rows, nb_columns, cases);
    	count_mines_border(nb_rows, nb_columns, cases);
}