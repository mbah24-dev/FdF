/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:09:55 by mbah              #+#    #+#             */
/*   Updated: 2025/01/22 17:11:44 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// Fonction pour compter le nombre de mots dans la chaîne
static int	count_words(const char *str, char sep)
{
	int	count = 0;
	int	in_word = 0;

	while (*str)
	{
		if (*str != sep && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == sep)
			in_word = 0;
		str++;
	}
	return (count);
}

// Fonction pour allouer une sous-chaîne
static char	*malloc_word(const char *start, const char *end)
{
	char	*word;
	size_t	len = end - start;
	size_t	i;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = *start++;
	word[i] = '\0';
	return (word);
}

// Libère tout le tableau en cas d'erreur
static void	free_split(char **split, int count)
{
	int	i;

	for (i = 0; i < count; i++)
		free(split[i]);
	free(split);
}

// Fonction principale pour diviser la chaîne
char	**new_split(const char *str, char sep)
{
	char	**result;
	int		words;
	int		i = 0;
	const char	*start;

	if (!str)
		return (NULL);
	words = count_words(str, sep);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	while (*str)
	{
		if (*str != sep)
		{
			start = str;
			while (*str && *str != sep)
				str++;
			result[i] = malloc_word(start, str);
			if (!result[i])
			{
				free_split(result, i);
				return (NULL);
			}
			i++;
		}
		else
			str++;
	}
	result[i] = NULL;
	return (result);
}
