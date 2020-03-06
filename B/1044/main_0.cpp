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

char str_mars_10[13][5] = { "tret" , "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
char str_mars_1[13][5] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };

bool isEarth(string& s) {
	return s[0] <= '9' && s[0] >= '0';
}

int str2int(string& s) {
	int n = s.size();
	int i;
	int result = 0;
	for (i = 0; i < n; ++i)
		result = result * 10 + s[i] - '0';

	return result;
}


int main() {
	int N;
	
	int i;
	string s;
	string strs[2];
	map<string, int> map_mars;
	for (i = 0; i < 13; ++i) {
		s = str_mars_1[i];
		map_mars[s] = i;

		s = str_mars_10[i];
		// tam -> 13 这里和13进制不一样的
		map_mars[s] = i * 13;
	}

	cin >> N;
	int h, g;
	int result;
	// 火星十位，火星个位
	int int_mars_10, int_mars_1;
	for (i = 0; i < N; ++i) {
		h = 0;
		do {
			cin >> strs[h];
			++h;
		} while (cin.get() != '\n');
		if (isEarth(strs[0])) {
			result = str2int(strs[0]);
			int_mars_10 = result / 13;
			int_mars_1 = result % 13;
			// 高位为0，低位一定输出
			if (!int_mars_10)
				printf("%s\n", str_mars_1[int_mars_1]);
			else {
				printf("%s", str_mars_10[int_mars_10]);
				// 这里题目中，tam -> 13，低位为0， 不输出的
				if (int_mars_1)
					printf(" %s", str_mars_1[int_mars_1]);
				printf("\n");
			}
		}
		else {
			result = 0;
			for (g = 0; g < h; ++g)
				result += map_mars[strs[g]];
			
			printf("%d\n", result);
				
		}
	}


	system("pause");
	return 0;
}