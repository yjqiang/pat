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

// ��¼�������������˳��
int position = 1;

int cmp(const void* p0, const void* p1) {
	int* i0 = (int*)p0;
	int* i1 = (int*)p1;
	return (*i0) - (*i1);
}

// �б�����������a[i]
void mid(int i) {
	if (i > N)
		return;
	mid(2 * i);
	a[i] = sorted[position++];
	mid(2 * i + 1);
}

int main() {
	scanf("%d", &N);

	int i;
	for (i = 1; i <= N; ++i)
		scanf("%d", sorted + i);
	// ��С����
	qsort(sorted + 1, N, sizeof(int), cmp);
	
	mid(1);

	printf("%d", a[1]);
	for (i = 2; i <= N; ++i)
		printf(" %d", a[i]);

	system("pause");
	return 0;
}