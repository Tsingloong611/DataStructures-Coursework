/*
* 编写时间：2024/8/31
* 程序版本：V1.0
* 开发者：xx
*
* 程序功能：对于给定的正整数n，求 1 + 2 + 3 + ... + n
* 输入数据：用户键盘输入正整数
* 输出结果：屏幕显示 1 + 2 + 3 + ... + n 的结果
*/

/*引用头文件*/
#include<iostream>
#include <time.h>
using namespace std;

/// <summary>
/// 子函数sum定义，计算 1 + 2 + 3 + ... + n 的结果
/// </summary>
/// <param name="n">值传递</param>
/// <returns>返回 1 + 2 + 3 + ... + n 的结果</returns>
int sum(int n) {
	int result = 0; // 结果变量定义
	// 循环计算结果
	for (int i = 1; i <= n; i++) {
		result += i;
	}
	return result; // 返回结果
}

/// <summary>
/// 子函数sum定义，计算 1 + 2 + 3 + ... + n 的结果
/// </summary>
/// <param name="n">值传递</param>
/// <returns>返回 1 + 2 + 3 + ... + n 的结果</returns>
int sum_plus(int n) {
	return n * (n + 1) / 2; // 返回结果
}

/// <summary>
/// 子函数check定义，对数据进行简单检验(是否>0)
/// </summary>
/// <param name="num">值传递</param>
/// <returns>返回布尔值，true表示合法数据，false表示非法数据</returns>
bool check(int n) {
	if (n > 0) {
		return true;
	}
	else {
		return false;
	}
}

/// <summary>
/// 主函数定义，程序入口
/// </summary>
void main() {
	// 变量定义
	int n;
	int result;
	clock_t begin = clock();
	clock_t end = clock();
	double duration;

	// 循环执行
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