/*
MADE BY GROUT_R + VOINNE_C

PROJECT MALLOC EPITECH 2

JANUARY 2015
 */

#include <unistd.h>
#include <stdio.h>

void		*g_start;

void	*find_space(void *ptr, size_t size)
{
  while (ptr )
    {
      
    }
  return NULL;
}

void		*malloc(size_t size)
{
  void		*ret;
  int		*stock_size;
  int		*stock_next;
  char		*stock_status;

  static int	first_time = 0;
  printf("size :: %lu\n", size);
  if ((int)size < 1)
    return (NULL);

  if (first_time == 0)
    {
      first_time = 1;
      start = sbrk(0);
      sbrk(9);
      puts("first time !");
    }
  if ((ret = find_space(start, size)) != NULL)
    {
      *(char *)ret = 1;
      return ret;
    }

  ret = sbrk(size + 9);

  stock_status = (char*)(ret);
  stock_size = (int*)((char*)ret + 1);
  stock_next = (int*)((char*)ret + 9 + 5 + size);

  if (first_time == 0)
    *(int*)((char*)ret + 5) = 0;
  *stock_status = 1;
  *stock_size = size;
  *stock_next = size; 
-
  return ((char*)ret + 9);
}
