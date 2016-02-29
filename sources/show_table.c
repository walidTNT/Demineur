#include "table.h"

//Affichage de la table
void	show_table(int nb_rows, int nb_columns, Case cases[nb_rows][nb_columns], Booleen show)
{
	int i;
	int	j;
	
	if(show == TRUE)
    {
		for (i = 0; i < nb_rows; i++)
    	{
        	for(j = 0; j < nb_columns; j++)
        	{
            	if(cases[i][j].mine == -1)
        		{
        			my_putstr("| ");
            		my_put_nbr(cases[i][j].mine);
           			my_putstr(" ");
        		}
        		else
        		{
        			my_putstr("| ");
            		my_put_nbr(cases[i][j].nb_mines);
           			my_putstr("  ");
        		}
       		}
       		my_putstr("|");
        	my_putstr("\n");
    	}
    }
}