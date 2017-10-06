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

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (-1);





	int		fp;
	int		checksum;
	char	value;

	value = 31;
	fp = open(argv[1], O_RDONLY);
	while (read(fp, &value, 1))
	{
		checksum += value;
		if (checksum % n == x && checksum < max)
			checksum = 0;
		else
			return(-1);
	}


	return(0);
}