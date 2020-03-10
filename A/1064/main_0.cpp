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

using namespace std;

#define N_MAX 1001
int N;
// index��1��ʼ
int sorted[N_MAX];

// index��1��ʼ
// ���ս�����������ȫ��������ʾ����
int a[N_MAX];

// index��1��ʼ
// ��ʾ����ȫ��������ʾ�����±�Ϊi�������Ĵ�С����ȫ��������ʾ��Ҳ��1��ʼ���
int subtree_nums[N_MAX] = { 0 };

int cmp(const void* p0, const void* p1) {
	int* i0 = (int*)p0;
	int* i1 = (int*)p1;
	return (*i0) - (*i1);
}

// ǰ�������������a[i];left��rightΪsorted��Ӧ�ĸ��������±귶Χ
void pre(int i, int left, int right) {
	if (left > right)
		return;
	// �������Ĵ�С
	int size_left_tree = (i * 2 <= N) ? subtree_nums[i * 2] : 0;
	// parent��ֵ
	a[i] = sorted[left + size_left_tree];

	pre(i * 2, left, left + size_left_tree - 1);
	pre(i * 2 + 1, left + size_left_tree + 1, right);
}

int main() {
	scanf("%d", &N);

	int i;
	for (i = 1; i <= N; ++i)
		scanf("%d", sorted + i);
	// ��С����
	qsort(sorted + 1, N, sizeof(int), cmp);
	
	// ���� subtree_nums���Ѿ���ʼ��Ϊ0
	for (i = N; i >= 0; --i) {
		if (2 * i <= N)  // ������
			subtree_nums[i] += subtree_nums[2 * i];
		if (2 * i + 1 <= N)  // ������
			subtree_nums[i] += subtree_nums[2 * i + 1];
		// parent�ڵ�����
		++subtree_nums[i];
	}
	
	pre(1, 1, N);

	printf("%d", a[1]);
	for (i = 2; i <= N; ++i)
		printf(" %d", a[i]);

	system("pause");
	return 0;
}