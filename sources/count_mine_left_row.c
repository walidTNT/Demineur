#include "table.h"

void	count_mine_left_row(int nb_rows, int nb_columns, Case cases[nb_rows][nb_columns])
{
	int i;
	int j;
	int count;
	
    for(i = 1; i < nb_rows - 1; i++)
    {
    	count = 0;
    	if(cases[i - 1][j].mine == - 1)
        	count++;
        if(cases[i - 1][j + 1].mine == - 1)
        	count++;
       	if(cases[i][j + 1].mine == - 1)
        	count++;
        if(cases[i + 1][j + 1].mine == - 1)
        	count++;
    	if(cases[i + 1][j].mine == - 1)
        	count++;	
    	cases[i][j].nb_mines = count;
    }
}