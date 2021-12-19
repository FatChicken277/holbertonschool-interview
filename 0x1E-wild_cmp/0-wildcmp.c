#include "holberton.h"
#include <stdio.h>

/**
 * wildcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 1 if the strings can be considered identical, otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
	int lens1, lens2, boolTrue = 1, asterisk = 0;

	for (lens1 = 0; s1[lens1] != '\0'; lens1++)
		;
	for (lens2 = 0; s2[lens2] != '\0'; lens2++)
		;

	lens1 = lens1 - 1;
	lens2 = lens2 - 1;

	for (; lens2 >= 0; lens1--, lens2--)
	{
		if (s2[lens2] == '*')
		{
			asterisk = 1;
			lens1++;
			continue;
		}

		if (asterisk == 1)
		{
			while (s2[lens2] != s1[lens1])
				lens1--;

			asterisk = 0;
			continue;
		}

		if (s2[lens2] != s1[lens1])
		{
			boolTrue = 0;
			break;
		}
	}

	return (boolTrue);
}
