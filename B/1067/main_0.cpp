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

string correct_psd;
string input_psd;

int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> correct_psd >> N;
	// 读取剩下的\n
	cin.get();

	int i;
	for (i = 1; ; ++i) {
		getline(cin, input_psd);
		// 终止
		if (input_psd.size() == 1 && input_psd[0] == '#')
			break;
		
		// OK
		if (input_psd == correct_psd){
			printf("Welcome in\n");
			break;
		}

		printf("Wrong password: %s\n", input_psd.c_str());
		// 错误且超过次数
		if (i >= N) {
			printf("Account locked\n");
			break;
		}

	}
	
	system("pause");
	return 0;
}