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

#define N_MAX 30

int pre[N_MAX];
int in[N_MAX];

int post[N_MAX];
// �±�ָʾ
int i_post = 0;

// root Ϊ�������ĸ���pre������±�
// start endΪ��������in����ķ�Χ
void check(int root, int start, int end) {
	if (start > end)
		return;

	int i;
	for (i = 0; in[i] != pre[root]; ++i);

	check(root + 1, start, i - 1);
	check(i + root - start + 1, i + 1, end);
	post[i_post++] = pre[root];
}

int main() {
	int N;
	scanf("%d", &N);
	int double_N = 2 * N;

	char command[5];

	int i;

	// �±�ָʾ
	int i_pre = 0, i_in = 0;
	int value;
	stack<int>s;
	// ���ݱ����ǵݹ���ʽ��д��
	for (i = 0; i < double_N; ++i) {
		scanf("%s", command);
		// Pop
		if (command[1] == 'o') {
			in[i_in++] = s.top();
			s.pop();
		}
		// Push
		else {
			scanf("%d", &value);
			pre[i_pre++] = value;
			s.push(value);
		}
			
	}

	check(0, 0, N - 1);
	printf("%d", post[0]);
	for (i = 1; i < N; ++i)
		printf(" %d", post[i]);

	system("pause");
	return 0;
}