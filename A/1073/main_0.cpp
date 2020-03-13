// https://www.liuchuo.net/archives/4216
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
#define N_MAX 10005

void revert(char* s, int n) {
	int i, j;
	for (i = 0, j = n - 1; i < j; ++i, --j)
		swap(s[i], s[j]);
}

// 原输入
char orig[N_MAX];
// 删除了符号、小数点、E以及后面数字的纯数
char pure_num[N_MAX];


int main() {
	int n_pure_num;

	scanf("%s", orig);
	if (orig[0] == '-')
		printf("-");

	int i;
	// E字符的下标
	int i_E;
	// x.xxx * 10^E
	int E;

	for (i = 2; orig[i] != 'E'; ++i);
	i_E = i;
	sscanf(orig + i_E, "E%d", &E);
	
	// 把符号之类的全部去掉
	for (n_pure_num = 0, i = 0; i < i_E; ++i)
		if (isdigit(orig[i])) {
			pure_num[n_pure_num] = orig[i];
			++n_pure_num;
		}
	
	// 前面补充0
	if (E < 0) {
		// 补充|E| - 1个0
		E = -E - 1;
		printf("0.");
		for (i = 0; i < E; ++i)
			printf("0");
		printf("%s", pure_num);
	}
	else if (E == 0) {
		printf("%c.%s", pure_num[0], pure_num + 1);
	}
	else {
		// 小数部分长度大于E，结果还有小数点
		if (n_pure_num - 1 > E) {
			for (i = 0; i <= E; ++i)
				printf("%c", pure_num[i]);

			printf(".");
			printf("%s", pure_num + E + 1);
		}
		// 无小数点
		else {
			printf("%s", pure_num);
			// 后面补充0
			int n_zero = E - (n_pure_num - 1);
			for (i = 0; i < n_zero; ++i)
				printf("0");
		}
	}

	system("pause");
	return 0;
}