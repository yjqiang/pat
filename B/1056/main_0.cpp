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

using namespace std;

#define N_MAX 10

int nums[N_MAX];

int main() {
	int N;
	
	scanf("%d", &N);
	
	int i, h;
	for (i = 0; i < N; ++i)
		scanf("%d", nums + i);

	int sum = 0;
	for (i = 0; i < N; ++i)
		for (h = i + 1; h < N; ++h)
			// (nums[i]*10 + nums[h]) + (nums[h] * 10 + nums[i])
			sum += nums[i] * 11 + nums[h] * 11;

	printf("%d", sum);


	system("pause");
	return 0;
}