void    my_putchar(char c);

int     my_putstr(char *str)
{
  int 	i;

  for(i = 0; str[i] != '\0'; ++i)
    my_putchar(str[i]);
  return (0);
}
