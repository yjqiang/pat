# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>

using namespace std;


int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	int sum = a + b;
	if (!sum){
		
		printf("0");
		system("pause");
		return 0;
	}

	bool negative;
	if (sum < 0)
	{
		sum = -sum;
		negative = true;
	}
	else
		negative = false;
	
	vector<char> s;
	for (; sum; sum/=10)
		s.push_back('0' + sum % 10);
	
	int n = s.size();
	if (negative)
		printf("-");

	int i;
	for (i=n-1; i >=0; --i){
		
		printf("%c", s[i]);
		if (!(i % 3) && i)
			printf(",");
	}
	
	
	
	system("pause");
	return 0;
}