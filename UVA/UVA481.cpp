//UVA481-What Goes Up
#include <iostream>
#include <vector>
using namespace std;
vector<int>all(1, 0), tail(2, 1), answer;//���Ҽ{�Ĺs��A��K��� || tail���Ĥ@��]��1�A�]���@�}�l�@�w�|���
int CeilIndex(int low, int high, int key)
{
	while (high - low > 1)
	{
		int mid = (high + low) / 2;//binary search
		if (all[tail[mid]] >= key)
			high = mid;
		else
			low = mid;
	}
	return high;
}
int main()
{
	int input, max = 0, place = 0;
	while (cin >> input)
		all.push_back(input);
	vector<int>prev(all.size(), 0);//�ΨӦs�W�@�ӫ��V����
	for (int j = 2; j < all.size(); j++) {//�Ĥ@���w�g��F�A�q�ĤG���}�l
		if (all[j] < all[tail[1]])//�M�Ĥ@�����A�]��CeilIndex���|���Ĥ@�������աA�Y�O�s���Ȥp��Ĥ@����ơA�L�|�л\�������s�����׬��@�����ڦ�m
			tail[1] = j;//tail�s���שҹ����̤p�����ڪ���m
		else if (all[j] > all[tail[tail.size() - 1]])//�M�̫�@�����A�]��CeilIndex���|���Ĥ@��������
		{//�Y�O�s���Ȥ�̫�@����Ƥj�A�L�i�H���b�̫��A�����׼W�[
			prev[j] = tail[tail.size() - 1];//���ɫe�@���n�Otail.size() - 1����m�A�s�iprev���U�ڭ̫إ߶���
			tail.push_back(j);//�N�L����m���tail���̫᭱
		}
		else {
			int position = CeilIndex(1, tail.size() - 1, all[j]);//���W���U���A�M�n�䪺�ȡA�ݥL�i�H���b����
			prev[j] = tail[position - 1];//��쪺��(position) - 1�N�O�e�@��A�N�L�s�iprev
			tail[position] = j;//�N�L��itail��������m�A�]���L�O�Ӫ��פU���̤p��
		}
	}
	max = tail.size() - 1;//���ǦC���`����
	place = tail[max];//�̫�@��s����m
	cout << max << "\n-\n";
	for (; place != 0; place = prev[place])
		answer.push_back(all[place]);//�N�L�̤@�Ӥ@�ө�ianswer
	for (int i = answer.size() - 1; i >= 0; i--)//��ianswer�����׬O�˵ۦ^�Ӫ��A�ҥH�n�˵ۿ�X
		cout << answer[i] << endl;
}