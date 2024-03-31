#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
vector<string>last;
string first, second, answer;
stack<int>place;//�s�̫�@��out����m
void merge(int open)//�|������A�~�h�P�_�N�ӭ�o�令i�ɥi���i��
{
	stack<char>temp;//�Ȧs��
	int j = 0;
	if (open != 0) {//�w�g����L�A
		place.pop();
		answer.resize(open);
		open = 0;
		for (int i = 0; i < answer.size(); i++)
			if (answer[i] == 'i') {
				temp.push(first[open]);
				open++;//�P�_first��ĴX��F
			}
			else {
				temp.pop();
				j++;//�P�_second�쩳�X��F
			}
	}
	for (int i = open; i < second.size(); i++) {
		answer.push_back('i');//�C�������Nfirst��istack
		temp.push(first[i]);
		while (!temp.empty())
			if (temp.top() == second[j]) {//�ۦP�ɴN��X
				answer.push_back('o');
				place.push(answer.size() - 1);
				temp.pop();
				j++;
			}
			else break;
	}
	for (int i = 0, j = 0; i < answer.size(); i++)
		if (answer[i] == 'i')
			j++;//�P�_i���Ӽ�
	if (answer.size() == first.size() * 2 && j == first.size() && answer[answer.size() - 1] != 'i') {//�����n�ŦX���T��i�Mo�~�i�H��X
		last.resize(last.size() + 1);
		last[last.size() - 1] = answer;
	}
	if (!place.empty())//�קKcrash
		if (place.top() == last[last.size() - 1].size() - 1)//�ٮ�(�i�H�֭˰h�@���������v�T��)
			place.pop();
}
int main()
{
	while (cin >> first) {//first�s�ഫ�e���r��
		cin >> second;//second�s�ഫ�᪺�r��
		cout << "[\n";
		if (first.size() == second.size()) {
			merge(0);
			while (!place.empty())//�˰h��palce[place.size() - 1]�x�s����m
				merge(place.top());
		}
		for (int j = last.size() - 1; j >= 0; j--) {//�쥻���r��S���Ů�A�b�o���
			for (int i = 0; i < last[j].size(); i++) {
				if (i != 0)
					cout << " ";
				cout << last[j][i];
			}
			cout << endl;
		}
		cout << "]\n";
		answer.clear();//�̫�@�����槹�ᤣ�|�M���A�b�o��M
		last.clear();//���׿�X��⵪�ײM��
	}
}