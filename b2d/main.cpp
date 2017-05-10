#include <iostream>
#include <iomanip>
#include <inttypes.h>
#include <cstring>
#include <vector>

using namespace std;
int pow_i(int a, int b){
	int result = 1;
	for (size_t i = 0; i < b; i++)
	{
		result *= a;
	}
	return result;
}
int toDec(int bin){
	int res = 0;
	for (size_t i = 1; i < 9; i++)
	{
		res += (((bin % pow_i(10, i)) - (bin % pow_i(10, i - 1)))) / pow_i(10, i - 1) *pow_i(2, i-1);
	}
	return res;
}
int main()
{
	char byte[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};
	vector<int> vec;
	while (true){
		for (size_t i = 0; i < 8; i++)
		{
			cin >> byte[i];
		}
		if (strcmp(byte, "exitexit")==0) break;
		int val = atoi(byte);
		val = toDec(val);
		vec.push_back(val);
	}
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	system("pause");
}