#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include<cmath>

// returns true if and only if the specified huge integer is zero
bool isZero(int* hugeInt, int size);

void reset(int*& hugeInt, int& size);

// return true if and only if hugeInt1 == hugeInt2
bool equal(int* hugeInt1, int* hugeInt2, int size1, int size2);

// a recursive function that returns true if and only if hugeInt1 == hugeInt2
// provided that size1 == size2
bool recursiveEqual(int* hugeInt1, int* hugeInt2, int last);

// returns true if and only if hugeInt1 < hugeInt2
bool less(int* hugeInt1, int* hugeInt2, int size1, int size2);

// a recursive function that returns true if and only if hugeInt1 < hugeInt2
// provided that size1 == size2
bool recursiveLess(int* hugeInt1, int* hugeInt2, int last);

// minuend -= subtrahend
void subtractionAssignment(int*& minuend, int* subtrahend,
	int& minuendSize, int subtrahendSize);

// product *= multiplicand
void multiplicationAssignment(int* multiplicand, int*& product,
	int multiplicandSize, int& productSize);

// quotient = dividend / divisor; remainder = dividend % divisor
void division(int* dividend, int* divisor, int*& quotient, int*& remainder,
	int dividendSize, int divisorSize, int& quotientSize, int& remainderSize);

// hugeInt /= 10
void divideBy10(int* hugeInt, int& size);

const int arraySize = 200;

int main()
{
	int t, a, b;
	while (cin >> t >> a >> b)
	{
		cout << "(" << t << "^" << a << "-1)/(" << t << "^" << b << "-1) ";

		if (t == 1)
			cout << "is not an integer with less than 100 digits.\n";
		else if (a == b)
			cout << "1\n";
		else if (a < b)
			cout << "is not an integer with less than 100 digits.\n";
		else if (a % b != 0)
			cout << "is not an integer with less than 100 digits.\n";
		else if ((a - b) * static_cast<int>(log10(t)) > 99)
			cout << "is not an integer with less than 100 digits.\n";
		else
		{
			int* dividend = new int[1]();
			int* divisor = new int[1]();
			int* quotient = new int[1]();
			int* remainder = new int[1]();

			int dividendSize = 1;
			int divisorSize = 1;
			int quotientSize = 1;
			int remainderSize = 1;

			int temp = t;
			int* base = new int[10]();
			int baseSize = 0;
			while (temp > 0)
			{
				base[baseSize++] = temp % 10;
				temp /= 10;
			}

			dividend[0] = 1;
			for (int i = 0; i < a; ++i)
			{
				multiplicationAssignment(base, dividend, baseSize, dividendSize);
				if (dividendSize > arraySize)
					break;
			}

			if (dividendSize > arraySize)
				cout << "is not an integer with less than 100 digits.\n";
			else
			{
				divisor[0] = 1;
				for (int i = 0; i < b; ++i)
					multiplicationAssignment(base, divisor, baseSize, divisorSize);

				int oneSize = 1;
				int* one = new int[1]();
				one[0] = 1;
				subtractionAssignment(dividend, one, dividendSize, oneSize);
				subtractionAssignment(divisor, one, divisorSize, oneSize);

				division(dividend, divisor, quotient, remainder,
					dividendSize, divisorSize, quotientSize, remainderSize);

				if (quotientSize < 100 && isZero(remainder, remainderSize))
					for (int i = quotientSize - 1; i >= 0; i--)
						cout << quotient[i];
				else
					cout << "is not an integer with less than 100 digits.";
				cout << endl;
			}
		}
	}
}

// returns true if and only if the specified huge integer is zero
bool isZero(int* hugeInt, int size)
{
	if (size == 1 && hugeInt[0] == 0)
		return true;
	return false;
}

void reset(int*& hugeInt, int& size)
{
	size = 1;
	delete[] hugeInt;
	hugeInt = new int[1]();
}

// return true if and only if hugeInt1 == hugeInt2
bool equal(int* hugeInt1, int* hugeInt2, int size1, int size2)
{
	if (size1 != size2)
		return false;

	return recursiveEqual(hugeInt1, hugeInt2, size1 - 1);
}

// a recursive function that returns true if and only if hugeInt1 == hugeInt2
// provided that size1 == size2
bool recursiveEqual(int* hugeInt1, int* hugeInt2, int last)
{
	if(hugeInt1[last] != hugeInt2[last])
		return false;

	if (last == 0)
		return true;//���j���פ

	return recursiveEqual(hugeInt1, hugeInt2, last - 1);
}

// returns true if and only if hugeInt1 < hugeInt2
bool less(int* hugeInt1, int* hugeInt2, int size1, int size2)
{
	if (size1 < size2)
		return true;
	if (size1 > size2)
		return false;

	return recursiveLess(hugeInt1, hugeInt2, size1 - 1);
}

