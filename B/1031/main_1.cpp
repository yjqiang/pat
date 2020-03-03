#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>
#include <cstring>
#include <climits>
#include <cstdio>
#include <queue>

using namespace std;

char M[] = "10X98765432";
int weight[] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
char ID[19];

bool isOk() {
	int k;
	char char_tmp;
	int sum = 0;
	for (k = 0; k < 17; ++k) {
		char_tmp = ID[k];
		if (char_tmp > '9' || char_tmp < '0') {
			return false;
		}
		sum += (char_tmp - '0') * weight[k];
	}
	return M[sum % 11] == ID[17];
}

int main() {
	
	int N;
	scanf("%d", &N);

	int i;
	bool is_ok;
	bool is_all_ok = true;
	

	for (i = 0; i < N; ++i) {
		scanf("%s", ID);
		if (!isOk()){
			printf("%s\n", ID);
			is_all_ok = false;
		}
	}
	if (is_all_ok)
		printf("All passed");

	system("pause");
	return 0;
}