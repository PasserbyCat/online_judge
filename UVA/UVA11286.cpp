#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string biggest(int[]);
int main()
{
	int line;
	cin >> line;
	while (line) {
		map<string, int>truth;
		int A[5], max = 0, real = 0;
		string temp;
		for (int i = 0; i < line; i++) {
			for (int j = 0; j < 5; j++)
				cin >> A[j];//用int存
			sort(A, A + 5);//確保數字由小大大排列
			temp = biggest(A);//將數字存成string作為map的key
			truth[temp]++;
			if (max < truth.find(temp)->second)
				max = truth.find(temp)->second;//被選最多次的課
		}
		
		for (map<string, int>::iterator it = truth.begin(); it != truth.end(); it++)
			if (it->second == max)
				real += max;//被選最多次的課有幾門

		cout << real << endl;
		cin >> line;
	}
}
string biggest(int A[])
{
	string temp;
	for (int i = 0; i < 5; i++) {
		temp.push_back(A[i] / 100 + '0');
		temp.push_back(A[i] / 10 % 10 + '0');
		temp.push_back(A[i] % 10 + '0');
	}
	return temp;
}
