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
	
	vector<int> result;
	int max_sale = -1;
	for (i = 1; i <= N; ++i) {
		if (counts[i] > max_sale) {
			result.clear();
			result.push_back(i);
			max_sale = counts[i];
		}
		else if (counts[i] == max_sale)
			result.push_back(i);
	}
	printf("%d\n", max_sale);
	printf("%d", result[0]);
	for (i = 1; i < result.size(); ++i)
		printf(" %d", result[i]);
	system("pause");
	return 0;
}