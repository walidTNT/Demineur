#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "table.h"

//libmy
void	my_putchar(char c)
{
  write(1, &c, 1);
}
int     my_putstr(char *str)
{
  int 	i;

  for (i = 0; str[i] != '\0'; ++i)
    my_putchar(str[i]);
  return (0);
}
int		my_isneg(int chiffre)
 {
   if (chiffre >= 0)
     my_putchar('P');
   else
     my_putchar('N');
   return (0);
}
int     my_intlen(int nb)
{
  int 	c;
  int 	div;

  div = 10;
  c = 1;

  while (nb / div != 0)
    {
      div *= 10;
      ++c;
    }

  return (c);
}
int		my_put_nbr(int nb)
{
  int 	nbel;
  char	*tab;
  int 	i;

  if (nb < 0)
    {
      my_putchar('-');
      nb *= -1;
    }
   nbel = my_intlen(nb);
   tab = malloc(nbel * sizeof(*tab));
   if (tab == NULL)
    return (0);
   --nbel;
   for (i = nbel; i >= 0; --i)
     {
       tab[i] = '0' + (nb % 10);
       nb = (nb - (nb % 10)) / 10;
     }
   for (i = 0; i <= nbel; ++i)
     my_putchar(tab[i]);   
   return (0);
}
char	*readLine()
{
		ssize_t  ret;
        char     *buff;

        if ((buff = malloc(sizeof(*buff) * (50 + 1))) == NULL)
            return (NULL);
        if ((ret = read(0, buff, 50)) > 1)
        {
            buff[ret - 1] = '\0';
            return (buff);
        }
        buff[0] = '\0';
        return (buff);
}

//Calcul nombre de cases de la table
int		number_cases(int nb_rows, int nb_columns)
{
	int	nb_cases;

	nb_cases = (nb_rows) * (nb_columns);
	return (nb_cases);
}

//Calcul du nombre de mines dans la table
int 	number_mines(int nb_rows, int nb_columns)
{
	int nb_cases;
	int nb_mines;
	
	nb_cases = number_cases(nb_rows, nb_columns);
	nb_mines = floor(nb_cases / 10);
	return (nb_mines);
}

//Placement des mines
void 	put_mines(int nb_rows, int nb_columns, t_case cases[nb_rows][nb_columns])
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

//Comptage des mines restants à découvrir
int		mines_left(int nb_rows,int nb_columns, t_case cases[nb_rows][nb_columns])
{
	int nb_mines;
	int nb_mines_tmp;
	int i;
	int	j;
	
	i = 0;
	j = 0;
	nb_mines = number_mines(nb_rows, nb_columns);
	nb_mines_tmp = nb_mines;
	if (nb_mines != 0)
	{
		for(i = 0; i < nb_mines; i++)
    	{
    		for(j = 0; j < nb_columns; j++)
    		{
    			if(cases[i][j].drapeau == 1)
    				nb_mines_tmp--;
    		}
    	}
    }
    return (nb_mines_tmp);
}

//Choix taille
int	choise_size()
{
	int nb;
		
	nb = atoi(readLine());
	return (nb);
}

