#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 128

char* string_allocation(const char *str)
{
	char* res;
	res = (char*)calloc(MAX, sizeof(char));
	strcpy(res, str);
	return res;
}

int my_strlen(const char *str)
{
	int length = 0;
	while(*(str + length))
		length++;
	return length;
}

void equality_check(const char *str)
{
	for(int i = 0; i < my_strlen(str); i++)
	{
		char* current_char = (char*)(str + i);
		char* next_char = (char*)(str + ((i + 1 << i) % my_strlen(str)));
		if(!(*current_char ^ *next_char))
			printf(" Address of %c : %p", *current_char, current_char);	
	}
}

int main(void)
{
	char* str;
	str = string_allocation("ababababacccbacbacbacbacbabc");
	printf("length = %d", my_strlen(str));
	equality_check(str);
	return 0;
}

