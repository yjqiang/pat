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

using namespace std;

#define N_MAX 100000
int a[N_MAX];

// 从大到小
int cmp(const void* p0, const void* p1) {
	int* i0 = (int*)p0;
	int* i1 = (int*)p1;
	return (*i1) - (*i0);
}


int main() {
	int N;
	int dist;
	scanf("%d", &N);

	int i;
	for (i = 1; i <= N; ++i)
		scanf("%d", a + i);

	qsort(a + 1, N, sizeof(int), cmp);
	// a[i] > i，则a[1]...a[i] 均大于 i，满足要求；否则不满足
	for (i = 1; i <= N; ++i)
		if (a[i] <= i) {
			break;
		}
	// 当break或者i=N+1时，需要--i
	--i;
	printf("%d", i);


	system("pause");
	return 0;
}