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

// �Ӵ�С
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
	// a[i] > i����a[1]...a[i] ������ i������Ҫ�󣻷�������
	for (i = 1; i <= N; ++i)
		if (a[i] <= i) {
			break;
		}
	// ��break����i=N+1ʱ����Ҫ--i
	--i;
	printf("%d", i);


	system("pause");
	return 0;
}