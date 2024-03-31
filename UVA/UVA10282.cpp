#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main()
{
	map<string, string>treenode;
	vector<string> answer;
	string pre, next, line;
	int place;
	while (getline(cin, line)) {
		if (line == "")
			break;
		pre = next = line;
		place = line.find(' ');//���Ů�N�r���}
		pre.erase(pre.begin() + place, pre.end());//�d�e�����r
		next.erase(next.begin(), next.begin() + place + 1);//�d�᭱���r
		treenode[next] += pre;
	}
	while (getline(cin, line)) {
		if (line == "")
			break;
		if (treenode.count(line)) {//��count��1�N�����
			answer.push_back(treenode.find(line)->second);//�N��쪺name��i�h
		}
		else {
			answer.push_back("eh");//�Neh��i�h
		}
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;//�N���ץ�����X�X��
	}
}
