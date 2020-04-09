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

#define N_MAX 201
#define M_MAX 200
#define L_MAX 10000

// ������ĵ�һ�������Ԫ��ֵӳ��Ϊ����˳�������Ͱ���Ŀת��Ϊ������Ӵ�
// Ĭ��Ϊ 0����ʾû�����
int books[N_MAX] = { 0 };

int nums[L_MAX];

// dp[i]��ʾ��iΪ��β��������Ӵ��ĳ���
int dp[L_MAX];

int main() {
	int N, M, L;

	scanf("%d %d", &N, &M);

	int i, h;
	int num;
	for (i = 1; i <= M; ++i) {
		scanf("%d", &num);
		books[num] = i;
	}

	scanf("%d", &L);
	for (i = 0, h = 0; i < L; ++i) {
		scanf("%d", &num);
		// ���˵���Щ������Ҫ���������Ԫ��
		if (books[num])
			nums[h++] = books[num];
	}
	// ����L����
	L = h;



	int result = -1;

	// ÿ��ѭ����������dp[i]
	for (i = 0; i < L; ++i) {
		dp[i] = 1; // ��Ϊ����������Ӵ�ֻ�б���һ��Ԫ��
		for (h = 0; h < i; ++h)
			// ������dp[h]��Ӧ�Ӵ��Ļ����ϣ�������չ
			if (nums[i] >= nums[h])
				dp[i] = max(dp[i], dp[h] + 1);

		result = max(dp[i], result);
	}

	printf("%d", result);
	system("pause");
	return 0;
}