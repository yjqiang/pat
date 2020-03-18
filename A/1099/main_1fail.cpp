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

#define N_MAX 101

struct Node {
	int value;
	int left_index, right_index;
	long long index;  // ���������ı�Ű취
};

Node nodes[N_MAX];
int nums[N_MAX];

int cmp_int(const void* p0, const void* p1) {
	int* a = (int*)p0;
	int* b = (int*)p1;
	return (*a) - (*b);
}

// ����2������index����
int cmp_index(const void* p0, const void* p1) {
	Node* a = (Node*)p0;
	Node* b = (Node*)p1;

	// indexһ������
	if (a->index < b->index)
		return -1;
	return 1;
}

// ָʾmid���±�
int count_mid = 0;
// root Ϊ��ǰ�����ĸ�
// index Ϊ���������ı�Ű취����1��ʼ
void mid(int root, long long index) {
	if (root == -1)
		return;

	mid(nodes[root].left_index, 2 * index);
	if (index > INT_MAX)
		exit(-1);
		
	nodes[root].value = nums[count_mid++];
	nodes[root].index = index;

	mid(nodes[root].right_index, 2 * index + 1);
}

int main() {
	int N;
	scanf("%d", &N);

	int i;
	for (i = 0; i < N; ++i) {
		scanf("%d%d", &(nodes[i].left_index), &(nodes[i].right_index));
		nodes[i].index = -1;
	}

	for (i = 0; i < N; ++i)
		scanf("%d", nums + i);

	// ��С�����nums����
	qsort(nums, N, sizeof(int), cmp_int);
	
	mid(0, 1);

	// ����level����
	qsort(nodes, N, sizeof(Node), cmp_index);

	

	printf("%d", nodes[0].value);
	for (i = 1; i < N; ++i)
		printf(" %d", nodes[i].value);
	
	system("pause");
	return 0;
}