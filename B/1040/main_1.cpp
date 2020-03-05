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

	// s[0...i]��Χ��P�ĸ�����T������PA����
	long long Pi = 0;
	long long Ti = 0;
	
	int i;
	for (i = 0; s[i] != '\0'; ++i)
		if (s[i] == 'T')
			++Ti;


	for (i = 0; s[i] != '\0'; ++i) {
		switch (s[i])
		{
			case 'P': ++Pi; break;
			// ��ĿҪ��ģ�����ģ����
			case 'A': result = int((Pi * Ti + result) % 1000000007); break;
			
			case 'T': --Ti; break;
		}
	}

	printf("%d", result);
	system("pause");
	return 0;
}