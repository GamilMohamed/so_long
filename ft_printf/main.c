#include <stdio.h>
#include "includes/ft_printf.h"

int main ()
{
	int a, b;
	// void *p;

	// a =	   printf("%c%s%d%i%u%x%X %c%s%d%i%u%x%X %c%s%d%i%u%x%X %c%p\n",
	//  'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42,
	//   'C', "0", 0, 0 ,0 ,0, 42, 0, &p);
	// b = ft_printf("%c%s%d%i%u%x%X %c%s%d%i%u%x%X %c%s%d%i%u%x%X %c%p\n",
	//  'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42,
	//   'C', "0", 0, 0 ,0 ,0, 42, 0, &p);
	a = ft_printf("blanc%rrouge%bbleur%mmagenta%yjaune%gvert%0fin\n");
	// b = printf("ceci\033[0;31m123\n");
	// printf("%i|%i", a, b);
}