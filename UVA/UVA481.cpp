//UVA481-What Goes Up
#include <iostream>
#include <vector>
using namespace std;
vector<int>all(1, 0), tail(2, 1), answer;//不考慮第零位，方便思考 || tail的第一位設為1，因為一開始一定會選到
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
	vector<int>prev(all.size(), 0);//用來存上一個指向哪裡
	for (int j = 2; j < all.size(); j++) {//第一筆已經選了，從第二筆開始
		if (all[j] < all[tail[1]])//和第一位比較，因為CeilIndex不會做第一筆的測試，若是新的值小於第一筆資料，他會覆蓋掉成為新的長度為一的尾巴位置
			tail[1] = j;//tail存長度所對應最小的尾巴的位置
		else if (all[j] > all[tail[tail.size() - 1]])//和最後一位比較，因為CeilIndex不會做第一筆的測試
		{//若是新的值比最後一筆資料大，他可以接在最後方，讓長度增加
			prev[j] = tail[tail.size() - 1];//此時前一位剛好是tail.size() - 1的位置，存進prev幫助我們建立順序
			tail.push_back(j);//將他的位置放到tail的最後面
		}
		else {
			int position = CeilIndex(1, tail.size() - 1, all[j]);//給上底下底，和要找的值，看他可以接在哪裡
			prev[j] = tail[position - 1];//找到的值(position) - 1就是前一位，將他存進prev
			tail[position] = j;//將他放進tail對應的位置，因為他是該長度下的最小值
		}
	}
	max = tail.size() - 1;//此序列的總長度
	place = tail[max];//最後一位存的位置
	cout << max << "\n-\n";
	for (; place != 0; place = prev[place])
		answer.push_back(all[place]);//將他們一個一個放進answer
	for (int i = answer.size() - 1; i >= 0; i--)//放進answer的答案是倒著回來的，所以要倒著輸出
		cout << answer[i] << endl;
}