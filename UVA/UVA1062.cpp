#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string input;
	vector<stack<char>>all;
	int j = 1;//�s�ĴX��case
	while (cin >> input) {
		if (input == "end")//�פ�Ÿ�
			break;
		while (!input.empty()) {//�C���u�P�_�@�Ӧ줸�A�P�_��Y�R��
			bool doing = true;//�P�_���S��push
			for (int i = 0; i < all.size(); i++)
				if (input[0] <= all[i].top()) {//����p�N��i�H�˶i�h
					all[i].push(input[0]);
					input.erase(input.begin());
					doing = false;
					break;
				}
			if (doing) {//���S���˶i�h�ɡA�B�~�}�@�ӷs��stack�x�s
				stack<char>temp;
				temp.push(input[0]);
				input.erase(input.begin());
				all.push_back(temp);
			}
		}
		cout << "Case " << j << ": " << all.size() << endl;
		j++;
		all.clear();//�b�Ҧ����굲����Nvector�M��
	}
}