
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

bool isOrdered(List l) {
	// an empty list is ordered by default
	if (l == NULL) {
		return true;
	
	// a list with one element is ordered by default
	} else if (l->next == NULL) {
		return true;
	
	// if the first value is larger than second value
	} else if (l->value > l->next->value) {
		return false;
	
	// check that the rest of the list is ordered
	} else {
		return isOrdered(l->next);
	}
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
