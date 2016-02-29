#include <stdlib.h>

void    my_putchar(char c);
int     my_isneg(int n);

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
  char 	*tab;
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
