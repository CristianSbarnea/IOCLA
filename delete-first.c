#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef unsigned int uint;

char* delete_first(char s[], char *pattern)
{
	if(!s)
		return NULL;
	if(!pattern)
		return NULL;
	uint len_s = strlen(s), len_pattern = strlen(pattern);
	char* ptr = strstr(s, pattern);
	uint length = len_s - strlen(ptr) ;
	char* rezultat = strdup(s);
	if(!rezultat)
		return NULL;
	for(int i = length; i < len_s - len_pattern; i++){
		*(rezultat + i) = *(rezultat + i + len_pattern);
	}
	*(rezultat + len_s - len_pattern) = '\0';
	return rezultat;
}

int main(){
	char s[] = "Ana are mere";
	char *pattern = "Ana ";
	// Decomentati linia dupa ce ati implementat functia delete_first.
	printf("%s\n", delete_first(s, pattern));
	printf("%s\n", s);
	return 0;
}
