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

// ԭ����
char orig[N_MAX];
// ɾ���˷��š�С���㡢E�Լ��������ֵĴ���
char pure_num[N_MAX];


int main() {
	int n_pure_num;

	scanf("%s", orig);
	if (orig[0] == '-')
		printf("-");

	int i;
	// E�ַ����±�
	int i_E;
	// x.xxx * 10^E
	int E;

	for (i = 2; orig[i] != 'E'; ++i);
	i_E = i;
	sscanf(orig + i_E, "E%d", &E);
	
	// �ѷ���֮���ȫ��ȥ��
	for (n_pure_num = 0, i = 0; i < i_E; ++i)
		if (isdigit(orig[i])) {
			pure_num[n_pure_num] = orig[i];
			++n_pure_num;
		}
	
	// ǰ�油��0
	if (E < 0) {
		// ����|E| - 1��0
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
		// С�����ֳ��ȴ���E���������С����
		if (n_pure_num - 1 > E) {
			for (i = 0; i <= E; ++i)
				printf("%c", pure_num[i]);

			printf(".");
			printf("%s", pure_num + E + 1);
		}
		// ��С����
		else {
			printf("%s", pure_num);
			// ���油��0
			int n_zero = E - (n_pure_num - 1);
			for (i = 0; i < n_zero; ++i)
				printf("0");
		}
	}

	system("pause");
	return 0;
}