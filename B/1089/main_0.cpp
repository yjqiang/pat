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

using namespace std;

#define N_MAX 101

int N;
// 记下说的话
int words[101];

int findLiars(int wolf0, int wolf1, bool& is_liar_wolf0, bool& is_liar_wolf1) {
	int i, person;
	int num_liars = 0;
	bool is_liar;
	for (i = 1; i <= N; ++i) {
		person = abs(words[i]);
		// i 说对方是好人，且对了 || i 说对方是狼人且，对了
		is_liar = (words[i] > 0 && person != wolf0 && person != wolf1) || (words[i] < 0 && (person == wolf0 || person == wolf1)) ? false : true;

		// printf("=> %d %d %d\n", i, words[i], is_liar);
		if (wolf0 == i)
			is_liar_wolf0 = is_liar;
		if (wolf1 == i)
			is_liar_wolf1 = is_liar;
		if(is_liar)
			++num_liars;
	}
	return num_liars;
}

void myTry() {
	// 两个狼人的编号
	int i, k;

	bool is_liar_wolf0, is_liar_wolf1;
	int num_liars;

	for (i = 1; i <= N; ++i)
		for (k = i + 1; k <= N; ++k) {
			num_liars = findLiars(i, k, is_liar_wolf0, is_liar_wolf1);

			// printf("%d %d [%d] %d %d\n", i, k, num_liars, is_liar_wolf0, is_liar_wolf1);

			// 有2个撒谎的 且 一个好人撒谎一个狼人撒谎
			if (num_liars == 2 && (is_liar_wolf0 && !is_liar_wolf1 || !is_liar_wolf0 && is_liar_wolf1)) {
				printf("%d %d", i, k);
				return;
			}
		}
	printf("No Solution");
}

int main() {
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N; ++i)
		scanf("%d", words + i);
	myTry();
	
	system("pause");
	return 0;
}