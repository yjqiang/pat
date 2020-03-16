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

bool judge(int K, int result) {
	while (K) {
		if (K % 10 != result % 10)
			return false;
		K /= 10;
		result /= 10;
	}
	return true;
}

void findN(int K) {
	int N, result;
	for (N = 1; N <= 10; ++N) {
		result = N * K * K;
		if (judge(K, result)) {
			printf("%d %d\n", N, result);
			return;
		}	
	}
	printf("No\n");
}

int main() {
	int M, K;
	scanf("%d", &M);

	int i;
	for (i = 0; i < M; ++i){
		scanf("%d", &K);
		findN(K);
	}
	
	
	
	system("pause");
	return 0;
}