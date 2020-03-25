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
bool isMaxHeap(int index) {
	// ������
	int left = index * 2;
	if (left <= N && !isMaxHeap(left))
		return false;

	// ������
	int right = index * 2 + 1;
	if (right <= N && !isMaxHeap(right))
		return false;

	// ���ڵ�
	return (right > N || level[index] >= level[right]) &&
		(left > N || level[index] >= level[left]);
}

// index Ϊ�����ĸ���level���±꣨��ȫ��������Ŵ�1��ʼ��
bool isMinHeap(int index) {
	// ������
	int left = index * 2;
	if (left <= N && !isMinHeap(left))
		return false;

	// ������
	int right = index * 2 + 1;
	if (right <= N && !isMinHeap(right))
		return false;

	// ���ڵ�
	return (right > N || level[index] <= level[right]) &&
		(left > N || level[index] <= level[left]);
}

bool is_first;
// ת����ȫ�������Ĳ������Ϊ�������
void post(int index) {
	int left = index * 2;
	if (left <= N)
		post(left);

	// ������
	int right = index * 2 + 1;
	if (right <= N)
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

		if (isMaxHeap(1))
			printf("Max Heap\n");
		else if (isMinHeap(1))
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