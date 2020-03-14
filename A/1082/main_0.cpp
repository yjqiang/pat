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

char nums[10][6] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };

char group_elements[4][5] = { "", "Shi", "Bai", "Qian" };
char groups[3][4] = {"", "Wan", "Yi" };

// 按照0|3210|3210切割输入
// 每一组4个数字，几千几百几十几
// 打印完每组的数字之后，再根据第几组，打印 亿/万/none
char s[11];

int main(){
	
	scanf("%s", &s);

	int i;

	bool is_first;

	if (s[0] == '-') {
		printf("Fu");
		i = 1;
		is_first = false;
	}
	else {
		i = 0;
		is_first = true;
	}

	int n_1 = strlen(s) - 1;
	int start;

	// 第几个组（4个数字一组，none/万/亿）
	int group_id;
	

	for (; i <= n_1;) {
		// 每四个一组
		// 可能不是恰好凑满一组的
		start = (n_1 - i) % 4;
		group_id = (n_1 - i) / 4;

		// 处理某一组的4个数（可能不满4个）
		while (start != -1) {
			if (s[i] == '0') {
				// 找到本组内最近的非0数字的位置，或者是到下一组的开头处
				for (++i, --start; start >= 0 && s[i] == '0'; ++i, --start);
				// 没到本组结束的位置，打印0
				if (start >= 0)
					printf(" ling");
				else
					// 到达下一组开头了
					break;
			}

			if (is_first)
				is_first = false;
			else
				printf(" ");
			// assert s[i] != '0' 本算法保证了这个
			printf("%s", nums[s[i] - '0']);

			// 个位数字没有后缀的，十位百位千位有的
			if (start > 0)
				printf(" %s", group_elements[start]);

			++i;
			--start;
		}

		// 最后一组不打印后缀，其余的打印 万/亿这些
		if (group_id > 0)
			printf(" %s", groups[group_id]);

	}

	// 特殊处理
	if (n_1 == 0 && s[0] == '0')
		printf("ling");

	system("pause");
	return 0;
}