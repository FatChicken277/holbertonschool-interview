#include "substring.h"

/**
 * find_substring - finds all the possible substrings
 *
 * @s: is the string to scan
 * @words: array of words all substrings
 * @nb_words: number of elements in the array words
 * @n: holds the address
 * Return: allocated array
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *idx_array;

	idx_array = malloc(10);
	if (!idx_array)
		return (0);

	if (*s && *words && nb_words && *n)
		return (idx_array);

	return (idx_array);
}
