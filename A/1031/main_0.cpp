#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>
#include <cstring>
#include <climits>
#include <cstdio>
#include <queue>

using namespace std;


int main() {
	char s[81];

	scanf("%s", s);
	int N = strlen(s);

	int n2 = max(3, ((N + 2) + 3 - 1) / 3);
	if ((N - n2) % 2)
		++n2;
	// printf("%d\n", n2);

	int n1 = (N + 2 - n2) / 2;

	int i, k;
	int n1_1 = n1 - 1;
	int n2_2 = n2 - 2;
	for (i = 0; i < n1_1; ++i) {
		printf("%c", s[i]);
		for (k = 0; k < n2_2; ++k)
			printf(" ");
		printf("%c\n", s[N - 1 - i]);
	}
	for (k = 0; k < n2; ++k, ++i) {
		printf("%c", s[i]);
	}
		

	system("pause");
	return 0;
}