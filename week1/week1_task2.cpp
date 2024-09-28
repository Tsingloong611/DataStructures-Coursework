/*
* ��дʱ�䣺2024/8/31
* ����汾��V1.0
* �����ߣ�����
*
* �����ܣ����ڸ�����������n����1~n����������
* �������ݣ��û���������������
* ����������Ļ��ʾ1~n����������
*/

/*����ͷ�ļ�*/
#include<iostream>
using namespace std;

/// <summary>
/// �Ӻ���is_prime���壬�ж�ĳһ���Ƿ�Ϊ����
/// </summary>
/// <param name="n">ֵ���ݣ�Ҫ�жϵ�������</param>
/// <returns>���ز���ֵ��true��ʾ��������false��ʾ��������</returns>
bool is_prime(int n) {
	// �ж� 1 ����С�����Ƿ�Ϊ����
	if (n <= 1) {
		return false;
	}
	// �ж� 2 ����������Ƿ�Ϊ����
	for (int i = 2; i <= int(n / 2); i++) {
		if (n % i == 0 && n != 2) {
			return false;
		}
	}
	return true; //�����жϾ�δ����false���򷵻�true
}

/// <summary>
/// �Ӻ���count���壬��1~n����������
/// </summary>
/// <param name="n">ֵ���ݣ�Ҫ������������</param>
/// <returns>���ͣ���ʾ1~n����������</returns>
int count(int n) {
	// ��������
	int count = 0;
	// ͳ�ƽ��
	for (int i = 1; i <= n; i++) {
		if (is_prime(i)) {
			count++;
		}
	}
	return count; // ���ؽ��
}

/// <summary>
/// �Ӻ���is_prime_plus���壬����һ��������һ������ֵn�����ȳ�ʼ������Ϊ1-n��Ȼ��1-n�з��������ָ�ֵ0
/// </summary>
/// <param name="arr">��ַ����</param>
/// <param name="n">ֵ����</param>
void is_prime_plus(int* arr, int n) {
	// �����ʼ��
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}
	arr[0] = 0; // �ֶ�ָ�� 1 ��������
	// ����2���Ժ�Ľ��
	for (int j = 2; j * j <= n; j++) {
		for (int x = j * j; x <= n; x += j) {
			if (arr[x - 1] != 0) {
				arr[x - 1] = 0;
			}
		}
	}
}

/// <summary>
/// �Ӻ���count_plus���壬��1~n����������
/// </summary>
/// <param name="n">ֵ����</param>
/// <returns>�������ͣ�1~n����������</returns>
int count_plus(int n) {
	// ��������
	int count = 0;
	int* arr = new int[n];

	is_prime_plus(arr, n); // ��������

	// ͳ�ƽ��
	for (int i = 0; i < n; i++) {
		if (arr[i] != 0) {
			count++;
		}
	}
	return count; //���ؽ��
}

/// <summary>
/// �Ӻ���check���壬�����ݽ��м򵥼���(�Ƿ�>0)
/// </summary>
/// <param name="num">ֵ����</param>
/// <returns>���ز���ֵ��true��ʾ�Ϸ����ݣ�false��ʾ�Ƿ�����</returns>
bool check(int num) {
	if (num > 0) {
		return true;
	}
	return false;
}

/// <summary>
/// ���������壬�������
/// </summary>
void main() {
	// ��������
	int num;
	int countResult;
	int countplusResult;

	// ѭ��ִ��
	while (true) {
		cout << "������һ����������" << endl;
		cin >> num;
		if (check(num)) {
			countResult = count(num);
			countplusResult = count_plus(num);
			cout << "normal way result: " << countResult << "\nbetter way result: " << countplusResult << endl;
		}
		else {
			cout << "���������" << endl;
		}
	}
}