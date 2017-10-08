/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhouser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 19:51:23 by mhouser           #+#    #+#             */
/*   Updated: 2017/10/05 19:51:51 by mhouser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//exit, open, close, write, read, malloc and free
//Makefile must compile your work and present the following rules : all, clean,fclean et re.
//You must compile your executable with the flags Wall, Wextra and Werror
//The executable must be named fillit and located in the root directory of your repository

//checksum()
//*spacing check()
//{
//	piece check()
//}
//blankspace check()
//any final checks()

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


void	validate()
{

}
fillit(grid, tet_fp)
/*
	fillit() is called taking 0 for first itertion and recursivly passing itself grid (solution grid variable)
	add new tet to fresh grid of previous size grid (but empty)
	shuffle new tet to optimal top left position
	reconsider all previos tets on grid var and shuffle them into empty grid with new tet already positioned
	if more tets -> call fillit and pass new grid var
*/


int	main(int argc, char **argv)
{
	if (argc != 2)
		return (-1);





	int		fp;
	int		checksum;
	char	value;

	value = 31;
	checksum = 0;
	fp = open(argv[1], O_RDONLY);
	while (read(fp, &value, 1))
	{
		checksum += value;
		if (((checksum == 786) || (checksum == 742)) && checksum < 787)
			checksum = 0;
		else if(checksum >= 787)
		{
			printf("invalid\n");
			return(-1);
		}
		//printf("%d\n", checksum);
	}
	checksum += ((int)value == 10) ? 10 : 0;
	printf("%s\n", (checksum == 786 || checksum == 742) ? "valid" : "invalid");

	return(0);
}