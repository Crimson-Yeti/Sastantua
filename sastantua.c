#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_math(int row, int desiredreturn, int i);
void ft_print_row(int max_chars, int chars, int door);
void sastantua(int size);

/*
Our main function is set up to take multiple inputs from the command line, and build all of the pyramids
to the size specified.
*/

int main(int argc, char **argv)
{
        int i = 0;
		int tmp;
        while (argc > ++i)
		{
			tmp = atoi(argv[i]);
			if (tmp > 0)
			{
				printf("\nSize %i\n", tmp);
				sastantua(tmp);
			}
			else
				printf("\n\n***Argument \"%s\" Invalid***\n\n", argv[i]);
		}
		return(0);
}

/*
sastantua takes in the size of the pyramid needing to be built, and then organizes the information
before calling upon our other funtions to get the job done.
*/

void sastantua(int size)
{
	int i;
	int max_row;
	int max_chars;

	i = 1;
	max_row = ft_math(0, 1, size);
	max_chars = ft_math(max_row, 4, 0);
	if (size > 0)
	{
		size = (size % 2 == 0 ? size - 1 : size);
		while (max_row--)
			ft_print_row(max_chars, ft_math(i++, 4, 0), size);
	}
}

/*
ft_print_row takes in the number of characters at the bottom of our pyramid (max_chars), the number of characters
in our current row (chars), and the size of our door (door), and assembles our pyramid level by level with the
information.
*/

void ft_print_row(int max_chars, int chars, int door)
{
	int i;

	i = 0;
	write (1, "|", 1);
	while (i < max_chars)
	{
		if (i < (max_chars / 2) - (chars / 2) || i > (max_chars / 2) + (chars / 2))
			write(1, " ", 1);
		else if (i == (max_chars / 2) - (chars / 2) || i == (max_chars / 2) + (chars / 2))
			i == (max_chars / 2) - (chars / 2) ? write(1, "/", 1) : write(1, "\\", 1);
		else if (max_chars - chars <= door * 2 - 1 && (i >= (max_chars / 2) - (door / 2)
			&& i <= (max_chars / 2) + (door / 2)))
				door > 3 && i == (max_chars / 2) + (door / 2) - 1 &&
				max_chars - chars == door - 1
					? write (1, "$", 1) : write(1, "|", 1);
		else
			write (1, "*", 1);
		i++;
	}
	write(1, "\n", 1);
}

/* 
   ft_math does all of the heavy lifting when it comes to crunching the numbers for our pyramid.
   
   Since there are different calculations needed for building our pyramid correctly, we need to
   tell our math function what our desired return is.
   
   The keys for desired return are as follows:
   1 = The maximum number of rows for size i
   2 = Tier that current row is in
   3 = Character progression for tier changes
   4 = Number of characters in row i
*/

int	ft_math(int row, int desiredreturn, int i)
{
	if (desiredreturn == 1)
		return(i == 1 ? 3 : (i + 2) + ft_math(0, 1, i - 1));
	if (desiredreturn == 2)
	{
		if (row > 3)
			return (row > ft_math(0, 1, i) ? ft_math(row, 2, i + 1) : i);
		return (1);
	}
	if (desiredreturn == 3)
		return (i % 2 == 0 ? i + 4 : i + 3);
	if (row > 1)
		return (ft_math(row, 2, 1) == ft_math(row - 1, 2, 1) ? 2 + ft_math(row -1, 4,
			ft_math(0, 3, ft_math(row - 1, 2, 1))) :
		ft_math(0, 3, ft_math(row, 2, 1)) + ft_math(row - 1, 4, ft_math(0, 3,
			ft_math(row - 1, 2, 1))));
	return (3);
}
