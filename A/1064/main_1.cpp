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
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define N_MAX 1001
int N;

int mid[N_MAX];

// level[��ȫ��������index] = num
int level[N_MAX];

int cmp(const void* p0, const void* p1) {
	int* a = (int*)p0;
	int* b = (int*)p1;
	return *a - *b;
}

// ָʾ�±�
int mid_i = 1;
// �������
void mid_check(int index) {
	if (index > N)
		return;
	// ������
	mid_check(index * 2);

	level[index] = mid[mid_i++];

	// ������
	mid_check(index * 2 + 1);
}

int main() {
	scanf("%d", &N);

	// ��������Ǵ�С�����ź����
	int i;
	for (i = 1; i <= N; ++i)
		scanf("%d", mid + i);
	qsort(mid + 1, N, sizeof(int), cmp);

	mid_check(1);

	printf("%d", level[1]);
	for (i = 2; i <= N; ++i)
		printf(" %d", level[i]);

	system("pause");
	return 0;
}