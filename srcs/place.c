/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:06:52 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/07/31 14:14:43 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		can_place(t_filler *datas)
{
	int 	i;
	int 	j;
	int		my_player_char;	

	j = 0;
	my_player_char = 0;
	while (j + datas->y < datas->map_height && j < datas->piece_height)
	{
		i = 0;
		while (i + datas->x < datas->map_width && i < datas->piece_width)
		{
			if (datas->piece[j][i] == '*' && datas->map[j + datas->y][i + datas->x] == datas->letter_me)
				++my_player_char;
			if (datas->piece[j][i] == '*' && datas->map[j + datas->y][i + datas->x] == datas->letter_enemy)
				return (0);
			++i;
		}
		++j;
	}
	return (my_player_char == 1 ? 1 : 0);
}

int		place(t_filler *datas)
{
	datas->y = 0;
	while (datas->y + datas->piece_height <= datas->map_height)
	{
		datas->y == 0 ? (datas->x = 1) : (datas->x = 0);
		while (datas->x + datas->piece_width <= datas->map_width)
		{
			if (can_place(datas))
			{
				heat_map(datas);
				ft_printf("%s %s\n", ft_itoa(datas->y), ft_itoa(datas->x));
				return (1);
			}
			++(datas->x);
		}
		++(datas->y);
	}
	datas->y = 0;
	datas->x = 0;
	ft_printf("%s %s\n", ft_itoa(datas->y), ft_itoa(datas->x));
	return (0);
}
