
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char *str);

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <string>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	bool result = isPalindrome(argv[1]);
	printf("%s\n", result ? "yes" : "no");
}

bool isPalindrome(char *str) {
	int l = 0;
	int r = strlen(str) - 1;
	while (l < r) {
		if (str[l] != str[r]) {
			return false;
		}
		l++;
		r--;
	}
	return true;
}