// a recursive function that returns true if and only if hugeInt1 < hugeInt2
// provided that size1 == size2
bool recursiveLess(int* hugeInt1, int* hugeInt2, int last)
{
	if (hugeInt1[last] < hugeInt2[last])
		return true;

	if (hugeInt1[last] > hugeInt2[last])
		return false;

	if (last == 0) {
		return false;
	}//���j���פ

	return recursiveLess(hugeInt1, hugeInt2, last - 1);
}

// minuend -= subtrahend
void subtractionAssignment(int*& minuend, int* subtrahend, int& minuendSize, int subtrahendSize)
{
	for (int i = 0; i < subtrahendSize; i++)
		minuend[i] -= subtrahend[i];//�۴�

	for (int i = 0; i < minuendSize; i++)
		if (minuend[i] < 0)
		{
			minuend[i] += 10;
			minuend[i + 1]--;
		}//�Y�O�Ʀr�p��0�A�ɦ�

	for (int i = minuendSize - 1; i > 0; i--) {
		if (minuend[i] == 0)
			minuendSize--;
		else
			break;
	}//�T�O�̰��줣��0
}

// product *= multiplicand
void multiplicationAssignment(int* multiplicand, int*& product, int multiplicandSize, int& productSize)
{
	int bufferSize;
	bufferSize = multiplicandSize + productSize;
	int* buffer = new int[bufferSize]();

	for (int i = 0; i < bufferSize; i++)
		buffer[i] = 0;//��l��

	for (int i = 0; i < multiplicandSize; i++)
		for (int j = 0; j < productSize; j++)
			buffer[i + j] += multiplicand[i] * product[j];//�i�歼�k

	delete[]product;
	productSize = bufferSize;
	product = new int[productSize]();

	for (int i = 0; i < bufferSize; i++) {
		product[i] = buffer[i];
	}

	for (int i = 0; i < productSize; i++)
		if (product[i] > 9)
		{
			product[i + 1] += product[i] / 10;
			product[i] %= 10;
		}//�Y�Ʀr�j��10�A�i��

	for (int i = productSize - 1; i > 0; i--) {
		if (product[i] == 0)
			productSize--;
		else
			break;
	}//�T�O�̰��줣��0

	delete[]buffer;
}

// quotient = dividend / divisor; remainder = dividend % divisor
void division(int* dividend, int* divisor, int*& quotient, int*& remainder,
	int dividendSize, int divisorSize, int& quotientSize, int& remainderSize)
{
	if (isZero(dividend, dividendSize))
	{
		reset(quotient, quotientSize);
		reset(remainder, remainderSize);
		return;
	}//�Q���Ƭ�0�A������X�өM�l��

	remainderSize = dividendSize;//�l�Ʀ�ƩM�Q���Ƥ@��
	delete[] remainder;
	remainder = new int[remainderSize]();

	delete[] quotient;
	quotient = new int[1]();

	for (int i = 0; i <= dividendSize - 1; i++) {
		remainder[i] = dividend[i];
	}//��Q���ƪ��ȼg�i�l�Ƹ̭�

	if (equal(dividend, divisor, dividendSize, divisorSize)) {
		quotientSize = 1;
		quotient[0] = 1;
		reset(remainder, remainderSize);
		return;
	}//��Ƭ۵��ɡA������X��ӼƩM�l��

	if (less(dividend, divisor, dividendSize, divisorSize))
	{
		reset(quotient, quotientSize);
		return;
	}//�Y�Q���ƪ���Ƥp�󰣼ƪ���ƪ�����X�ӼƩM�l��

	quotientSize = dividendSize - divisorSize + 1;//�D�Ӽƪ�SIZE
	delete[] quotient;
	quotient = new int[quotientSize]();

	int* buffer = new int[dividendSize](), bufferSize;
	bufferSize = dividendSize;//�N�䩹�����ɥ������NdivisorSize�[�j

	for (int i = 0; i < quotientSize; i++) {
		quotient[i] = 0;
	}//���N�ӼƳ]��0

	for (int i = dividendSize - 1, j = divisorSize - 1; j >= 0; i--, j--)
		buffer[i] = divisor[j];//�N���Ʋ���

	if (!less(buffer, dividend, bufferSize, dividendSize)) {
		divideBy10(buffer, bufferSize);
		quotientSize--;
	}//�T�w��������A���ƨ̵M�p��Q���ơA���M���k���@��

	for (int i = quotientSize - 1; i >= 0; i--) {
		while (1) {
			if (!less(remainder, buffer, remainderSize, bufferSize)) {
				quotient[i]++;
				subtractionAssignment(remainder, buffer, remainderSize, bufferSize);
			}//�@�몺��k
			else {
				divideBy10(buffer, bufferSize);
				break;
			}//��remainder���Ȥp��divisor���ȮɡA�Ndivisor�V�k��
		}
	}//�������X����������
	delete[] buffer;
}

// hugeInt /= 10
void divideBy10(int* hugeInt, int& size)
{
	if (size == 1)
		hugeInt[0] = 0;
	else
	{
		for (int i = 1; i < size; i++)
			hugeInt[i - 1] = hugeInt[i];

		size--;
		hugeInt[size] = 0;
	}
}