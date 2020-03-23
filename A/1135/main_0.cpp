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

#define N_MAX 30
int K, N;

int pre[N_MAX];
int in[N_MAX];

bool result;

// root Ϊ�������ĸ���pre���±�
// [start, end] Ϊ��������in�ķ�Χ
// count_black Ϊ�������ĸ�����׺���ڵ㣨NULL����·���ϣ��ڽڵ���Ŀ
// is_black ��ʾ�������ĸ�����ɫ
void check(int root, int start, int end, int& count_black, bool& is_black) {
	// NULL �ڵ�
	if (start > end) {
		count_black = 1;
		is_black = true;
		return;
	}

	int left_count_black;
	bool left_is_black;
	int right_count_black;
	bool right_is_black;
	int i;
	for (i = start; i <= end && in[i] != pre[root]; ++i);
	if (i > end) {
		result = false;
		return;
	}

	check(root + 1, start, i - 1, left_count_black, left_is_black);

	check(root + i + 1 - start, i + 1, end, right_count_black, right_is_black);

	// ��ɫ�ڵ�ĺ�����ɫ�к�ɫ��
	if (pre[root] < 0 && (!left_is_black || !right_is_black))
		result = false;

	// ĳ�㵽����NULL��·���ϵĺ�ɫ����Ŀ��һ��
	if (left_count_black != right_count_black)
		result = false;

	if (pre[root] < 0) {
		is_black = false;
		count_black = left_count_black;
	}
	else {
		is_black = true;
		count_black = left_count_black + 1;
	}

	// printf("%d count_black: %d  is_black: %d\n", pre[root], count_black, is_black);
}

// ����ֵ����
int cmp(const void* p0, const void* p1) {
	int* a = (int*)p0;
	int* b = (int*)p1;
	return abs(*a) - abs(*b);
}

int main() {
	scanf("%d", &K);

	int i, h;
	bool is_black;
	int count_black;
	for (i = 0; i < K; ++i) {
		scanf("%d", &N);
		for (h = 0; h < N; ++h) {
			scanf("%d", pre + h);
			in[h] = pre[h];
		}

		qsort(in, N, sizeof(int), cmp);
		result = true;
		check(0, 0, N - 1, count_black, is_black);
		// ��Ϊ��
		if (result && is_black)
			printf("Yes\n");
		else
			printf("No\n");

	}


	system("pause");
	return 0;
}