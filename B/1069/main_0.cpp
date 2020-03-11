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

// �û������н�����(ֻ¼���н��ߵ�)
map<string, int>cache;

int main() {
	int M, N, S;
	cin >> M >> N >> S;
	cin.get();

	string s;
	int i;
	int next_lucky_dog;
	bool no_lucky_dog = true;
	for (i = 1, next_lucky_dog = S; i <= M; ++i) {
		getline(cin, s);
		
		if (next_lucky_dog == i) {
			// ����û¼��
			if (cache.find(s) == cache.end()) {
				printf("%s\n", s.c_str());
				no_lucky_dog = false;
				cache[s] = 1;
				next_lucky_dog += N;
			}
			else {
				++next_lucky_dog;
			}
		}
	}

	if (no_lucky_dog)
		printf("Keep going...");

	system("pause");
	return 0;
}