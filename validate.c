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
	const char *flag = "pwning-since-1337";
	int i = 0;
	for (;; i++)
	{
		unsigned char a = (unsigned char)input[i];
		unsigned char b = (unsigned char)flag[i];
		if (a != b)
		{
			return 0;
		}
			
		if (a == 0)
		{
			return 1;
		}
			
	}
}
