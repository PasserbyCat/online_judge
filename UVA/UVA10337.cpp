//UVA10337 - ���w����Z���P�U������쪺���t�A��X���檺�̤֯Ӫo�q
#include <iostream>
using namespace std;
int main()
{
	int test, ** sky, mile, ** arrive;
	cin >> test;
	sky = new int* [10]();
	arrive = new int* [10]();
	for (int z = 0; z < test; z++) {
		cin >> mile;
		mile /= 100;//�C100���ش��@�����氪��
		for (int i = 9; i > -1; i--) {
			sky[i] = new int[mile + 1]();
			for (int j = 0; j < mile; j++)
				cin >> sky[i][j];//��J���t
			arrive[i] = new int[mile + 1]();
			for (int j = 0; j < mile + 1; j++)
				arrive[i][j] = 1000000;//�]�w���ݭ�
		}
		arrive[0][0] = 0;
		for (int i = 0; i < mile; i++)
			for (int j = 0; j < 10; j++) {//�Y�O�U�@�檺�Ӫo�q���h�A�אּ���֪�
				if (arrive[j][i + 1] > arrive[j][i] - sky[j][i] + 30)
					arrive[j][i + 1] = arrive[j][i] - sky[j][i] + 30;
				if (j == 0) {//�S����C��
					if (arrive[j][i + 1] > arrive[j + 1][i] - sky[j + 1][i] + 20)
						arrive[j][i + 1] = arrive[j + 1][i] - sky[j + 1][i] + 20;
				}
				else if (j == 9) {//�S���󰪪�
					if (arrive[j][i + 1] > arrive[j - 1][i] - sky[j - 1][i] + 60)
						arrive[j][i + 1] = arrive[j - 1][i] - sky[j - 1][i] + 60;
				}
				else {
					if (arrive[j][i + 1] > arrive[j + 1][i] - sky[j + 1][i] + 20)
						arrive[j][i + 1] = arrive[j + 1][i] - sky[j + 1][i] + 20;
					if (arrive[j][i + 1] > arrive[j - 1][i] - sky[j - 1][i] + 60)
						arrive[j][i + 1] = arrive[j - 1][i] - sky[j - 1][i] + 60;
				}
			}
		cout << arrive[0][mile] << endl << endl;//�̫ᥲ�w�b��0��
		for (int i = 9; i > -1; i--) {
			delete[]sky[i];
			delete[]arrive[i];
		}
	}
	delete[]sky;
	delete[]arrive;
}
