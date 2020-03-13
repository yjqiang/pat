#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <cmath>
#include <climits>
#include <queue>
#include <set>

using namespace std;

#define N_MAX 1001

char type;
char orig_data[N_MAX];

int main() {
	ios::sync_with_stdio(false);
	cin >> type;
	// 去除\n
	cin.get();
	cin.getline(orig_data, N_MAX);

	int i;
	char cur_char;
	if (type == 'C') {
		int start, end;
		for (i = 0; orig_data[i] != '\0'; ) {
			cur_char = orig_data[i];
			start = i;
			for (i += 1; orig_data[i] != '\0' && orig_data[i] == cur_char; ++i);
			end = i;
			// 无法压缩（就一个）
			if (end - start == 1)
				printf("%c", cur_char);
			else
				printf("%d%c", end - start, cur_char);
		}
	}
	else {
		int sum;
		int h;
		for (i = 0; orig_data[i] != '\0'; ++i) {
			cur_char = orig_data[i];
			if (isdigit(cur_char)) {
				sum = 0;
				// 数字部分一定不会到达\0
				for (; isdigit(orig_data[i]); ++i)
					sum = sum * 10 + orig_data[i] - '0';
			}
			else
				sum = 1;  // 可以认为1默认

			cur_char = orig_data[i];
			for (h = 0; h < sum; ++h)
				printf("%c", cur_char);
		}

	}

	
	system("pause");
	return 0;
}