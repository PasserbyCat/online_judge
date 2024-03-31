#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int n;

int CeilIndex(int A[], int tail[], int low, int high, int key)
{
	while (high - low > 1)
	{
		int mid = (high + low) / 2;
		if (A[tail[mid]] >= key)
			high = mid;
		else
			low = mid;
	}
	return high;
}
int main()
{
	while (cin >> n) {
		int A[10001] = {}, B[10001] = {}, tail[10001] = {}, rtail[10001] = {},
			prev[10001] = {}, rprev[10001] = {}, lis[10001] = {}, rlis[10001] = {};
		int rlength = 1, length = 1;
		tail[1] = rtail[1] = 1;
		for (int i = 1; i < n + 1; i++) {
			cin >> A[i];
			B[n + 1 - i] = A[i];
		}
		for (int i = 2; i <= n; i++)
		{
			if (A[i] < A[tail[1]]) {
				tail[1] = i;
				lis[i] = 1;
			}
			else if (A[i] > A[tail[length]])
			{
				prev[i] = tail[length];
				tail[++length] = i;
				lis[i] = length;
			}
			else
			{
				int position = CeilIndex(A, tail, 1, length, A[i]);
				prev[i] = tail[position - 1];
				tail[position] = i;
				lis[i] = position;
			}
			if (B[i] < B[rtail[1]]) {
				rtail[1] = i;
				rlis[i] = 1;
			}
			else if (B[i] > B[rtail[rlength]])
			{
				rprev[i] = rtail[rlength];
				rtail[++rlength] = i;
				rlis[i] = rlength;
			}
			else
			{
				int position = CeilIndex(B, rtail, 1, rlength, B[i]);
				rprev[i] = rtail[position - 1];
				rtail[position] = i;
				rlis[i] = position;
			}
		}
		int answer = 1;
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j <= n + 1 - i; j++)
			if (lis[i] == rlis[j])
				if (answer < lis[i])
					answer = lis[i];
		}
		cout << answer * 2 - 1 << endl;
	}
}