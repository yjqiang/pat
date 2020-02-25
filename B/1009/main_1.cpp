# define _CRT_SECURE_NO_WARNINGS
# include <cstdlib>
# include <stdio.h>
# include <vector>
# include <ctime>
# include <iostream>
# include <cstring>
# include <climits>
# include <cmath>

using namespace std;

char s[85];

int main() {
	int n;
	ios::sync_with_stdio(false);

	cin.getline(s, 85);

	for (int i = strlen(s) - 1; i > 0; i--) { //从末尾开始遍历字符串 
		if (s[i] == ' ') {
			printf("%s ", s + i + 1);
			s[i] = '\0'; //把空格改为 \0，使后续输出也只有一个单词
		}
	}
	printf("%s", s);
	system("pause");
	return 0;
}