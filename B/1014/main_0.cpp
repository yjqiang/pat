# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
# include <climits>
#include <cstring>
#include <map>
#include <cstdio>

using namespace std;

int main() {
	char week[7][4] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

	char s0[61], s1[61];
	char c0, c1;
	scanf("%s%s", s0, s1);
	int i;
	for (i = 0;; ++i) {
		c0 = s0[i];
		c1 = s1[i];
		if (c0 == c1 && c0 >= 'A' && c0 <= 'G') {
			printf("%s ", week[c0 - 'A']);
			break;
		}
			
	}
	++i;
	for (;; ++i) {
		c0 = s0[i];
		c1 = s1[i];
		if (c0 == c1 && (c0 >= 'A' && c0 <= 'N' || c0 >= '0' && c0 <= '9')) {
			printf("%02d:", (c0 <= '9' && c0 >= '0') ? c0 - '0' : c0 - 'A' + 10);
			break;
		}
			
	}

	scanf("%s%s", s0, s1);
	for (i = 0;; ++i) {
		c0 = s0[i];
		c1 = s1[i];
		if (c0 == c1 && (c0 >= 'A' && c0 <= 'Z' || c0 >= 'a' && c0 <= 'z')) {
			printf("%02d", i);
			break;
		}
			
	}

	system("pause");
	return 0;
}