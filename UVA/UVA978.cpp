#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
	vector<int> fightground;

	int fight;
	cin >> fight;//���X���԰�
	for (int i = 0; i < fight; i++) {

		multiset<int> green, blue;
		int ground, gnumber, bnumber;
		cin >> ground >> gnumber >> bnumber;//���X�ӾԳ��F��観�X�ӳ��F�Ť観�X�ӳ��

		fightground.resize(ground);//�@���i��Ԫ��̤j�Գ���

		int temp;
		for (int j = 0; j < gnumber; j++) {
			cin >> temp;
			green.insert(temp);//�N��誺�h�L�԰��O��iset
		}
		for (int j = 0; j < bnumber; j++) {
			cin >> temp;
			blue.insert(temp);//�N�Ť誺�h�L�԰��O��iset
		}

		multiset<int>::reverse_iterator rbit = blue.rbegin(), rgit = green.rbegin();//�q����԰��O�̰����}�l�԰�
		while (!green.empty() && !blue.empty()) {//���[����ܤ֤@����ư}�`
			for (int j = 0; j < ground; j++) {
				fightground[j] = *rbit - *rgit;//�C�ӾԳ��s�԰����G�A���ƥN���Ť�Ĺ�A�t�ƥN����Ĺ�A0�h�N������Ұ}�`
				green.erase(green.lower_bound(*rgit));
				blue.erase(blue.lower_bound(*rbit));
				if (green.empty() || blue.empty())
					break;
			}
			for (int j = 0; j < ground; j++) {
				if (fightground[j] > 0)
					blue.insert(fightground[j]);//�Ť��Ĺ��A�N�Ӥh�L���Ѿl�԰��O�b�g�Jset
				else if (fightground[j] < 0)
					green.insert(-fightground[j]);//����Ĺ��A�N�Ӥh�L���Ѿl�԰��O�b�g�Jset
				fightground[j] = 0;
			}
		}

		if (!green.empty()) {//�Ť�����}�`�A�N���Ѿl�h�L�P��԰��O��X
			cout << "green wins\n";
			for (multiset<int>::reverse_iterator it = green.rbegin(); it != green.rend(); ++it)
				std::cout << *it << endl;
		}
		else if (!blue.empty()) {//�������}�`�A�N�Ť�Ѿl�h�L�P��԰��O��X
			cout << "blue wins\n";
			for (multiset<int>::reverse_iterator it = blue.rbegin(); it != blue.rend(); ++it)
				std::cout << *it << endl;
		}
		else
			cout << "green and blue died\n";
		if (i != fight - 1)//�̫�@����Ƥ��δ���
			cout << endl;
	}
	return 0;
}