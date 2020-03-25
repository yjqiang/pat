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
#include <unordered_map>

using namespace std;

#define N_MAX 1001
int N;

// ����������У���1��ʼ��
int level[N_MAX];

// index Ϊ�����ĸ���level���±꣨��ȫ��������Ŵ�1��ʼ��
bool isMaxHeap() {
	int i;
	// �Ƚϸýڵ��븸�ڵ��С
	for (i = N; i >= 2; --i)
		if (level[i / 2] < level[i])
			return false;
	return true;
}

// index Ϊ�����ĸ���level���±꣨��ȫ��������Ŵ�1��ʼ��
bool isMinHeap() {
	int i;
	// �Ƚϸýڵ��븸�ڵ��С
	for (i = N; i >= 2; --i)
		if (level[i / 2] > level[i])
			return false;
	return true;
}

bool is_first;
// ת����ȫ�������Ĳ������Ϊ�������
// index Ϊ�����ĸ���level���±꣨��ȫ��������Ŵ�1��ʼ��
void post(int index) {
	if (index > N)
		return;

	// ������
	int left = index * 2;
	post(left);

	// ������
	int right = index * 2 + 1;
	post(right);

	if (is_first) {
		printf("%d", level[index]);
		is_first = false;
	}
	else
		printf(" %d", level[index]);
}

int main() {
	int M;
	scanf("%d%d", &M, &N);

	int i, h;
	for (i = 0; i < M; ++i) {
		for (h = 1; h <= N; ++h)
			scanf("%d", level + h);

		if (isMaxHeap())
			printf("Max Heap\n");
		else if (isMinHeap())
			printf("Min Heap\n");
		else
			printf("Not Heap\n");

		is_first = true;
		post(1);
		printf("\n");

	}

	system("pause");
	return 0;
}