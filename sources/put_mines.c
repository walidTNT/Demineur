#include "table.h"

//Placement des mines
void 	put_mines(int nb_rows, int nb_columns, Case cases[nb_rows][nb_columns])
{
	int nb_mines;
	int m;
	int nb_c;
	int nb_l;
	int nb_a;
	int nb_b;
	
	nb_mines = number_mines(nb_rows, nb_columns);
	if (nb_mines != 0)
	{
		for(m = 0; m < nb_mines; m++)
    	{
    		nb_l = (int)(rand() % nb_rows);
    		nb_c = (int)(rand() % nb_columns);
    		if(cases[nb_l][nb_c].mine != -1) 
    		{ 
    			cases[nb_l][nb_c].mine = -1;
				cases[nb_l][nb_c].nb_mines = 1;
    		}
			else
			{
				nb_a = (int)(rand() % nb_rows);
    			nb_b = (int)(rand() % nb_columns);
    			if((nb_a!= nb_l) && (nb_b != nb_c))
    			{ 
    				cases[nb_l][nb_c].mine = -1;
					cases[nb_l][nb_c].nb_mines = 1;
    			}
			}
    	}
	}
}