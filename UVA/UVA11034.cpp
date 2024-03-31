#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <climits>
using namespace std;
int main()
{
	int c;
	cin >> c;//�`�@���X������
	while (c--) {
		int l, m, cross = 0;//l��ܲ����_m��ܨ��l���ƶq_cross��ܴ�e������
		bool place = true;//true��ܥ����Afalse��ܥk��
		cin >> l >> m;
		l *= 100;//l�쥻�O���حn�ন����
		queue<int>left, right;//���O�s���������M�k������
		for (int i = 0; i < m; i++) {
			int temp;
			string word;
			cin >> temp >> word;
			if (word == "left")
				left.push(temp);
			else
				right.push(temp);
		}
		left.push(2000000000);//�񷥺ݭȡA���n�B
		right.push(2000000000);//�񷥺ݭȡA���n�B
		while (left.size() != 1 || right.size() != 1) {
			int temp = l;//temp������O�_�뺡�F
			if (place) {
				while (temp >= 0) {
					if (temp != l)//�Ĥ@��������
						left.pop();
					temp -= left.front();//�C���N�@�x����W��A�Y�O�o�{���l�W�h��|�W�L�N�פ�A�Ϥ��N�W����l�q��������
				}
				temp += left.front();
				place = false;//�L�e
			}
			else {
				while (temp >= 0) {
					if (temp != l)//�Ĥ@��������
						right.pop();
					temp -= right.front();//�C���N�@�x����W��A�Y�O�o�{���l�W�h��|�W�L�N�פ�A�Ϥ��N�W����l�q�k������
				}
				temp += right.front();
				place = true;//�L�e
			}
			cross++;
		}
		cout << cross << endl;//��X��e����
	}
}