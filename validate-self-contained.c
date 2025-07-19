#include <stdio.h>
#include <string.h>

int validate(const char *input);

int main()
{
	char input[64];
	scanf("%63s", input);
	if (validate(input))
	{
		printf("Correct!\n");
	}
	else
	{
		printf("Wrong!\n");
	}
	return 0;
}

int validate(const char *input)
{
	// Store the flag as a local array, not as a pointer to a string literal
	const unsigned char flag[] = {
		'p', 'w', 'n', 'i', 'n', 'g', '-', 's', 'i', 'n', 'c', 'e', '-', '1', '3', '3', '7', 0};
	int i = 0;
	while (1)
	{
		unsigned char a = (unsigned char)input[i];
		unsigned char b = flag[i];
		if (a != b)
			return 0;
		if (a == 0)
			return 1;
		i++;
	}
}
