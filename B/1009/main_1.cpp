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

	for (int i = strlen(s) - 1; i > 0; i--) { //��ĩβ��ʼ�����ַ��� 
		if (s[i] == ' ') {
			printf("%s ", s + i + 1);
			s[i] = '\0'; //�ѿո��Ϊ \0��ʹ�������Ҳֻ��һ������
		}
	}
	printf("%s", s);
	system("pause");
	return 0;
}