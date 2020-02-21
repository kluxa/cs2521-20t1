
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/* From list.h
typedef struct _Node {
	int value;
	struct _Node *next;
} Node;

typedef Node *List; // pointer to first Node
*/

/**
 * Delete first instance of a value from
 * the list, if it exists
 */
List listDelete(List l, int val) {
	List curr = l;
	List prev = NULL;

	while (curr != NULL) {
		if (curr->value == val) {
			// deleting first value
			if (prev == NULL) {
				List temp = curr->next;
				free(curr);
				return temp;
			
			// deleting middle value
			} else {
				prev->next = curr->next;
				free(curr);
				return l;
			}
		}
		prev = curr;
		curr = curr->next;
	}

	// value not found
	return l;
}

int main(void) {
	int a[] = {0, 1, 1, 2, 3, 5, 8};
	List l = arrayToList(a, 7);
	
	printList(l);

	// try a value in the list
	l = listDelete(l, 2);
	printList(l);

	// try a value not in the list
	l = listDelete(l, 9);
	printList(l);

	// try a value that occurs more
	// than once in the list
	l = listDelete(l, 1);
	printList(l);

	// try a value that appears at
	// the beginning of the list
	l = listDelete(l, 0);
	printList(l);
}
