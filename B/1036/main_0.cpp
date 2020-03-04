#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>

#include <climits>
#include <cstdio>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;


int main() {
	int N;
	char c;
	scanf("%d %c", &N, &c);

	int i;
	for (i = 0; i < N; ++i)
		printf("%c", c);
	printf("\n");

	int m = int(N / 2.0 + 0.5) - 2;
	int k;
	int N_2 = N - 2;
	for (i = 0; i < m; ++i) {
		printf("%c", c);
		for (k = 0; k < N_2; ++k)
			printf(" ");
		printf("%c", c);
		printf("\n");
	}
	for (i = 0; i < N; ++i)
		printf("%c", c);
	printf("\n");

	system("pause");
	return 0;
}