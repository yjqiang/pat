#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>
#include <string>

using namespace std;

int nums[10];

int main() {
	int i, n;
	for (i = 0; i < 10; ++i)
		scanf("%d", nums + i);

	for (i = 1; i < 10; ++i)
		if (nums[i]) {
			printf("%d", i);
			--nums[i];
			break;
		}
	for (i = 0; i < 10; ++i) {
		n = nums[i];
		while (n) {
			printf("%d", i);
			--n;
		}
	}

	system("pause");
	return 0;
}