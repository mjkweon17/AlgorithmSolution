#include <iostream>
using namespace std;

int babylonian(int distance);

int main(void) {

	int T;	//�׽�Ʈ ���̽�
	cin >> T;

	for (int i = 0; i < T; i++) {

		int x, y;	//���� ��ġ, ��ǥ ��ġ
		cin >> x >> y;
		int distance = y - x;

		int count = 0;	//�̵� Ƚ��

		int n = babylonian(distance); //�ִ� �̵� �Ÿ�
		
		count += 2 * n - 1;
		
		int left = distance - n * n;
		
		if (left > n) {
			count += 2;
		}
		else if (left <= n && left > 0) {
			count += 1;
		}
		
		cout << count << endl;
	}

	return 0;
}

int babylonian(int distance) {
	int x = distance;
	int y = 1;
	while (x > y) {
		x = (x + y) / 2;
		y = distance / x;
	}
	return x;
}