#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <cmath>
#include <climits>
#include <queue>
#include <set>

using namespace std;


char s[81];

void judge() {
	int i;
	int len;
	char c;
	bool is_digit_exist, is_alpha_exist;

	len = strlen(s);
	if (len < 6) {
		printf("Your password is tai duan le.\n");
		return;
	}

	is_digit_exist = is_alpha_exist = false;
	for (i = 0; i < len; ++i) {
		c = s[i];
		if (isdigit(c))
			is_digit_exist = true;
		else if (isalpha(c))
			is_alpha_exist = true;
		else if (c != '.') {
			printf("Your password is tai luan le.\n");
			return;
		}
	}
	if (is_alpha_exist && !is_digit_exist) {
		printf("Your password needs shu zi.\n");
		return;
	}

	if (!is_alpha_exist && is_digit_exist) {
		printf("Your password needs zi mu.\n");
		return;
	}

	if (is_alpha_exist && is_digit_exist)
		printf("Your password is wan mei.\n");
}

int main() {
	int N;
	cin >> N;
	// È¥³ý\n
	cin.get();

	int i;
	for (i = 0; i < N; ++i) {
		cin.getline(s, 81);
		judge();
	}
		
	
	system("pause");
	return 0;
}