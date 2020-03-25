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

#define N_MAX 101
int N;

int words[N_MAX];

// ��ǰ�����ɫ
// ÿ���û��ǲ���wolf, +1�����ǣ�-1����
int is_wolf[N_MAX];

bool is_liar[N_MAX];

void check() {
	int count_liars;
	int i, h, k;
	// i Ϊ����0��hΪ����1
	for (i = 1; i <= N; ++i)
		for (h = i + 1; h <= N; ++h) {
			// ���õ�ǰ�����ɫ
			for (k = 1; k <= N; ++k)
				is_wolf[k] = 1;
			is_wolf[i] = -1;
			is_wolf[h] = -1;

			count_liars = 0;

			for (k = 1; k <= N; ++k) {
				// ��k��˵�Ļ� �� ������ָ����(abs(words[k]))�Ľ�ɫ�Ƿ�һ��
				// (a >> 31) ^ (b >> 31)  ab�Ƿ���� 
				if ((is_wolf[abs(words[k])] >> 31) ^ (words[k] >> 31)) {
					++count_liars;
					is_liar[k] = true;
				}
				else
					is_liar[k] = false;
			}

			if (count_liars == 2 && is_liar[i] != is_liar[h]) {
				printf("%d %d", i, h);
				return;
			}

		}

	printf("No Solution");
}

int main() {
	scanf("%d", &N);

	int i;
	for (i = 1; i <= N; ++i)
		scanf("%d", words + i);

	// �鵽��ֱ��return�������һ��״̬(�Ƿ��ӡNo Solution)������
	check();

	system("pause");
	return 0;
}