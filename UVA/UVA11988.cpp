#include <iostream>
#include <list>
#include <string>
using namespace std;
int main()
{
	string sentence;
	while (getline(cin, sentence)) {
		list<string> answer;//�C���Nlist���s�}
		for (int i = sentence.size() - 1; i >= 0; i--)//�ѫ᭱���e�P�_
			if (sentence[i] == '[') {//�J�쥪�A���A�n�N���A����k�A���Υ��A��(�Y�L�A���h�쩳)���F����̫e��
				string temp;//�C���Ntemp���s�}
				int j = i + 1;//�q���A�����U�@��}�l
				for (; j < sentence.size(); j++) {//��~�l�����ڰ���
					if (sentence[j] == '[' || sentence[j] == ']')//��k�A���Υ��A������
						break;
					temp.push_back(sentence[j]);
				}
				sentence.erase(sentence.begin() + i, sentence.begin() + j);//�N�r��ŤU��
				answer.push_back(temp);//�N�������r���ilist������
			}
		for (int i = 0; i < sentence.size(); i++)
			if (sentence[i] == ']') {//��S�R�����k�A���R��
				sentence.erase(sentence.begin() + i);
				i--;
			}
		answer.push_back(sentence);//�N�y�l��ilist������
		for (list<string>::iterator it = answer.begin(); it != answer.end(); it++)
			cout << *it;//���Ӷ��ǿ�X
		cout << endl;
	}
}