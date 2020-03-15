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


string s;
string tmp_s;

int main() {
	int N;
	cin >> s >> N;

	int i, k;

	int count, start;
	char cur_value;

	int n_size;

	for (i = 2; i <= N; ++i) {
		tmp_s = "";
		n_size = s.size();
		// 求第i个数据（"d"为第一个数据）
		for (k = 0; k < n_size;) {
			// 本连续片段的起始位置（连续片段长度可以为1）
			start = k;
			cur_value = s[k];

			for (++k; k < n_size && s[k] == cur_value; ++k);
			// 连续片段长度
			count = k - start;

			// 录入
			tmp_s += cur_value + to_string(count);
		}

		s = tmp_s;
	}

	printf("%s\n", s.c_str());

	system("pause");
	return 0;
}