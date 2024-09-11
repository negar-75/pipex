/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:49:54 by nnasiri           #+#    #+#             */
/*   Updated: 2024/06/13 16:08:18 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	ft_word_count(char const *s, char c)
{
	int	world_count;
	int	i;

	world_count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			world_count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (world_count);
}

static char	*ft_allocate_word(char const *s, char c)
{
	int		i;
	char	*new_word;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	new_word = (char *)malloc((i + 1) * sizeof(char));
	if (!new_word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		new_word[i] = s[i];
		i++;
	}
	new_word[i] = '\0';
	return (new_word);
}

static void	free_split(char **arr, int j)
{
	while (j > 0)
	{
		free(arr[--j]);
	}
	free(arr);
}

static char	**split_str(char **arr, const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			arr[j] = ft_allocate_word(&s[i], c);
			if (!arr[j])
			{
				free_split(arr, j);
				return (NULL);
			}
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**arr;

	words = ft_word_count(s, c);
	arr = (char **)malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (split_str(arr, s, c));
}
