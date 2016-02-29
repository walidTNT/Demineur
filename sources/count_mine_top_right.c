#include "table.h"

//RIGHT ROW BORDER
void	count_mine_top_right(int nb_rows, int nb_columns, Case cases[nb_rows][nb_columns])
{
	int i;
	int j;
	int count;
	  
	count = 0; 
	i = 0;
	j = nb_columns - 1;
    if(cases[i + 1][j].mine == - 1)
    	count++;
    if(cases[i + 1][j - 1].mine == - 1)
        count++;
    if(cases[i][j - 1].mine == - 1)
        count++;
    cases[i][j].nb_mines = count;
}