# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
# include <climits>
#include <cstring>

using namespace std;

int main() {
	char a[] = "WTL";
	int i, k;
	double tmp;
	int max_index;
	double max_element;
	double result = 1.0;
	for (i = 0; i < 3; ++i) {
		max_index = -1;
		max_element = 0.0;
		for (k = 0; k < 3; ++k) {
			scanf("%lf", &tmp);
			if (tmp > max_element) {
				max_index = k;
				max_element = tmp;
			}
			
		}
		printf("%c ", a[max_index]);
		result *= max_element;
	}
	printf("%.2lf", (result * 0.65 - 1) * 2);

	system("pause");
	return 0;
}