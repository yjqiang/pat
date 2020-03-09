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

using namespace std;

// ��λ����С����
#define LEN_MAX 110

char A[LEN_MAX];
char B[LEN_MAX];

// kΪ0.d[1]...d[N] * 10^k���Ǹ�k
// ����ֵΪ0.00xxxx  ɾ����λ0��.���λ��������Чλ��
int findDecimalPoint(char* p, int n, int& k) {
	int i;

	// С�����λ��(������С����������'\0'��)
	for (i = 0; i < n && p[i] != '.'; ++i);
	int point = i;

	// �Ӹ�λ��ʼ����һ����0��index
	int index = -1;
	for (i = 0; i < n; ++i)
		if (isdigit(p[i]) && p[i] != '0') {
			index = i;
			break;
		}
	// ������־���0
	if (index == -1) {
		k = 0;
		return 0;
	}

	// ɾ��indexǰ���0���Լ�ɾ��С����
	int j;
	for (i = index, j = 0; i < n; ++i)
		if (p[i] != '.') {
			p[j] = p[i];
			++j;
		}
	// ԭ��Ϊ 0.001xxx ��ʽ
	if (index > point)
		k = point - index + 1;
	else // ԭ��Ϊ 10.111 ��ʽ
		k = point - index;
	return j;
}

int main() {
	int N;
	scanf("%d %s %s", &N, A, B);

	
	int n_A, n_B;
	int k_A, k_B;
	n_A = findDecimalPoint(A, strlen(A), k_A);
	n_B = findDecimalPoint(B, strlen(B), k_B);

	// ����N��ȡ���������0
	int i;
	// ��鿴�Ƿ���Ҫ��0
	for (i = 0; i < N; ++i) {
		if (i >= n_A)
			A[i] = '0';
		if (i >= n_B)
			B[i] = '0';
	}
	// �ضϼ�ֹͣ����
	A[N] = '\0';
	B[N] = '\0';

	if (k_A == k_B && !strcmp(A, B))
		printf("YES 0.%s*10^%d", A, k_A);
	else
		printf("NO 0.%s*10^%d 0.%s*10^%d", A, k_A, B, k_B);

	system("pause");
	return 0;
}