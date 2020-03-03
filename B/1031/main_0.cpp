#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>
#include <cstring>
#include <climits>
#include <cstdio>
#include <queue>

using namespace std;


int main() {
	char M[] = "10X98765432";
	int weight[] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
	char ID[19];
	int N;
	scanf("%d", &N);

	int i, k, sum;
	char char_tmp;
	bool is_ok;
	bool is_all_ok = true;
	

	for (i = 0; i < N; ++i) {
		scanf("%s", ID);

		sum = 0;
		is_ok = true;
		for (k = 0; k < 17; ++k) {
			char_tmp = ID[k];
			if (char_tmp > '9' || char_tmp < '0') {
				is_ok = false;
				break;
			}	
			sum += (char_tmp - '0') * weight[k];
		}
		if (!is_ok || M[sum % 11] != ID[17]) {
			printf("%s\n", ID);
			is_all_ok = false;
		}
	}
	if (is_all_ok)
		printf("All passed");

	system("pause");
	return 0;
}