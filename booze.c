#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define BEER 0.10
#define VODKA 2.00
#define VINE 0.31

void flush(void);
int get_first(void);

int main(void)
{
	bool flag = false;
	char ch;
	float beer, vine, spirit, result;

	while (1)
	{
		printf("How much did you had to drink?\n");
		printf("Enter amount in LITERS in a format like 0 or 0.5 or 3.\n");

		printf("Beer: ");
		while (scanf("%f", &beer) != 1 || beer < 0)
			printf("\nInvalid imput, try again.\n");

		printf("Vine and martini: ");
		while (scanf("%f", &vine) != 1 || beer < 0)
			printf("\nInvalid imput, try again.\n");

		printf("40%% spirit like whisky, vodka etc.: ");
		while (scanf("%f", &spirit) != 1 || beer < 0)
			printf("\nInvalid imput, try again.\n");

		result = beer * BEER + VINE * vine + VODKA * spirit;

		printf("\nYou drank %.2f BOTTLES of vodka.\n", result);
		printf("If you want to count again enter \"Y\", if you want to exit enter \"Q\": \n");

		ch = get_first();
		switch (ch)
		{
		case ('Y') :
			flag = false;
			break;
		case ('Q') :
			flag = true;
			break;
		default :
			printf("Invalid imput.\n");
			flag = true;
			break;
		}
		if (flag)
			break;
	}
	printf("Bye.");
	return 0;
}

void flush(void)
{
	while (getchar != '\n')
		continue;
}

int get_first(void)
{
	// return first non-whitespace character
	int ch;

	do ch = getchar(); while (isspace(ch));

	while (getchar() != '\n')
		continue;

	return toupper(ch);
}
