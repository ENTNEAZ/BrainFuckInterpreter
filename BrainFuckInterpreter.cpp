// BrainFuckInterpreter.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

/*
1.检查是否合法（括号是否匹配）
2.交给函数执行
*/
extern bool isLegal(std::string);
int main()
{
    std::string a;
    std::cin >> a;
    std::cout << isLegal(a);
}