//Mines autour d'une case, grille intérieure
void	count_mines_inside(int nb_rows,int nb_columns, t_case cases[nb_rows][nb_columns])
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
//TOP ROW BORDER
void	count_mine_top_left(int nb_rows, int nb_columns, t_case cases[nb_rows][nb_columns])
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
    count = 0;
    if(cases[i][j + 1].mine == - 1)
    	count++;
    if(cases[i + 1][j + 1].mine == - 1)
        count++;
    if(cases[i + 1][j].mine == - 1)
        count++;	
    cases[i][j].nb_mines = count;
}
void	count_mine_top_row(int nb_rows, int nb_columns, t_case cases[nb_rows][nb_columns])
{
	int i;
	int j;
	int count;
	
	i = 0;
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
//RIGHT ROW BORDER
void	count_mine_top_right(int nb_rows, int nb_columns, t_case cases[nb_rows][nb_columns])
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
void	count_mine_right_row(int nb_rows, int nb_columns, t_case cases[nb_rows][nb_columns])
{
	int i;
	int j;
	int count;
	
	j = nb_columns - 1;
    for(i = 1; i < nb_rows - 1; i++)
    {
    	count = 0;
    	if(cases[i + 1][j].mine == - 1)
        	count++;
        if(cases[i + 1][j - 1].mine == - 1)
        	count++;
       	if(cases[i][j - 1].mine == - 1)
        	count++;
        if(cases[i - 1][j - 1].mine == - 1)
        	count++;
        if(cases[i - 1][j].mine == - 1)
        	count++;
    	cases[i][j].nb_mines = count;
    }
}
//BOTTOM ROW BORDER
void	count_mine_bottom_right(int nb_rows, int nb_columns, t_case cases[nb_rows][nb_columns])
{
	int i;
	int j;
	int count;
	  
	count = 0; 
	i = nb_rows - 1;
	j = nb_columns - 1;
    if(cases[i][j - 1].mine == - 1)
       	count++;
    if(cases[i - 1][j - 1].mine == - 1)
       	count++;
    if(cases[i - 1][j].mine == - 1)
       	count++;	
    cases[i][j].nb_mines = count;
}	
void	count_mine_bottom_row(int nb_rows, int nb_columns, t_case cases[nb_rows][nb_columns])
{
	int i;
	int j;
	int count;
	
	i = nb_rows - 1;
    for(j = 1; j < nb_columns - 1; j++)
    {
    	count = 0;
       	if(cases[i][j - 1].mine == - 1)	
       		count++;
  		if(cases[i - 1][j - 1].mine == - 1)
   			count++;
       	if(cases[i - 1][j].mine == - 1)
     		count++;
       	if(cases[i - 1][j + 1].mine == - 1)
       		count++;
       	if(cases[i][j + 1].mine == - 1)
       		count++;
   		cases[i][j].nb_mines = count;
   	}
}
//LEFT ROW BORDER
void	count_mine_bottom_left(int nb_rows, int nb_columns, t_case cases[nb_rows][nb_columns])
{
	int i;
	int j;
	int count;
	  
	count = 0; 
	i = nb_rows - 1;
	j = 0;
   	if(cases[i - 1][j].mine == - 1)
      	count++;
    if(cases[i - 1][j + 1].mine == - 1)
        count++;
    if(cases[i][j + 1].mine == - 1)
        count++;	
    cases[i][j].nb_mines = count;
}
void	count_mine_left_row(int nb_rows, int nb_columns, t_case cases[nb_rows][nb_columns])
{
	int i;
	int j;
	int count;
	
	j = 0;
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

void	count_mines_border(int nb_rows, int nb_columns, t_case cases[nb_rows][nb_columns])
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

void 	count_mines(int nb_rows,int nb_columns, t_case cases[nb_rows][nb_columns])
{
    	count_mines_inside(nb_rows, nb_columns, cases);
    	count_mines_border(nb_rows, nb_columns, cases);
}

//Affichage de la table
void	show_table(int nb_rows, int nb_columns, t_case cases[nb_rows][nb_columns])
{
	int i;
	int	j;
	
		for (i = 0; i < nb_rows; i++)
    	{
        	for(j = 0; j < nb_columns; j++)
        	{
            	if(cases[i][j].decouverte == 1)
        		{
        			my_putstr("|   ");
            		my_put_nbr(cases[i][j].nb_mines);
           			my_putstr("   ");
        		}
        		else if(cases[i][j].drapeau == 1)
        		{
        			cases[i][j].affichage = 7;
        			my_putstr("|   ");
            		my_put_nbr(cases[i][j].affichage);
           			my_putstr("   ");
        		}
        		
        		else
        		{
        			my_putstr("|   ");
            		my_put_nbr(cases[i][j].affichage);
           			my_putstr("   ");
        		}
       		}
       		my_putstr("|");
        	my_putstr("\n");
    	}
}

//Choix de l'action du joueur
void	choise_action(int nb_rows,int nb_columns, t_case cases[nb_rows][nb_columns])
{
	int i;
	int j;
	int x;
	int m;
	
	m = mines_left(nb_rows, nb_columns, cases);
	while(m > 0)
	{
	x = 0;
	my_putstr("Choisir abscisse: ");
	i = choise_size();
	if (i == -1)
		exit(0);
	my_putstr("Choisir ordonnée: ");
	j = choise_size();
	if (j == -1)
		exit(0);
	if((i >= 0 && i <= nb_rows - 1) && (j >= 0 && j <= nb_columns - 1))
	{
		if(cases[i][j].mine == -1)
		{
			my_putstr("Vous avez perdu :(\n\n");
			exit(0);
		}
		else
		{
			cases[i][j].decouverte = 1;
			my_putstr("\n\n");
			my_putstr("Vous voulez poser un drapeau? (Oui = 1 Non = 2)");
			my_putstr("\n\n");
			x = choise_size();
			my_putstr("\n\n");
			if ( x == 1) 
			{
				cases[i][j].drapeau = 1;
				m--;
			}
			else if (x == -1)
				exit(0);
		}
		show_table(nb_rows, nb_columns, cases);
	}
	else
	{
		my_putstr("Vous avez dépassé les dimensions de la grille\n\n");
		//choise_action(nb_rows,nb_columns,cases[nb_rows][nb_columns]);
	}
	
	}
}

//Initialization de la table et placement des mines 
void	initialize_table(int nb_rows, int nb_columns, t_case cases[nb_rows][nb_columns])
{
	int nb_mines;
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
            cases[i][j].affichage = -9; 
        }     
    }
    put_mines(nb_rows, nb_columns, cases);
    cases[0][0].mine = 0;
    count_mines(nb_rows, nb_columns, cases);
}

//Affichage initial du jeu
void	init_game()
{
		my_putstr("\n\n");
		my_putstr("xxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		my_putstr("||	Démineur	||\n");
		my_putstr("xxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		my_putstr("\n\n");
		
		my_putstr("xxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		my_putstr("||	Etape 3		||\n");
		my_putstr("xxxxxxxxxxxxxxxxxxxxxxxxxx\n");	
		my_putstr("\n\n");
}

int 		main (void)
{
	int 	nb_r;
	int 	nb_c;
	
	init_game();
	
	my_putstr("La boucle du jeu. Pour sortir taper -1 \n\n");
	
	my_putstr("Choisir nombre de lignes: ");
	nb_r = choise_size();
	if (nb_r == -1)
		return (0);
	my_putstr("Choisir nombre de colonnes: ");
	nb_c = choise_size();
	if (nb_c == -1)
		return (0);
	t_case	cases[nb_r][nb_c];
	my_putstr("\n\n");
	
	my_putstr("Nombre de mines: ");
	my_put_nbr(number_mines(nb_r,nb_c));
	my_putstr("\n\n");
	
	initialize_table(nb_r,nb_c, cases);
	show_table(nb_r,nb_c, cases);
	choise_action(nb_r,nb_c, cases);
		
  	return (0);
}