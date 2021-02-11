#include "palindrome.h"

/**
 * is_palindrome - checks if a integer is a palindrome.
 *
 * @n: number
 *
 * Return: 0 if not is a palindrome, 1 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long lastDigit, reverse = 0, nCopy = n;

	while (nCopy > 0)
	{
		lastDigit = nCopy % 10;
		reverse = (reverse * 10) + lastDigit;
		nCopy = nCopy / 10;
	}

	if (reverse == n)
		return (1);

	return (0);
}
