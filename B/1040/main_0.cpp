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

char s[100001];

int main() {
	scanf("%s", s);

	int result = 0;

	// s[0...i]��Χ��P�ĸ�����A������PA����;A��������ͳ��
	int Pi = 0;
	// PAi ������� (5 * 10^4)^2 = 2.5 * 10* 9
	long long PAi = 0;
	
	int i;
	for (i = 0; s[i] != '\0'; ++i) {
		switch (s[i])
		{
			case 'P': ++Pi; break;
			case 'A': PAi += Pi; break;
			// ��ĿҪ��ģ�����ģ����
			case 'T': result = int((PAi + result) % 1000000007); break;
		}
	}

	printf("%d", result);
	system("pause");
	return 0;
}