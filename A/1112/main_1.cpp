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

char s[1001];

// һ�������ģ�����n*k��һ��û����
bool normal[128] = { false };

// ��ӡ��ס�ļ���ʱ��ֻ��ӡһ�ξͿ�����
bool duplicate[128] = { false };


int main() {
	int k;
	scanf("%d %s", &k, s);

	char c;
	int i, h;
	int start;  // �ظ��ַ�������ʼλ��(�ظ�����Ϊ1Ҳ��������)
	int len; // �ظ��ַ�������

	for (i = 0; s[i] != '\0';) {
		start = i;
		c = s[i];
		for (++i; s[i] != '\0' && s[i] == c; ++i);

		len = i - start;
		if (len % k != 0)
			normal[c] = true;
	}

	for (i = 0; s[i] != '\0';) {
		start = i;
		c = s[i];
		for (++i; s[i] != '\0' && s[i] == c; ++i);

		len = i - start;
		// δ��normal��������Ŀ���
		if (!normal[c])
			if (!duplicate[c]) {
				duplicate[c] = true;
				printf("%c", c);
			}
			
	}
	printf("\n");
	for (i = 0; s[i] != '\0';) {
		start = i;
		c = s[i];
		for (++i; s[i] != '\0' && s[i] == c; ++i);

		len = i - start;
		// δ��normal��������Ŀ���
		if (!normal[c])
			len = len / k;  // ��ӡ�����ĸ���/k == ʵ�ʵĸ���

		for (h = 0; h < len; ++h)
			printf("%c", c);
	}

	system("pause");
	return 0;
}