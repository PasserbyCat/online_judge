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
				cin >> A[j];//��int�s
			sort(A, A + 5);//�T�O�Ʀr�Ѥp�j�j�ƦC
			temp = biggest(A);//�N�Ʀr�s��string�@��map��key
			truth[temp]++;
			if (max < truth.find(temp)->second)
				max = truth.find(temp)->second;//�Q��̦h������
		}
		
		for (map<string, int>::iterator it = truth.begin(); it != truth.end(); it++)
			if (it->second == max)
				real += max;//�Q��̦h�����Ҧ��X��

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
