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



int main() {
	int N;
	scanf("%d", &N);
	
	double result = 0;

	int i;
	double num;

	// nums[i] 在 (i+1)*(N-1-i+1)个片段里出现了
	for (i = 0; i < N; ++i) {
		scanf("%lf", &num);
		result += num * (i + 1) * (N - i);
	}

	printf("%.2lf", result);

	system("pause");
	return 0;
}