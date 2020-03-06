#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>

#include <climits>
#include <cstdio>
#include <queue>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

#define N_MAX 1000
int N;
int pre[N_MAX];
// �����������������������ǵ���
int sorted[N_MAX];
// ��������������������ǵݼ�
int revert_sorted[N_MAX];

vector<int> post;

int cmp(const void* p0, const void* p1) {
	int* a = (int*)p0;
	int* b = (int*)p1;
	return (*a) - (*b);
}

//  ������������������������������ʱ�򣬶�Ӧroot���ظ���Ԫ�أ�һ��ѡ�����ģ���������������Ԫ����root��ȵģ�������Ҫ��
bool checkPost_sorted(int root, int start, int end) {
	if (start > end)
		return true;
	int i;
	for (i = start; i <= end; ++i)
		if (sorted[i] == pre[root]) {

			if (checkPost_sorted(root + 1, start, i - 1) && checkPost_sorted(root + i + 1 - start, i + 1, end)) {
				// ����+ǰ�� ���ܶ���� eg�� 1 1 1 1 1��1 1 1 1 1
				post.push_back(pre[root]);
				return true;			
			}
			return false;
		}
	return false;
}

//  ������������������������������ʱ�򣬶�Ӧroot���ظ���Ԫ�أ�һ��ѡ���Ҳ�ģ���������������Ԫ����root��ȵģ�������Ҫ��
bool checkPost_revert_sorted(int root, int start, int end) {
	if (start > end)
		return true;
	int i;
	for (i = end; i >= start; --i)
		if (revert_sorted[i] == pre[root]) {
			if (checkPost_revert_sorted(root + 1, start, i - 1) && checkPost_revert_sorted(root + i + 1 - start, i + 1, end)) {
				// ����+ǰ�� ���ܶ���� eg�� 1 1 1 1 1��1 1 1 1 1
				post.push_back(pre[root]);
				return true;
			}
			return false;
		}
	return false;
}

int main() {

	scanf("%d", &N);

	int i;
	int num;
	for (i = 0; i < N; ++i) {
		scanf("%d", &num);
		pre[i] = num;
		sorted[i] = num;
	}
	qsort(sorted, N, sizeof(int), cmp);
	for (i = 0; i < N; ++i)
		revert_sorted[N - 1 - i] = sorted[i];


	if (checkPost_sorted(0, 0, N - 1)) {
		printf("YES\n");
		printf("%d", post[0]);
		for (i = 1; i < post.size(); ++i)
			printf(" %d", post[i]);
		system("pause");
		return 0;
	}
	post.clear();
	if (checkPost_revert_sorted(0, 0, N - 1)) {
		printf("YES\n");
		printf("%d", post[0]);
		for (i = 1; i < post.size(); ++i)
			printf(" %d", post[i]);
		system("pause");
		return 0;
	}
	printf("NO\n");

	system("pause");
	return 0;
}