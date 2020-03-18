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

// 个位
string digits_1[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
// 十位
string digits_10[13] = { "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };


int main() {
	int N;
	cin >> N;

	string strs[2];
	int num;

	int i, h;
	// 个位，十位
	int num_1, num_10;

	map<string, int>converter;
	for (i = 0; i < 13; ++i) {
		converter[digits_1[i]] = i;
		converter[digits_10[i]] = i * 13;
	}

	for (i = 0; i < N; ++i) {
		h = 0;
		do {
			cin >> strs[h++];
		} while (cin.get() != '\n');
		if (isdigit(strs[0][0])) {
			sscanf(strs[0].c_str(), "%d", &num);
			num_10 = num / 13;
			num_1 = num % 13;

			if (num_10) {
				printf("%s", digits_10[num_10].c_str());
				// 看题目 13->tam 不输出个位的0
				if (num_1)
					printf(" %s", digits_1[num_1].c_str());
				printf("\n");
			}
			else
				printf("%s\n", digits_1[num_1].c_str());

		}
		else {
			num = 0;
			for (h -= 1; h >= 0; --h)
				num += converter[strs[h]];
			printf("%d\n", num);
		}
	}
		

	system("pause");
	return 0;
}