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

string name;
// 防止重复中奖
set<string> lucky_dogs;

int main() {
	int M, N, S;
	cin >> M >> N >> S;

	// 下一个幸运儿的下标
	int next_lucky_dog = S;
	int i;
	for (i = 1; i <= M; ++i) {
		cin >> name;
		if (i == next_lucky_dog) {
			if (lucky_dogs.find(name) == lucky_dogs.end()) {
				printf("%s\n", name.c_str());
				next_lucky_dog += N;
				lucky_dogs.insert(name);
			}
			else
				// 重复中奖的跳过，等下一个人
				++next_lucky_dog;
		}
	}

	// M未超过S，一定没有中奖的
	// 否则，一定有中奖
	if (M < S)
		printf("Keep going...");

	system("pause");
	return 0;
}