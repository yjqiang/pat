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

// 代表ascii码
bool is_exists[128] = { false };

int main() {
	string a, b;

	cin >> a >> b;

	int i;
	int n_size;

	n_size = b.size();
	for (i = 0; i < n_size; ++i)
		is_exists[toupper(b[i])] = true;

	char tmp;
	n_size = a.size();
	for (i = 0; i < n_size; ++i) {
		tmp = toupper(a[i]);
		if (!is_exists[tmp]) {
			printf("%c", tmp);
			// 不重复打印
			is_exists[tmp] = true;
		}
	}
		 

	system("pause");
	return 0;
}