#include <iostream>
#include <deque>
using namespace std;
int main()
{
	long long people;
	unsigned int command, now = 1, temp;
	cin >> people >> command;
	while (people != 0 || command != 0) {

		cout << "Case " << now << ":\n";
		now++;//�C�@��case

		deque<unsigned int>all;
		for (unsigned int i = 0; i < people && i < command; i++) {
			all.push_back(i + 1);
		}//�u�ݭn�s�H�ƥB�H�ƥ��M�p��������O�A�H�Ʀh����O���������|�Q�s��
		for (unsigned int i = 0; i < command; i++) {
			char input;
			cin >> input;
			if (input == 'N') {//�H���X��
				temp = all.front();//�N�Ĥ@�Ӱe�X�h
				all.push_back(temp);//���̫�@��
				all.pop_front();
				cout << temp << endl;
			}
			else if (input == 'E') {
				unsigned int number;
				cin >> number;//�ݭn�u�����H��
				for (unsigned int j = 0; j < all.size(); j++)
					if (all[j] == number) {//�p�G�u���H���s�b��ƶ��ǦC���A�N�L����m����
						all.erase(all.begin() + j);
						break;
					}
				all.push_front(number);//���u���H�����̫e��
			}
		}
		cin >> people >> command;
	}
}