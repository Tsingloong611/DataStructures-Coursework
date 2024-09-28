/*
* 编写时间：2024/8/31
* 程序版本：V1.0
* 开发者：陈铠
*
* 程序功能：对于给定的正整数n，求1~n的素数个数
* 输入数据：用户键盘输入正整数
* 输出结果：屏幕显示1~n的素数个数
*/

/*引用头文件*/
#include<iostream>
using namespace std;

/// <summary>
/// 子函数is_prime定义，判断某一数是否为质数
/// </summary>
/// <param name="n">值传递，要判断的正整数</param>
/// <returns>返回布尔值，true表示是质数，false表示不是质数</returns>
bool is_prime(int n) {
	// 判断 1 及更小的数是否为素数
	if (n <= 1) {
		return false;
	}
	// 判断 2 及更大的数是否为素数
	for (int i = 2; i <= int(n / 2); i++) {
		if (n % i == 0 && n != 2) {
			return false;
		}
	}
	return true; //上述判断均未返回false，则返回true
}

/// <summary>
/// 子函数count定义，求1~n的素数个数
/// </summary>
/// <param name="n">值传递，要截至的正整数</param>
/// <returns>整型，表示1~n的素数个数</returns>
int count(int n) {
	// 变量定义
	int count = 0;
	// 统计结果
	for (int i = 1; i <= n; i++) {
		if (is_prime(i)) {
			count++;
		}
	}
	return count; // 返回结果
}

/// <summary>
/// 子函数is_prime_plus定义，传入一个数组与一个结束值n，首先初始化数列为1-n，然后将1-n中非质数部分赋值0
/// </summary>
/// <param name="arr">地址传递</param>
/// <param name="n">值传递</param>
void is_prime_plus(int* arr, int n) {
	// 数组初始化
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}
	arr[0] = 0; // 手动指定 1 不是质数
	// 计算2及以后的结果
	for (int j = 2; j * j <= n; j++) {
		for (int x = j * j; x <= n; x += j) {
			if (arr[x - 1] != 0) {
				arr[x - 1] = 0;
			}
		}
	}
}

/// <summary>
/// 子函数count_plus定义，求1~n的素数个数
/// </summary>
/// <param name="n">值传递</param>
/// <returns>返回整型，1~n的素数个数</returns>
int count_plus(int n) {
	// 变量定义
	int count = 0;
	int* arr = new int[n];

	is_prime_plus(arr, n); // 处理数组

	// 统计结果
	for (int i = 0; i < n; i++) {
		if (arr[i] != 0) {
			count++;
		}
	}
	return count; //返回结果
}

/// <summary>
/// 子函数check定义，对数据进行简单检验(是否>0)
/// </summary>
/// <param name="num">值传递</param>
/// <returns>返回布尔值，true表示合法数据，false表示非法数据</returns>
bool check(int num) {
	if (num > 0) {
		return true;
	}
	return false;
}

/// <summary>
/// 主函数定义，程序入口
/// </summary>
void main() {
	// 变量定义
	int num;
	int countResult;
	int countplusResult;

	// 循环执行
	while (true) {
		cout << "请输入一个正整数：" << endl;
		cin >> num;
		if (check(num)) {
			countResult = count(num);
			countplusResult = count_plus(num);
			cout << "normal way result: " << countResult << "\nbetter way result: " << countplusResult << endl;
		}
		else {
			cout << "错误的输入" << endl;
		}
	}
}