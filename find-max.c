#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
	Functie generica pentru calcularea valorii maxime dintr-un array.
	n este dimensiunea array-ului
	element_size este dimensiunea unui element din array
	Se va parcurge vectorul arr, iar la fiecare iteratie sa va verifica
	daca functia compare intoarce 1, caz in care elementul curent va fi
	si cel maxim.
	Pentru a folosi corect aritmetica pe pointeri vom inmulti indexul curent
	din parcurgere cu dimensiunea unui element.
	Astfel, pentru accesarea elementului curent avem:
	void *cur_element = (char *)arr + index * element_size;
*/

void *find_max(void *arr, int n, int element_size,int (*compare)(const void *, const void *)) {
	void *max_elem = arr;
	for(int i = 1; i < n; i++){
		void *cur_element = (char*)arr + i * element_size;
		if(compare(cur_element, max_elem))
			max_elem = cur_element;
	}
	return max_elem;
}

int compare(const void *a, const void *b){
	if(*((int*)a) > *((int*)b))
		return 1;
	return 0;
}

/*
	Se citeste de la tastatura un vector si se cere sa se afle
	elementul maxim folosind functia find_max.
	Rezultatul functiei find_max trebuie cast la int, spre exemplu:
	int *res = (*int) find_max(...);
*/
int main() {
	int n;
	printf("Introduceti numarul de elemente : ");
	scanf("%d", &n);
	int *arr = calloc(n, sizeof(*arr));
	for (int i = 0 ; i < n; ++i)
		scanf("%d", &arr[i]);
	int *elem = find_max(arr, n, sizeof(int), compare);
	printf("Elem maxim : %d\n", *elem);
	free(arr);
	return 0;
}
