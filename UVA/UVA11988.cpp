#include <iostream>
#include <list>
#include <string>
using namespace std;
int main()
{
	string sentence;
	while (getline(cin, sentence)) {
		list<string> answer;//每次將list重新開
		for (int i = sentence.size() - 1; i >= 0; i--)//由後面往前判斷
			if (sentence[i] == '[') {//遇到左括號，要將左括號到右括號或左括號(若無括號則到底)的東西放到最前面
				string temp;//每次將temp重新開
				int j = i + 1;//從左括號的下一位開始
				for (; j < sentence.size(); j++) {//到居子的尾巴停止
					if (sentence[j] == '[' || sentence[j] == ']')//到右括號或左括號停止
						break;
					temp.push_back(sentence[j]);
				}
				sentence.erase(sentence.begin() + i, sentence.begin() + j);//將字串剪下來
				answer.push_back(temp);//將收集的字串放進list的尾巴
			}
		for (int i = 0; i < sentence.size(); i++)
			if (sentence[i] == ']') {//把沒刪掉的右括號刪掉
				sentence.erase(sentence.begin() + i);
				i--;
			}
		answer.push_back(sentence);//將句子放進list的尾巴
		for (list<string>::iterator it = answer.begin(); it != answer.end(); it++)
			cout << *it;//按照順序輸出
		cout << endl;
	}
}