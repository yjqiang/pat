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

#define N_MAX 100000

int nums[N_MAX];

// S2 Ϊ��Сֵ���֣��� |S1-S2| == S1-S2
// sum Ϊȫ���ĺͣ�S1-S2 = sum - S2 - S2
int S2 = 0, sum = 0;


int cmp(const void* p0, const void* p1) {
	int* a = (int*)p0;
	int* b = (int*)p1;
	return (*a) - (*b);
}

int main() {
	int N;
	scanf("%d", &N);

	int i;

	for (i = 0; i < N; ++i) {
		scanf("%d", nums + i);
		sum += nums[i];
	}

	qsort(nums, N, sizeof(int), cmp);
	
	// n2 Ϊ��Сֵ����
	// NΪż����ȡn2==n1
	// NΪ������ȡn1 == n2 + 1

	int n2 = N / 2;
	for (i = 0; i < n2; ++i)
		S2 += nums[i];

	printf("%d %d", (N - n2) - n2, (sum - S2) - S2);

	system("pause");
	return 0;
}