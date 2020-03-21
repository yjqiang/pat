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

#define N_MAX 30


int pre[N_MAX];
int post[N_MAX];

vector<int> result;
bool is_duplicate = false;

void in(int root, int start, int end) {
	// root Ϊ�������ĸ���Ӧ��pre���±�
	// [start, end]Ϊ��������post�����ҷ�Χ

	if (start > end)
		return;
	// �޺��ӽڵ�
	if (start == end) {
		result.push_back(pre[root]);
		return;
	}

	int i;
	for (i = start; post[i] != pre[root + 1]; ++i);
	// ��break forѭ����ʱ��i==end-1�������[start, end-1]ȫ��root���������������������Ͷ����

	if (i == end - 1)
		is_duplicate = true;

	in(root + 1, start, i);
	result.push_back(pre[root]);
	in(i - start + root + 2, i + 1, end - 1);
}

int main() {
	int N;
	scanf("%d", &N);
	
	int i;
	
	for (i = 0; i < N; ++i)
		scanf("%d", pre + i);
	for (i = 0; i < N; ++i)
		scanf("%d", post + i);
	

	in(0, 0, N - 1);

	if (is_duplicate)
		printf("No\n");
	else
		printf("Yes\n");

	printf("%d", result[0]);
	for (i = 1; i < N; ++i)
		printf(" %d", result[i]);
		
	printf("\n");
	system("pause");
	return 0;
}