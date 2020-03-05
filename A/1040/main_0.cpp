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

char special = '#';
char s[1005];
char T[2005];
int P[2005];

int main() {
	cin.getline(s, 1001);
	int n = strlen(s);

	int size_T = n * 2 + 1;
	int i;
	// ���# �������
	for (i = 0; i < n; ++i) {
		T[2 * i] = special;
		T[2 * i + 1] = s[i];
	}
	T[size_T - 1] = special;

	// ��ǰ���л��Ĵ����Ҷ˵��У����Ҷ�
	int R = 0;
	// ��Ӧ�����ĵ�
	int C = 0;

	int cur_R;

	int max_R = -1;
	int start = -1;

	for (i = 0; i < size_T; ++i) {
		// i < Rʱ��i����C�ĶԳƵ�i'һ������(>=0)
		// ��P[i']��Ӧ�İ뾶������C�ķ�Χ����cur_R��R-i����ʼ�����������P[i']��ʼ����
		if (i < R)
			cur_R = min(P[2 * C - i], R - i);
		else  // û����Ϣ����0��ʼ����
			cur_R = 0;

		++cur_R;
		for (; i - cur_R >= 0 && i + cur_R < size_T && T[i - cur_R] == T[i + cur_R]; ++cur_R);
		--cur_R;

		// �������Ҷ�
		if (i + cur_R > R) {
			R = i + cur_R;
			C = i;
		}
		// ���������Ĵ���cur_R �������İ뾶����ԭ���Ĵ����������ȣ�
		if (cur_R > max_R) {
			max_R = cur_R;
			// ���Ĵ���˵�һ���� # ����
			start = (i - cur_R) / 2;
		}

	}
	//for (i = start; i < start + max_R; ++i)
	//	printf("%c", s[i]);
	//printf("\n");
	printf("%d", max_R);

	system("pause");
	return 0;
}