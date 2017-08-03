void	ft_putchar(char);

int	get_cursor_position(char *comb, int n)
{
  int	max;
  int	p;
  
  max = '9';
  p = n - 1;
  while (comb[p] == max)
    {
      p = p - 1;
      max = max - 1;
    }
  return (p);
}


void	print_combn(char *comb, int n)
{
  int	i;

  i = 0;
  while (i < n)
    {
      ft_putchar(comb[i]);
      i = i + 1;
    }
  if (get_cursor_position(comb, n) >= 0)
    {
      ft_putchar(',');
      ft_putchar(' ');
    }
}

void	ft_print_combn(int n)
{
  char	comb[n];
  int	p;
  int	i;
  char	max;
  
  comb[0] = '0';
  i = 1;
  while (i < n)
    {
      comb[i] = comb[i - 1] + 1;
      i = i + 1;
    }
  p = n - 1;
  while (get_cursor_position(comb, n) >= 0)
    {
      print_combn(comb, n);
      p = get_cursor_position(comb, n);
      comb[p] = comb[p] + 1;
      while (p < (n - 1))
	{
	  comb[p + 1] = comb[p] + 1;
	  p = p + 1;
	}
    }
  print_combn(comb, n);
}
