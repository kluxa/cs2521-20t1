
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

bool isOrdered(List l) {
	return false;
}

int main(void) {
	int A1[] = {};
	List l1 = arrayToList(A1, 0);
	assert(isOrdered(l1));

	int A2[] = {5};
	List l2 = arrayToList(A2, 1);
	assert(isOrdered(l2));

	int A3[] = {3, 6};
	List l3 = arrayToList(A3, 2);
	assert(isOrdered(l3));

	int A4[] = {8, 4};
	List l4 = arrayToList(A4, 2);
	assert(!isOrdered(l4));

	int A5[] = {2, 6, 8};
	List l5 = arrayToList(A5, 3);
	assert(isOrdered(l5));

	int A6[] = {3, 9, 8};
	List l6 = arrayToList(A6, 3);
	assert(!isOrdered(l6));

	int A7[] = {7, 7, 7};
	List l7 = arrayToList(A7, 3);
	assert(isOrdered(l7));

	printf("Tests passed!\n");
}
