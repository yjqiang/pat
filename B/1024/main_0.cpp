#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>
#include <string>

using namespace std;


int main() {
	// +1.23400E-03
	// -1.2E+10
	char tmp_char;
	scanf("%c", &tmp_char);
	if (tmp_char == '-')
		printf("-");
	char a[10000];
	scanf("%c.", a);

	int i, n;
	for (n = 1; (tmp_char = getchar()) != 'E'; ++n)
		a[n] = tmp_char;
	a[n] = '\0';

	int e;
	scanf("%d", &e);
	if (e < 0) {  // +1.234E-1 => 0.1234
		printf("0.");
		for (i = -e - 1; i > 0; --i)
			printf("0");
		printf("%s", a);
	}
	else if (e == 0) { // +1.2345E0  => 1.2345
		printf("%c.%s", a[0], a + 1);
	}
	else { // +1.2345E5 => 123450
		// +1.2345E3 => 1234.5
		for (i = 0; i <= e; ++i) {
			if (i >= n)
				printf("0");
			else
				printf("%c", a[i]);
		}
		if (i < n) {
			printf(".");
			printf("%s", a + i);
		}
	}

	system("pause");
	return 0;
}