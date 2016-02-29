#include "table.h"

//Initialization de la table et placement des mines 
void 	initialize_table(int nb_rows, int nb_columns, Booleen show)
{
	int nb_mines;
	Case cases[nb_rows][nb_columns];
    int i;
    int j;
    
    nb_mines = number_mines(nb_rows, nb_columns);
    for (i = 0; i < nb_rows; i++)
    {
        for(j = 0; j < nb_columns; j++)
        {    	
        	cases[i][j].decouverte = 0;
            cases[i][j].mine = 0;
            cases[i][j].nb_mines = 0;
            cases[i][j].drapeau = 0;
        }
            
    }
    put_mines(nb_rows, nb_columns, cases);
    count_mines(nb_rows, nb_columns, cases);
    show_table(nb_rows, nb_columns, cases, show);
}