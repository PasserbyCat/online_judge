#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main()
{
	int number;
	while (cin >> number) {
		int in, temp, real = 3;
		bool ts = true, tq = true, tpq = true;
		stack<int>dos;
		queue<int>doq;
		priority_queue<int>dopq;

		for (int i = 0; i < number; i++) {
			cin >> in >> temp;
			if (in == 1) {//in用來判斷是push還是pop
				dos.push(temp);
				doq.push(temp);
				dopq.push(temp);
			}
			else {
				if (dos.empty() || doq.empty() || dopq.empty()) {
					real = 0;//當數列是空的時候pop代表不可能存在
					continue;
				}
				if (ts)
					if (dos.top() == temp)
						dos.pop();
					else {//一旦不等就將real--且將ts設為false，代表答案不是stack
						real--;
						ts = false;
					}
				if (tq)
					if (doq.front() == temp)
						doq.pop();
					else {
						real--;//一旦不等就將real--且將tq設為false，代表答案不是queue
						tq = false;
					}
				if (tpq)
					if (dopq.top() == temp)
						dopq.pop();
					else {
						real--;//一旦不等就將real--且將tpq設為false，代表答案不是priority_queue
						tpq = false;
					}
			}
		}
		if (real < 1)
			cout << "impossible\n";
		else if (real == 1)
			if (ts)
				cout << "stack\n";
			else if (tq)
				cout << "queue\n";
			else
				cout << "priority queue\n";
		else//real>1代表有兩組以上的解，所以我們不能確定到底是甚麼
			cout << "not sure\n";
	}
}