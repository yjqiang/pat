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

// ����ascii��ͳ��
int counts[128] = { 0 };

int main() {
	scanf("%s", s);

	int i;
	// ͳ�Ƹ��������е�ͳ������
	for (i = 0; s[i] != '\0'; ++i)
		++counts[s[i]];

	// �۳���Ҫ����һ����
	scanf("%s", s);
	for (i = 0; s[i] != '\0'; ++i)
		--counts[s[i]];

	int more, less;
	int value;

	more = less = 0;
	for (i = 0; i < 128; ++i) {
		value = counts[i];
		if (value < 0)
			less += -value;
		else if (value > 0)
			more += value;
	}

	if (less == 0)
		printf("Yes %d", more);
	else
		printf("No %d", less);
		
	system("pause");
	return 0;
}