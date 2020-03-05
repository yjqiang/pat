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

#define N_MAX 10001

string a[N_MAX];

bool cmp(string &x, string &y) {
	return x + y < y + x;
}

int main() {
	int N;
	cin >> N;

	int i;
	for (i = 0; i < N; ++i)
		cin >> a[i];

	sort(a, a + N, cmp);

	int k;
	// 开头不该打印0
	bool should_zore_be_print = false;
	string result;
	for (i = 0; i < N; ++i)
		result += a[i];
	
	for (i = 0; result[i] == '0' && i < result.size(); ++i);
	
	if (i == result.size())
		printf("0");
	else {
		for (; i < result.size(); ++i)
			printf("%c", result[i]);
	}
		
	system("pause");
	return 0;
}