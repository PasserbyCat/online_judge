#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int number;
	cin >> number;//���X�ӼƦr
	while (number) {
		priority_queue<int>all;
		int total;
		for (int i = 0; i < number; i++) {
			int temp;
			cin >> temp;
			all.push(-temp);//�έt�Ʀs�A��n�Ominheap�A�L��-�������p
		}
		int answer = 0;
		for (int i = 0; !all.empty(); i++) {
			if (i != 0)//�Ĥ@�������٨S��total
				all.push(-total);//�b�٦���ƪ��ɭԡA�Ntotal��^�쥻��priority_queue
			total = -all.top();
			all.pop();
			total += -all.top();
			all.pop();
			answer += total;//�Ntotal�[�ianswer��
		}
		cout << answer << endl;
		cin >> number;
	}
}