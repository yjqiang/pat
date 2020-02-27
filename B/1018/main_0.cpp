#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
# include <climits>
#include <cstring>
#include <map>
#include <cstdio>
#include <queue>

using namespace std;


int main() {
	int N;
	char as[2], bs[2];
	char a, b;
	int scores[2][3] = { 0 };  // 0win 1draw 2loss
	int statistic[2][3] = { 0 };  // 0B 1C  2J
	map<char, int> m;
	m['B'] = 0;
	m['C'] = 1;
	m['J'] = 2;
	char m0[] = "BCJ";

	scanf("%d", &N);
	
	int index;
	for (index = 0; index < N; ++index) {
		scanf("%s %s", as, bs);
		a = as[0];
		b = bs[0];

		if (a == b) {
			++scores[0][1];
			++scores[1][1];
		}
		else if (a == 'B' && b == 'C' || a == 'C' && b == 'J' || a == 'J' && b == 'B') {
			++scores[0][0];
			++scores[1][2];
			++statistic[0][m[a]];
		}
		else {
			++scores[0][2];
			++scores[1][0];
			++statistic[1][m[b]];
		}
	}

	

	printf("%d %d %d\n%d %d %d\n",
		scores[0][0],
		scores[0][1],
		scores[0][2],
		scores[1][0],
		scores[1][1],
		scores[1][2]);

	int max_element, max_index;
	max_element = -1;
	for (index = 0; index < 3;++index)
		if (statistic[0][index] > max_element) {
			max_element = statistic[0][index];
			max_index = index;
		}
	printf("%c ", m0[max_index]);

	max_element = -1;
	for (index = 0; index < 3; ++index)
		if (statistic[1][index] > max_element) {
			max_element = statistic[1][index];
			max_index = index;
		}
	printf("%c", m0[max_index]);
	

	system("pause");

	
	return 0;
}