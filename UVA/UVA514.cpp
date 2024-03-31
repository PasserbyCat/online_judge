#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main()
{
	int car, temp;
	cin >> car;//這種有幾列車廂
	while (car) {
		while (1) {
			cin >> temp;//該種車廂的列車已經結束，測試其他種
			if (temp == 0)
				break;
			stack<int>station;//存取轉運站列車的排列順序，FILO
			queue<int>answer;//存取原始列車的排列順序，FIFO
			for (int i = 0; i < car; i++) {
				if (i != 0)//第一筆測資已經輸入過不用再輸入一次
					cin >> temp;
				answer.push(temp);
			}
			for (int i = 1; i <= car; i++) {//測試B側的列車能不能倒車回原本的排序方式
				if (i == answer.front())
					answer.pop();
				else
					station.push(i);
				while (!station.empty())
					if (station.top() == answer.front()) {
						station.pop();
						answer.pop();
					}
					else
						break;
			}
			if (station.empty())//若是停駐空間還有剩，代表排序不正確
				cout << "Yes\n";
			else
				cout << "No\n";
		}
		cout << endl;
		cin >> car;
	}
}