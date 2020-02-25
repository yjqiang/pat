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
	for (n = 0; scanf("%d%d", &x, &y) != EOF; ++n) {

		x = x * y;
		y -= 1;

		if (x) {
			if (first) {
				printf("%d %d", x, y);
				first = false;
			}
				
			else
				printf(" %d %d", x, y);
		}
		
			
	}
	if (first)
		printf("0 0");
		
	system("pause");
	return 0;
}