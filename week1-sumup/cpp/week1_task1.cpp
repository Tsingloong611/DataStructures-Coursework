/*
* ��дʱ�䣺2024/8/31
* ����汾��V1.0
* �����ߣ�xx
*
* �����ܣ����ڸ�����������n���� 1 + 2 + 3 + ... + n
* �������ݣ��û���������������
* ����������Ļ��ʾ 1 + 2 + 3 + ... + n �Ľ��
*/

/*����ͷ�ļ�*/
#include<iostream>
#include <time.h>
using namespace std;

/// <summary>
/// �Ӻ���sum���壬���� 1 + 2 + 3 + ... + n �Ľ��
/// </summary>
/// <param name="n">ֵ����</param>
/// <returns>���� 1 + 2 + 3 + ... + n �Ľ��</returns>
int sum(int n) {
	int result = 0; // �����������
	// ѭ��������
	for (int i = 1; i <= n; i++) {
		result += i;
	}
	return result; // ���ؽ��
}

/// <summary>
/// �Ӻ���sum���壬���� 1 + 2 + 3 + ... + n �Ľ��
/// </summary>
/// <param name="n">ֵ����</param>
/// <returns>���� 1 + 2 + 3 + ... + n �Ľ��</returns>
int sum_plus(int n) {
	return n * (n + 1) / 2; // ���ؽ��
}

/// <summary>
/// �Ӻ���check���壬�����ݽ��м򵥼���(�Ƿ�>0)
/// </summary>
/// <param name="num">ֵ����</param>
/// <returns>���ز���ֵ��true��ʾ�Ϸ����ݣ�false��ʾ�Ƿ�����</returns>
bool check(int n) {
	if (n > 0) {
		return true;
	}
	else {
		return false;
	}
}

/// <summary>
/// ���������壬�������
/// </summary>
void main() {
	// ��������
	int n;
	int result;
	clock_t begin = clock();
	clock_t end = clock();
	double duration;

	// ѭ��ִ��
	while (true) {
		cout << "please input a number (>0): " << endl;
		cin >> n;
		if (check(n)) {
			begin = clock();
			result = sum(n);
			end = clock();
			duration = double(end - begin) / CLOCKS_PER_SEC;
			cout << "normal way to sum result: " << result << " ;normal way takes time: " << duration << endl;

			begin = clock();
			result = sum_plus(n);
			end = clock();
			duration = double(end - begin) / CLOCKS_PER_SEC;
			cout << "better way to sum result: " << result << " ;better way takes time: " << duration << endl;
		}
		else {
			cout << "error input" << endl;
		}
	}
}