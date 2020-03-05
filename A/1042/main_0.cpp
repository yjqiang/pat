#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>

#include <climits>
#include <cstdio>
#include <queue>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

// index 1->54
char s[55][4];

char types[] = "SHCDJ";

int order[55];
int result[55];


int main() {
	int K;
	scanf("%d", &K);

	int i;
	for (i = 1; i <= 54; ++i)
		scanf("%d", order + i);

	int h;
	int cur_index;
	for (i = 1; i <= 54; ++i) {
		cur_index = i;
		for (h = 0; h < K; ++h)
			cur_index = order[cur_index];
		result[cur_index] = i;
	}

	printf("%c%d", types[(result[1] - 1) / 13], (result[1] - 1) % 13 + 1);
	for (i = 2; i <= 54; ++i) {
		// [0, 12] -> 0 S; [13, 25] -> 1 H; [26, 38] -> 2 C; [39, 51] -> 3 D; [52, 53] -> 4
		printf(" %c%d", types[(result[i] - 1) / 13], (result[i] - 1) % 13 + 1);
	}

	system("pause");
	return 0;
}