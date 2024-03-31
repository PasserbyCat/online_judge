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
			if (in == 1) {//in�ΨӧP�_�Opush�٬Opop
				dos.push(temp);
				doq.push(temp);
				dopq.push(temp);
			}
			else {
				if (dos.empty() || doq.empty() || dopq.empty()) {
					real = 0;//��ƦC�O�Ū��ɭ�pop�N���i��s�b
					continue;
				}
				if (ts)
					if (dos.top() == temp)
						dos.pop();
					else {//�@�������N�Nreal--�B�Nts�]��false�A�N���פ��Ostack
						real--;
						ts = false;
					}
				if (tq)
					if (doq.front() == temp)
						doq.pop();
					else {
						real--;//�@�������N�Nreal--�B�Ntq�]��false�A�N���פ��Oqueue
						tq = false;
					}
				if (tpq)
					if (dopq.top() == temp)
						dopq.pop();
					else {
						real--;//�@�������N�Nreal--�B�Ntpq�]��false�A�N���פ��Opriority_queue
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
		else//real>1�N����եH�W���ѡA�ҥH�ڭ̤���T�w�쩳�O�ƻ�
			cout << "not sure\n";
	}
}