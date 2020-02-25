# define _CRT_SECURE_NO_WARNINGS
# include <cstdlib>
# include <stdio.h>
# include <vector>
# include <ctime>
# include <iostream>
# include <cstring>
# include <climits>
# include <cmath>

using namespace std;



int main() {
	int n;
	int x, y;
	bool first = true;
	bool zero = true;
	for (n = 0; scanf("%d", &x) != EOF; ++n) {
		scanf("%d", &y);

		x = x * y;
		y -= 1;

		if (x) {
			zero = false;
			if (first) {
				printf("%d %d", x, y);
				first = false;
			}
				
			else
				printf(" %d %d", x, y);
		}
		
			
	}
	if (zero)
		printf("0 0");
		
	system("pause");
	return 0;
}