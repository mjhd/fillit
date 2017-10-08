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

// CAN'T KEEP!!
#include <string.h>
#include <stdlib.h>
//#include "libft.h"

int	*validate(fp)
{
	int		*checksum;
	char	value;

	// NO MORE THAN 26

	checksum = (int *)malloc(sizeof(int));
	*checksum = 0;
	value = 31;
	while (read(fp, &value, 1))
	{
		*checksum += value;
		if (((*checksum == 786) || (*checksum == 742)) && *checksum < 787)
			*checksum = 0;
		else if(*checksum >= 787)
		{
			//printf("invalid\n");
			*checksum = -1;
			return(checksum);
		}
		//printf("%d\n", checksum);
	}
	*checksum += ((int)value == 10) ? 10 : 0;
	*checksum = (*checksum == 786 || *checksum == 742) ? 0 : -1;
	//printf("%s\n", (!checksum) ? "valid" : "invalid");
	return (checksum);
}

char *fillit(char *map, int fp)
{
	char	buf;
	char	*pnt;
	int		i;

	i = 20;
	if ((int)(*map) == -1)
	{
		map = (char *)malloc(6);
		strcpy(map, "error");
	}
	else if (!(int)(*map))
	{
		map = (char *)malloc(21);
		pnt = map;
		while (i-- && read(fp, &buf, 1))
			(*pnt++) = buf;
		*pnt = '$';

		map = ft_blanklineslicer(map);
	}



/*
		disassemble map into links to each peice;
		base letter assignment of new tet on number of tets dissambled;
		ft_compare all possible combinations of stored tets with new tet
		int ft_compare(tet1, tet2, map); -> return 0 or 1
		ft_compare(tet_compare_of, tet_compare_to, map);
		array[# of dissasembled tets + 1] -> 0
		array[member + ft_compare] for ft compare hits



		convert peice to letters and make fresh map from previous map size;
		place converted new tet on fresh map;
		reassemble linked tets from previous map -> growing map if necessary;
	*/
	//fillit(map, fp);
	return map;
}



int	main(int argc, char **argv)
{
	if (argc != 2)
		return (-1);





	int		fpv;
	int		fpf;
	char	*result;
	//char 	*file = "....\n...#\n..##\n..#.\n....\n....\n#...\n###.\n";

	fpv = open(argv[1], O_RDONLY);
	fpf = open(argv[1], O_RDONLY);
	int dummy = 0;
	//printf("%s\n", fillit((char *)validate(fp), fp));
	printf("%s\n", fillit((char *)validate(fpv), fpf));
	return(0);
}