#include "table.h"

void	count_mines_border(int nb_rows, int nb_columns, Case cases[nb_rows][nb_columns])
{
		count_mine_top_left(nb_rows, nb_columns, cases);
		count_mine_top_row(nb_rows, nb_columns, cases);
   	 	count_mine_top_right(nb_rows, nb_columns, cases);
   	 	count_mine_right_row(nb_rows, nb_columns, cases);
    	count_mine_bottom_left(nb_rows, nb_columns, cases);
    	count_mine_bottom_row(nb_rows, nb_columns, cases);
    	count_mine_bottom_right(nb_rows, nb_columns, cases);
    	count_mine_left_row(nb_rows, nb_columns, cases);
}