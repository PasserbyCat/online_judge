#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main()
{
	int car, temp;
	cin >> car;//�o�ئ��X�C���[
	while (car) {
		while (1) {
			cin >> temp;//�Ӻب��[���C���w�g�����A���ը�L��
			if (temp == 0)
				break;
			stack<int>station;//�s����B���C�����ƦC���ǡAFILO
			queue<int>answer;//�s����l�C�����ƦC���ǡAFIFO
			for (int i = 0; i < car; i++) {
				if (i != 0)//�Ĥ@������w�g��J�L���ΦA��J�@��
					cin >> temp;
				answer.push(temp);
			}
			for (int i = 1; i <= car; i++) {//����B�����C���ण��˨��^�쥻���ƧǤ覡
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
			if (station.empty())//�Y�O���n�Ŷ��٦��ѡA�N��ƧǤ����T
				cout << "Yes\n";
			else
				cout << "No\n";
		}
		cout << endl;
		cin >> car;
	}
}