//UVA10943_How do you add?
//���D�B�έ��ƲզX
#include <iostream>
using namespace std;
int truth[46]{ 2, 3, 5,	7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
101, 103, 107, 109,	113, 127, 131, 137,	139, 149, 151 ,157 ,163	,167, 173, 179, 181, 191, 193, 197 ,199 };//�C�X��ƪ�
int main()
{
	int N, K;//K�O�����ƭӼơAN�O�ƭӥ����ƪ��X �d�� : N = 5, K = 3 �h��ܦ� x+y+z=5���X�زզX
	while (cin >> N >> K) {
		if (N == 0 || K == 0)//�פ����
			break;
		int up = N + K - 1, down = up - N, answer = 1;//���ƲզX���W��up = N + K - 1
		if (down > N)//���ƲզX���U��down = up - N = K - 1�A�ڭ̨����p���ȡA�B��W���²��
			down = N;
		int co[46] = {};//�t�X��ƪ�A�i���]�Ƥ��ѡA�ΨӰO���ӽ�Ʀ��X����
		for (; down > 0; down--, up--)//�ΤW�U�ɪ����i�滼��B��(�]�N�O����)
			for (int k = 0, i = up, j = down; truth[k] <= up; k++) {
				while (i % truth[k] == 0) {
					co[k]++;//���l�����+��
					i /= truth[k];
				}
				while (j % truth[k] == 0) {
					co[k]--;//���������-��
					j /= truth[k];
				}
			}
		for (int i = 0; i < 46; i++)
			for (int j = 0; j < co[i]; j++) {//�i��̫᪺�B��
				answer *= truth[i];
				answer %= 1000000;
			}
		cout << answer << endl;
	}
}
