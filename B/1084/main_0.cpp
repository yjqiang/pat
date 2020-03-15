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

using namespace std;

#define LEN_MAX 100000

char s[LEN_MAX];
char tmp_s[LEN_MAX];

// value Ϊ����
// ���س��ȣ�������ʼ��ַ��ƫ������
int int2str(char* a, int value) {
	int i = 0;
	while (value) {
		a[i++] = value % 10 + '0';
		value /= 10;
	}

	int j;
	int result = i;
	for (i = 0, j = result - 1; i < j; ++i, --j)
		swap(a[i], a[j]);

	return result;
}

int main() {
	int N;
	scanf("%s%d", s, &N);

	int i, k;

	int count, start;
	char cur_value;

	// д���ݵ�ʱ���ָ��
	int index_tmp_s;

	for (i = 2; i <= N; ++i) {
		index_tmp_s = 0;
		// ���i�����ݣ�"d"Ϊ��һ�����ݣ�
		for (k = 0; s[k] != '\0';) {
			// ������Ƭ�ε���ʼλ�ã�����Ƭ�γ��ȿ���Ϊ1��
			start = k;
			cur_value = s[k];

			for (++k; s[k] != '\0' && s[k] == cur_value; ++k);
			// ����Ƭ�γ���
			count = k - start;

			// ¼��value
			tmp_s[index_tmp_s++] = cur_value;
			// ¼��count
			index_tmp_s += int2str(tmp_s + index_tmp_s, count);
		}
		tmp_s[index_tmp_s] = '\0';

		strcpy(s, tmp_s);
		// printf("%d %s\n", i, s);
	}

	printf("%s\n", s);

	system("pause");
	return 0;
}