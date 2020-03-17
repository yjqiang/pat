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

char s[100001];

long long count_left_P = 0;
long long count_right_T = 0;

int main() {
	scanf("%s", s);

	int i;
	long long result = 0;;

	for (i = 0; s[i] != '\0'; ++i)
		if (s[i] == 'T')
			++count_right_T;

	// count_right_T 的计算办法是T在s中总个数，减去从0到i处T个数
	for (i = 0; s[i] != '\0'; ++i){
		switch (s[i]) {
			case 'P': ++count_left_P; break;
			case 'T': --count_right_T; break;
			case 'A': result = (result + count_left_P * count_right_T) % 1000000007; break;
		}

	}
	printf("%lld", result);


	system("pause");
	return 0;
}