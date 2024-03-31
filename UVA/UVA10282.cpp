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
		place = line.find(' ');//找到空格將字分開
		pre.erase(pre.begin() + place, pre.end());//留前面的字
		next.erase(next.begin(), next.begin() + place + 1);//留後面的字
		treenode[next] += pre;
	}
	while (getline(cin, line)) {
		if (line == "")
			break;
		if (treenode.count(line)) {//當count為1代表有找到
			answer.push_back(treenode.find(line)->second);//將找到的name放進去
		}
		else {
			answer.push_back("eh");//將eh放進去
		}
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;//將答案全部輸出出來
	}
}
