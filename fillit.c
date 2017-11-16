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

typedef struct tet {
	struct tet *next;
	int value[4][2];
} tet;

void  prnt_list(tet *list)
{
	tet *pnt;

	pnt = list;
	while ((*pnt).next)
	{
		printf("!");
		pnt = (*pnt).next;
	}
	printf("!");
}

int	validate(int fp)
{
	int		checksum;
	char	value;
	int		x;
	int 	y;
	int 	valids;

	// NO MORE THAN 26

	checksum = 0;
	x = 4;
	y = 4;
	valids = 0;
	struct tet *list;
	struct tet *rdpnt;

	list = (tet *)malloc(sizeof(struct tet));
	rdpnt = list;

	while (read(fp, &value, 1))
	{
		if(!checksum && !(*rdpnt).next)
		{
			(*rdpnt).next = (tet *)malloc(sizeof(tet));
			rdpnt = (*rdpnt).next;
		}

		value = *input++;
		checksum += value;
		if (value == '#')
		{
			//(*rdpnt).value[valids][0] = x;
			//(*rdpnt).value[valids][1] = y;
			printf("Found # at %d, %d\n", x, y);
			valids++;
		}
		else if (value == '\n' && x && y != 4)
		{
			checksum = -1;
			break;
		}
		else if (value != '\n' && value != '#' && value != '.')
		{
			value = -1;
			break;
		}
		if (checksum == 732 && valids == 4)
		{
			checksum = 0;
			valids = 0;
			(*rdpnt).next = 0;
		}
		else if(checksum >= 733)
		{
			checksum = -1;
			break;
		}
		//printf("%d , %d\n", x, y);
		y = (value == '\n' && x == 0) ? y - 1 : y;
		x = (value == '\n') ? 4 : x - 1;
		y = (y == 0) ? 4 : y;
	}
	checksum = (!checksum) ? 1 : 0;

	return (checksum);
}

/*char *fillit(char *map, int fp)
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

	//fillit(map, fp);
	return map;
}*/



int	main(int argc, char **argv)
{
	if (argc != 2)
		return (-1);


	//char *str = "....\n....\n....\n####\n\n....\n....\n###.\n..#.";



	//int arr[4][2] = {{4,2}, {3,2}, {2,2}, {2,1}};

	//char *str = "....\n....\n....\n####\n\n....\n....\n###.\n..#.\n";
	//char *str = "\n....\n....\n....\n####\n\n....\n....\n###.\n..#.";
	//char *str = "....\n....\n....\n####\n\n....\n....###.\n..#.\n";
	//char *str = "\n....\n....\n....\n####\n\n....\n....###.\n..#.";


	int		fp;

	fp = open(argv[1], O_RDONLY);

	struct tet *list;
	list = (tet *)malloc(sizeof(struct tet));
	(*list).next = list;

	printf("%d\n", validate(fp, list));

	prnt_list(list);

	// if(validator(fp, **link)) {
	//  file and tets validated and list attached to argument link
	//  assembler(**link);
	//}
	return(0);
}