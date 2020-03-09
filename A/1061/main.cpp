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

char days[7][4] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

#define N_MAX 61
char a[N_MAX];
char b[N_MAX];

int main() {
	int day, hour, minute;
	scanf("%s%s", a, b);

	int i;
	char c0, c1;
	for (i = 0; a[i] != '\0' && b[i] != '\0'; ++i) {
		c0 = a[i];
		c1 = b[i];
		// 根据最终范围，看c0范围sb
		if (c0 == c1 && c0 <= 'G' && c0 >= 'A') {
			// A 对应 MON
			day = c0 - 'A';
			break;
		}
	}
	++i;
	// 接着上面的i继续
	for (; a[i] != '\0' && b[i] != '\0'; ++i) {
		c0 = a[i];
		c1 = b[i];
		// 根据最终范围，看c0范围sb
		if (c0 == c1 && (c0 <= 'N' && c0 >= 'A' || isdigit(c0))) {
			if (!isdigit(c0))
				hour = c0 - 'A' + 10;
			else
				hour = c0 - '0';
			break;
		}
	}

	scanf("%s%s", a, b);
	for (i = 0; a[i] != '\0' && b[i] != '\0'; ++i) {
		c0 = a[i];
		c1 = b[i];
		if (c0 == c1 && isalpha(c0)) {
			minute = i;
			break;
		}
	}
	printf("%s %02d:%02d", days[day], hour, minute);


	system("pause");
	return 0;
}