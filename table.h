#ifndef _TABLE_H
#define _TABLE_H

typedef enum
{
		FALSE,
		TRUE
}		t_booleen;

typedef struct 
{
	int decouverte;
	int mine;
	int nb_mines;
	int drapeau;
	int affichage;
} 		t_case;

/*
int		number_cases(int nb_rows, int nb_columns);
int		number_mines(int nb_rows, int nb_columns);
void 	put_mines(int nb_rows, int nb_columns, Case *cases);
void 	count_mines(int nb_rows,int nb_columns, Case cases[nb_rows][nb_columns]);
void	show_table(int nb_rows, int nb_columns, Case *cases, Booleen show);
void 	initialize_table(int nb_rows, int nb_columns, Booleen show);
*/

#endif