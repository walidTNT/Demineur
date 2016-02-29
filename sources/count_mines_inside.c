#include "table.h"

void	count_mines_inside(int nb_rows,int nb_columns, Case cases[nb_rows][nb_columns])
{
	int i;
	int j;
	int count;
	  
	for (i = 1; i < nb_rows - 1; i++)
    {
        for(j = 1; j < nb_columns - 1; j++)
        {
        	count = 0;
        	if(cases[i - 1][j - 1].mine == - 1)
        		count++;
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
        	if(cases[i + 1][j - 1].mine == - 1)
        		count++;
        	if(cases[i][j - 1].mine == - 1)
        		count++;
        	cases[i][j].nb_mines = count;	
        }
    }
}