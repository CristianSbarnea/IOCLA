#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define SIGN(X) (((X) > 0) - ((X) < 0))

int my_strlen(const char *s){
	int length = 0;
	while(*(s + length))
		length++;
	return length;
}

int my_strcmp(const char *s1, const char *s2){
	for(; *(s1) || *(s2); s1++, s2++)
		if(*(s1) != *(s2))
			return *(s1) - *(s2);
}
void *my_memcpy(void *dest, const void *src, size_t n){
	char* s = (char*)src;
	char* p = (char*)dest;
	for(int i = 0; i < n; i++, p++, s++)
		*p = *s;
	return dest;
}

char *my_strcpy(char *dest, const char *src){
	char* new = dest;
	for(; *(src); ++src, ++dest)
		*(dest) = *(src);
	return new;
}


int main() {
	char s1[] = "Abracadabra";
	char s2[] = "Abracababra";
	char src[] = "Learn IOCLA, you must!";
	char *dest = malloc(sizeof(src));	
	(void) s1;
	(void) s2;
	/*
	Decomentati pe rand cate un assert pe masura ce implementati o functie.
	Daca functia voastra este implementata corect atunci asertia se va realiza
	cu succes. In caz contrar, programul va crapa.
	*/
	assert(SIGN(my_strcmp(s1, s2)) == SIGN(strcmp(s1, s2)));
	assert(my_memcpy(dest, src, sizeof(src)) == memcpy(dest, src, sizeof(src)));
	assert(my_strcpy(dest, src) == strcpy(dest, src));
	free(dest);
	return 0;
}
