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
		// ���i�����ݣ�"d"Ϊ��һ�����ݣ�
		for (k = 0; k < n_size;) {
			// ������Ƭ�ε���ʼλ�ã�����Ƭ�γ��ȿ���Ϊ1��
			start = k;
			cur_value = s[k];

			for (++k; k < n_size && s[k] == cur_value; ++k);
			// ����Ƭ�γ���
			count = k - start;

			// ¼��
			tmp_s += cur_value + to_string(count);
		}

		s = tmp_s;
	}

	printf("%s\n", s.c_str());

	system("pause");
	return 0;
}