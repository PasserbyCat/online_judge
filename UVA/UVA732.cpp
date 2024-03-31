#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
vector<string>last;
string first, second, answer;
stack<int>place;//存最後一個out的位置
void merge(int open)//會先執行，才去判斷將該個o改成i時可不可行
{
	stack<char>temp;//暫存器
	int j = 0;
	if (open != 0) {//已經執行過，
		place.pop();
		answer.resize(open);
		open = 0;
		for (int i = 0; i < answer.size(); i++)
			if (answer[i] == 'i') {
				temp.push(first[open]);
				open++;//判斷first到第幾位了
			}
			else {
				temp.pop();
				j++;//判斷second到底幾位了
			}
	}
	for (int i = open; i < second.size(); i++) {
		answer.push_back('i');//每次都先將first放進stack
		temp.push(first[i]);
		while (!temp.empty())
			if (temp.top() == second[j]) {//相同時就輸出
				answer.push_back('o');
				place.push(answer.size() - 1);
				temp.pop();
				j++;
			}
			else break;
	}
	for (int i = 0, j = 0; i < answer.size(); i++)
		if (answer[i] == 'i')
			j++;//判斷i的個數
	if (answer.size() == first.size() * 2 && j == first.size() && answer[answer.size() - 1] != 'i') {//必須要符合正確的i和o才可以輸出
		last.resize(last.size() + 1);
		last[last.size() - 1] = answer;
	}
	if (!place.empty())//避免crash
		if (place.top() == last[last.size() - 1].size() - 1)//省時(可以少倒退一筆完全不影響的)
			place.pop();
}
int main()
{
	while (cin >> first) {//first存轉換前的字串
		cin >> second;//second存轉換後的字串
		cout << "[\n";
		if (first.size() == second.size()) {
			merge(0);
			while (!place.empty())//倒退到palce[place.size() - 1]儲存的位置
				merge(place.top());
		}
		for (int j = last.size() - 1; j >= 0; j--) {//原本的字串沒有空格，在這邊補
			for (int i = 0; i < last[j].size(); i++) {
				if (i != 0)
					cout << " ";
				cout << last[j][i];
			}
			cout << endl;
		}
		cout << "]\n";
		answer.clear();//最後一筆執行完後不會清掉，在這邊清
		last.clear();//答案輸出後把答案清空
	}
}