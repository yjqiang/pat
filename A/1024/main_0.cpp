#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>
#include <cstring>

using namespace std;

char a[50];
char b[50];

void reverseB2A(int n) {
	int i, k;
	for (i = 0, k = n - 1; i < n; ++i, --k)
		a[i] = b[k];
	a[n] = '\0';
}

bool isPalindromic(int n) {
	int i, k;
	for (i = 0, k = n - 1; i < k; ++i, --k)
		if (a[i] != a[k])
			return false;
	return true;
}

int main() {
	int K;
	scanf("%s%d", a, &K);


	int n = strlen(a);

	if (isPalindromic(n)) {
		printf("%s\n%d", a, 0);
		return 0;
	}

	int i, count;
	int sum;
	for (count = 1;; ++count) {
		sum = 0;
		for (i = n - 1, n = 0; i >= 0; --i, ++n) {
			sum += (a[i] - '0') + (a[n] - '0');
			b[n] = sum % 10 + '0';
			sum /= 10;
		}
		if (sum) {
			b[n] = '0' + sum;
			++n;
		}
		b[n] = '\0';

		// printf("%s=>%s\n", a, b);

		reverseB2A(n);
		if (isPalindromic(n) || count == K){
			break;
		}
			
	}
	printf("%s\n%d", a, count);

	system("pause");
	return 0;
}