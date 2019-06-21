#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define BEER 0.20
#define VODKA 2.00
#define VINE 0.60

void flush(void);
int get_first(void);
float get_number(void);

int main(void)
{
	bool flag = false;
	char ch;
	float beer, vine, spirit, result;

	while (1)
	{
		printf("How much did you had to drink?\n");
		printf("Enter amount in LITERS in a format such as 2.5, 1.78E8, or 3.\n");

		printf("Beer: ");
		beer = get_number();

		printf("Vine and martini: ");
		vine = get_number();

		printf("40%% spirit like whisky, vodka etc.: ");
		spirit = get_number();

		result = beer * BEER + VINE * vine + VODKA * spirit;

		printf("\nYou drank %.2f %s of vodka.\n", result, (result > 1) ? "BOTTLES" : "BOTTLE");
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
	int ch;

	do ch = getchar(); while (isspace(ch));

	while (getchar() != '\n')
		continue;

	return toupper(ch);
}

float get_number(void)
{
	int ch;
	float num;

	while (scanf("%f", &num) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch);

		printf(" is not a number.\n");
		printf("Please enter a number, such as 2.5, 1.78E8, or 3: ");
	}

	return num;
}
