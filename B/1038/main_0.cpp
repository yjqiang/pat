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

using namespace std;

int counts[101] = { 0 };

int main() {
	int N, K;
	scanf("%d", &N);
	
	int i;
	int grade;
	for (i = 0; i < N; ++i) {
		scanf("%d", &grade);
		++counts[grade];
	}
	scanf("%d", &K);

	scanf("%d", &grade);
	printf("%d", counts[grade]);

	for (i = 1; i < K; ++i) {
		scanf("%d", &grade);
		printf(" %d", counts[grade]);
	}

	system("pause");
	return 0;
}