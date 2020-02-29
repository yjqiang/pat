#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>
#include <cstring>

using namespace std;

char a[22];
char double_a[22];
int my_count[10] = { 0 };

int main() {
	a[0] = '0';
	scanf("%s", a + 1);
	int n = strlen(a);
	int i;
	int sum = 0;
	double_a[n] = 0;
	for (i = n - 1; i >= 0; --i) {
		sum += (a[i] - '0') * 2;
		double_a[i] = sum % 10 + '0';
		sum /= 10;
	}

	for (i = 1; i < n; ++i)
		++my_count[a[i] - '0'];

	for (i = 1; i < n; ++i)
		--my_count[double_a[i] - '0'];

	bool is_ok = true;
	for (i = 0; i < 10; ++i)
		if (my_count[i]) {
			is_ok = false;
			break;
		}
	is_ok && double_a[0] == '0' ? printf("Yes\n"): printf("No\n");
	double_a[0] == '0'? printf("%s", double_a+1) : printf("%s", double_a);
		
	


	system("pause");
	return 0;
}