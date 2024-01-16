/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:55:20 by mgalmari          #+#    #+#             */
/*   Updated: 2024/01/10 16:28:08 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countw(char const *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s && s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word++;
		i++;
	}
	return (word);
}

static char	**ft_freeato(char **fin, int x)
{
	while (x >= 0)
	{
		free(fin[x]);
		x--;
	}
	free(fin);
	return (NULL);
}

static char	*ft_strnew(const char *s, size_t i, char c)
{
	unsigned int	st;
	size_t			len;

	st = (unsigned int)i;
	while (s[i] && s[i] != c)
		i++;
	len = i - st;
	return (ft_substr(s, st, len));
}

static char	**ft_copia(char **fin, const char *s, char c)
{
	size_t	i;
	int		x;

	i = 0;
	x = 0;
	while (i < ft_strlen(s))
	{
		while (s && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			if (s[i - 1] == c || i == 0)
			{
				fin[x] = ft_strnew(s, i, c);
				if (!fin[x])
					return (ft_freeato(fin, x));
				x++;
			}
			i++;
		}
	}
	fin[x] = NULL;
	return (fin);
}

char	**ft_split(char const *s, char c)
{
	char	**fin;

	if (!s)
		return (NULL);
	fin = (char **)malloc(sizeof(char *) * (ft_countw(s, c) + 1));
	if (!fin)
		return (NULL);
	return (ft_copia(fin, s, c));
}
/* 
int main()
{
	int i = 0;
	char **fin = ft_split("Ciao", ' ');
	
	while (fin[i])
	{
		printf("[%d] %s\n", i, fin[i]);
		i++;
	}
	if (!fin)
		printf("non c'e");
	ft_freeato(fin, i);
	return (0);
} */