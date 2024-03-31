#include <iostream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
	string temp;
	int blank;
	cin >> blank;//有幾塊區域需要判讀
	temp = "\n";
	getline(cin, temp);//11行與12行是為了解決cin後getline會被忽略的問題
	/*getchar();用法同11行+12行
	getchar();*/
	cout << fixed << setprecision(4);//強制輸出小數點後四位
	for (int i = 0; i <= blank; i++) {
		map<string, int>treenode;
		int total = 0;
		while (getline(cin, temp)) {
			if (temp == "")
				break;
			//if (treenode.count(temp))
				treenode[temp]++;//此用法就包含insert
			//else
				//treenode.insert(pair<string, int>(temp, 1));
			total++;
		}
		map<string, int>::iterator it = treenode.begin();
		for (map<string, int>::iterator it = treenode.begin(); it != treenode.end(); it++)
			cout << it->first << " " 
				<< it->second * 100.0 / total //100.0強制將int轉型成寒小數點的數
				<< endl;
		if (i != 0 && i != blank)//第一筆永遠是空的；最後一筆不用輸出endl，為符合語法
			cout << endl;
	}
}
