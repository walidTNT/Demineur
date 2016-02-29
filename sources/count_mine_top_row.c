#include "table.h"

//TOP ROW BORDER
void	count_mine_top_row(int nb_rows, int nb_columns, Case cases[nb_rows][nb_columns])
{
	int i;
	int j;
	int count;		
    	for(j = 1; j < nb_columns - 1; j++)
    	{
    		count = 0;
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