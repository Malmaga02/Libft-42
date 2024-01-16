/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:28:40 by mgalmari          #+#    #+#             */
/*   Updated: 2024/01/05 12:44:11 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	*t2;

	i = 0;
	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (t1[i] != '\0' && t2[i] != '\0' && i < n - 1)
	{
		if (t1[i] != t2[i])
			return (t1[i] - t2[i]);
		i++;
	}
	return (t1[i] - t2[i]);
}
/* int main()
{
	printf("my is %d, yours is %d", ft_strncmp("1", "", 1), strncmp("1", "", 1));
	return (0);
} */