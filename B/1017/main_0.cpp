#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
# include <climits>
#include <cstring>
#include <map>
#include <cstdio>
#include <queue>

using namespace std;

#define MAX_N 1001

char a[MAX_N];
int b;

int main() {
	scanf("%s%d", a, &b);

	int index;
	int sum;

	for (index = 0, sum = 0; a[index] != '\0'; ++index) {
		sum = sum * 10 + a[index] - '0';
		a[index] = '0' + sum / b;
		sum = sum % b;  // (sum < b) => (sum == sum % b); (sum >= b) => (sum == sum % b)
	}
	for (index = 0; a[index] != '\0'; ++index) {
		if (a[index] != '0'){
			printf("%s %d", a + index, sum);
			system("pause");
			return 0;
		}
	}
	printf("0 %d", sum);
	system("pause");

	
	return 0;
}