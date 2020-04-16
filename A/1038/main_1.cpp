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
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;


#define N_MAX 10000


vector<string> strings;

bool cmp(string& a, string& b) {
	return a + b < b + a;
}

int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;

	int i;
	string s;
	for (i = 0; i < N; ++i) {
		cin >> s;
		strings.push_back(s);
	}

	sort(strings.begin(), strings.end(), cmp);

	string result;
	for (i = 0; i < N; ++i)
		result += strings[i];

	// remove the zeros at the beginning
	int n_size = result.size();
	for (i = 0; i < n_size && result[i] == '0'; ++i);

	if (i == n_size)
		printf("0");
	else
		for (; i < n_size; ++i)
			printf("%c", result[i]);

	system("pause");
	return 0;
}