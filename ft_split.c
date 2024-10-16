/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:05:56 by mmembril          #+#    #+#             */
/*   Updated: 2024/10/04 20:45:58 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word(char const *str, char c, int i)
{
	int	size;

	size = 0;
	while (str[i] && str[i] != c)
	{
		i++;
		size++;
	}
	return (size);
}

static void	ft_free(char **str, int j)
{
	while (j-- > 0)
		free(str[j]);
	free(str);
}

static int	ft_cont(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		m;
	int		j;
	int		i;
	int		size;

	m = ft_cont(s, c);
	i = 0;
	str = (char **)malloc(sizeof(char *) * (m + 1));
	j = 0;
	if (!str)
		return (NULL);
	while (j < m)
	{
		while (s[i] == c)
			i++;
		size = ft_word(s, c, i);
		str[j] = ft_substr(s, i, size);
		if (!str[j])	
			return (ft_free(str, j), NULL);
		i += size;
		j++;
	}
	str[j] = 0;
	return (str);
}
/*int main(void)
{
    char *s = "hola mundo";
	char c = 32;
    char **st = ft_split(s, c);
    int i = 0;
	if (!st)
		return (0);
    while (st[i][0] != '\0')
    {
        printf("%s\n", st[i]);
		free (st[i]);
        i++;
    }
    free (st);
    return (0);
}*/
