#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
struct ANS {
	int order;//�s�ǦC
	int number;//�sarrival
};
int main()
{
	int c, n, t, m, take;
	cin >> c;//c�N���X�հ���
	vector<int>answer;
	for (int a = 0; a < c; a++) {
		if (a != 0)
			cout << endl;
		int time = 0;
		cin >> n >> t >> m;//n�N��i�H�b�X�x��_t�N���e�n��h�[_m�N���`�@���X�x���n��e
		answer.resize(m);//��m����ƥN��m��answer
		queue<ANS>left, right;//�������M�k��
		ANS input;
		for (int i = 0; i < m; i++) {
			int temp;
			string word;
			cin >> temp >> word;
			input.number = temp;//��F�ɶ�
			input.order = i;//�ĴX�x��
			if (word == "left")//������i����
				left.push(input);
			else//�k����i�k��
				right.push(input);
		}
		input.number = 2147483647;
		left.push(input);//���Y��̤j�ȡA�����
		right.push(input);//���Y�񷥤j�ȡA�����
		bool place = true;//��@�}�l�b����
		while (left.size() != 1 || right.size() != 1) {//��ӳ��u�ѧڭ̦ۤv��J�����j�Ȯɵ����j��
			take = 0;//�i�D�ϥΪ̲{�b��W���X�x��
			if (place) {//��b�������ʧ@
				while (left.size() != 1 && take < n)//��W�������ƥؤ���j����B�q�A�B���������n�����l�~�i����
					if (left.front().number <= time) {//���l�w�g��F�ɡA�N�N���l��W��
						take++;
						answer[left.front().order] = time + t;//��L����F�ɶ���X�ө�J�ǦC����
						left.pop();
					}
					else//�|�������l��F�N�������}�j��
						break;
				if (take > 0);//�w�g�����l�b��W�Q�H�U��������(�H�U�ҬO���F�ɩ|�����������p)
				else if (left.front().number <= right.front().number) {//�Y�O�������U�@������k�����U�@�����󦭩�F
					time = left.front().number;//�����N�ɶ������쥪���U�@��������F�ɶ�
					while (time == left.front().number && take < n) {//�Y�O���Ƽƪ������P�@�ɶ���F�A�@�_���W��(�b��W�e�q�٨S�z�������p)
						answer[left.front().order] = time + t;
						left.pop();
						take++;
					}
				}
				else if (time > right.front().number);//�k�����U�@�����񥪩����U�@�����󦭩�F�A�B�ӽ����w�g��F�k���A�h�����N��}���k��
				else
					time = right.front().number;//�k�����U�@�����񥪩����U�@�����󦭩�F�A���ӽ����|����F�k���A���쨮��F�k���A�N��}�L�h
				time += t;//���F�k�����ɶ�
				place = false;//��}���k��
			}
			else {//��b�k�����ʧ@
				while (right.size() != 1 && take < n)//��W�������ƥؤ���j����B�q�A�B�k�������n�����l�~�i����
					if (right.front().number <= time) {//���l�w�g��F�ɡA�N�N���l��W��
						take++;
						answer[right.front().order] = time + t;//��L����F�ɶ���X�ө�J�ǦC����
						right.pop();
					}
					else//�|�������l��F�N�������}�j��
						break;
				if (take > 0);//�w�g�����l�b��W�Q�H�U��������(�H�U�ҬO���F�ɩ|�����������p)
				else if (left.front().number >= right.front().number) {//�Y�O�k�����U�@�����񥪩����U�@�����󦭩�F
					time = right.front().number;//�����N�ɶ�������k���U�@��������F�ɶ�
					while (time == right.front().number && take < n) {//�Y�O���Ƽƪ������P�@�ɶ���F�A�@�_���W��(�b��W�e�q�٨S�z�������p)
						answer[right.front().order] = time + t;
						right.pop();
						take++;
					}
				}
				else if (time > left.front().number);//�������U�@�����񥪩����U�@�����󦭩�F�A�B�ӽ����w�g��F�����A�h�����N��}������
				else
					time = left.front().number;//�������U�@������k�����U�@�����󦭩�F�A���ӽ����|����F�����A���쨮��F�����A�N��}�L�h
				time += t;//���F�������ɶ�
				place = true;//��}������
			}
		}
		for (int i = 0; i < answer.size(); i++)
			cout << answer[i] << endl;//�N�Ӧ����B�@���G��X
	}
}