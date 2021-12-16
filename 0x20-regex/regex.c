#include "regex.h"

/**
 * regex_match - checks whether a given pattern matches a given string
 * @str: is the string to scan
 * @pattern: is the regular expression
 * Return: 1 if the pattern matches the string, or 0 if it doesn’t
 */
int regex_match(char const *str, char const *pattern)
{
	int x = 0;

	if (*str == '\0' && *pattern == '\0')
		return (1);

	if ((str[0] == pattern[0] || pattern[0] == '.') && (pattern + 1)[0] != '*')
		return (regex_match(str + 1, pattern + 1));

	if ((pattern + 1)[0] == '*')
	{
		if (str[0] != '\0' && (str[0] == pattern[0] || pattern[0] == '.'))
			x = regex_match(str + 1, pattern);

		return (regex_match(str, pattern + 2) || x);
	}

	return (0);
}
