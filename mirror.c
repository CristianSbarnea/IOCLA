#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 128

char* string_allocation(const char* str)
{
	char *string;
	string = (char *)calloc(MAX, sizeof(char));
	strcpy(string, str);
	return string;
}

int my_strlen(char* str)
{
	int length = 0;
	while(*(str + length))
		length++;
	return length;
}

void mirror(char *str)
{
	char temp;
	int l = my_strlen(str);
	for(int i = 0; i < (l >> 1); i++)
	{
		int 
		temp = *(str + i);
		*(str + i) = *(str + l - i - 1);
		*(str + l - i - 1) = temp;
	}
}

int main()
{
	char* str;
	str = string_allocation("AnaAreMere");
	printf("%s\n", str);
	printf("%d\n", my_strlen(str));
	mirror(str);
	printf("%s\n", str);
	return 0;
}

