#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <cmath>
#include <climits>
#include <queue>
#include <set>
#include <unordered_set>

using namespace std;

#define N_MAX 1001

int counts[N_MAX] = { 0 };

int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	int i, k;
	int sale;
	
	for (i = 0; i < M; ++i)
		for (k = 1; k <= N; ++k) {
			scanf("%d", &sale);
			counts[k] += sale;
		}
	
	int max_sale = -1;
	for (i = 1; i <= N; ++i)
		max_sale = max(max_sale, counts[i]);
	printf("%d\n", max_sale);

	bool is_first = true;
	for (i = 1; i <= N; ++i)
		if (counts[i] == max_sale) {
			if (!is_first)
				printf(" ");
			else
				is_first = false;
			printf("%d", i);
		}
	
		
	system("pause");
	return 0;
}