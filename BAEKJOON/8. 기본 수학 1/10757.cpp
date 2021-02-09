#include <iostream>
#include <string>
using namespace std;

int atoi(char ch);
char itoa(int num);
string addStr(string str1, string str2);

int main(void) {

	string A, B;
	cin >> A >> B;

	string result = "";

	if (A.length() >= B.length()) {
		result = addStr(A, B);
	}
	else {
		result = addStr(B, B);
	}

	cout << result;

	return 0;
}

int atoi(char ch) {
	return ch - '0';
}

char itoa(int num) {
	return num + '0';
}

string addStr(string str1, string str2) {
	
	string result = "";
	int temp = 0;	//str1�� str2�� i��° �ڸ��� ���� ������ ����
	int temp1 = 0;	//���� temp�� 10 �̻��� �� 10�� ������ ����

	for (int i = 0; i < str1.length(); i++) {

		if (i >= str2.length()) {	//str2�� �� �̻� ���꿡 �������� ������
			temp = atoi(str1[str1.length() - 1 - i]) + temp1;
			temp1 = 0;
		}
		else {
			temp = atoi(str1[str1.length() - 1 - i])
				+ atoi(str2[str2.length() - 1 - i]) + temp1;
			temp1 = 0;
		}

		if (temp > 9) {	//temp�� �� �ڸ����� 

			int j = i;
			while (true) {
				j++;
				if (j + 1 == str1.length()) {

				}
				else {
					str1[str1.length() - 1 - j] += 1;
				}
			}





			if (i + 1 == str1.length()) {	//���� �����ϴ� �ڸ����� str1�� �ڸ����� ������
				result = "1" + itoa(temp - 10) + result;
			}



			else {
				result = itoa(temp - 10) + result;

				int j = i;
				while (true) {	//���� �ϳ� �� �߰�����
					if (str1[str1.length() - 1 - j] != '9') {
						str1[str1.length() - 1 - j] += 1;
					}
					else {
						j++;
					}
				}
			}
		}





		else {	//temp�� 1�ڸ� ����
			result = itoa(temp) + result;
			temp1 = 0;
		}
	}

	return result;
}