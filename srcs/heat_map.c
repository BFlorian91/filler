/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:20:51 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/08/08 14:53:37 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	place_number(t_filler *datas, char score, char previous)
{
	int		i;
	int		j;

	i = 1;
	while (i + 1 < datas->map_height)
	{
		j = 1;
		while (j + 1 < datas->map_width)
		{
			if (datas->map[i][j] == previous)
			{
				if (datas->map[UP][j] == '.')
					datas->map[UP][j] = score;
				if (datas->map[UP][RIGHT] == '.')
					datas->map[UP][RIGHT] = score;
				if (datas->map[UP][LEFT] == '.')
					datas->map[UP][LEFT] = score;
				if (datas->map[DOWN][j] == '.')
					datas->map[DOWN][j] = score;
				if (datas->map[DOWN][RIGHT] == '.')
					datas->map[DOWN][RIGHT]= score;
				if (datas->map[DOWN][LEFT] == '.')
					datas->map[DOWN][LEFT] = score;
				if (datas->map[i][RIGHT] == '.')
					datas->map[i][RIGHT] = score;
				if (datas->map[i][LEFT] == '.')
					datas->map[i][LEFT] = score;
			}
			++j;
		}
		++i;
	}
	/*print_board(datas->map);*/
	return (1);
}

/*static void	init_points_map(t_filler *datas)*/
/*{*/
/*int i;*/

/*i = 0;*/
/*datas->pos[i].y = -1;*/
/*datas->pos[i++].x = -1;*/
/*datas->pos[i].y = -1;*/
/*datas->pos[i++].x = 0;*/
/*datas->pos[i].y = -1;*/
/*datas->pos[i++].x = 1;*/
/*datas->pos[i].y = 0;*/
/*datas->pos[i++].x = -1;*/
/*datas->pos[i].y = 0;*/
/*datas->pos[i++].x = 1;*/
/*datas->pos[i].y = 1; */
/*datas->pos[i++].x = -1;*/
/*datas->pos[i].y = 1;*/
/*datas->pos[i++].x = 0;*/
/*datas->pos[i].y = 1;*/
/*datas->pos[i++].x = 1;*/
/*}*/

/*static int	place_number(t_filler *datas, char score, char previous)*/
/*{*/
/*int		i;*/
/*int		j;*/
/*int		point;*/


/*i = 1;*/
/*point = 8;*/
/*init_points_map(datas);*/
/*while (i + 1 < datas->map_height)*/
/*{*/
/*j = 1;*/
/*while (j + 1 < datas->map_width)*/
/*{*/
/*if (datas->map[i][j] == previous)*/
/*{*/
/*while (point >= 0 && datas->map[j + datas->pos[point].y][j + datas->pos[point].x] == '.')*/
/*{*/
/*[>STR("\nORIGIN POS ==> \n");<]*/
/*[>NBR(i);<]*/
/*[>CHAR(' ');<]*/
/*[>NBR(j);<]*/
/*[>BACKN;<]*/
/*[>STR("\nTEST POS ==> \n");<]*/
/*[>NBR(i + datas->pos[point].y);<]*/
/*[>CHAR(' ');<]*/
/*[>NBR(j + datas->pos[point].x);<]*/
/*[>BACKN;<]*/
/*[>STR("VALUES:");<]*/
/*[>NBR(datas->pos[point].y);<]*/
/*[>CHAR(' ');<]*/
/*[>NBR(datas->pos[point].x);<]*/
/*[>BACKN;<]*/
/*[>BACKN;<]*/
/*NBR(point);*/
/*datas->map[i + datas->pos[point].y][j + datas->pos[point].x] = score;*/
/*--point;*/
/*}*/
/*}*/
/*++j;*/
/*}*/
/*++i;*/
/*}*/
/*print_board(datas->map);*/
/*return (1);*/
/*}*/

static int	track_is_full(t_filler *datas)
{
	int i;
	int j;

	i = 0;
	while (datas->map[i])
	{
		j = 0;
		while (datas->map[i][j])
		{
			if (datas->map[i][j] == '.')
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

int			heat_map(t_filler *datas)
{
	char	score;

	score = 48;
	place_number(datas, score, datas->letter_enemy);
	while (!track_is_full(datas) && score < 126)
	{

		place_number(datas, score, (score - 1));
		++score;
		if ((score == 'X' || score == 'O' || score == '.') && score < 126)
		{
			++score;
			place_number(datas, score, (score - 2));
		}
		else
			place_number(datas, score, (score - 1));
	}
	return (1);
}
