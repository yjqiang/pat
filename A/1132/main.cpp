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
#include <unordered_map>

using namespace std;


string s, s1, s2;

int main() {
	int N;
	scanf("%d", &N);

	int i;

	int Z, A, B;
	int half_len;
	for (i = 0; i < N; ++i) {
		cin >> s;
		half_len = s.size() / 2;
		s1 = s.substr(0, half_len);
		s2 = s.substr(half_len, half_len);

		A = atoi(s1.c_str());
		B = atoi(s2.c_str());
		Z = atoi(s.c_str());

		if (A * B != 0 && Z % (A * B) == 0)
			printf("Yes\n");
		else
			printf("No\n");
	}

	
	system("pause");
	return 0;
}