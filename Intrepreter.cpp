#include <iostream>
#include <vector>
/*
字符	含义
>	指针加一
<	指针减一
+	指针所指字节的值加一
-	指针所指字节的值减一
.	输出指针所指字节内容（ASCII码）
,	向指针所指的字节输入内容（ASCII码）
[	若指针所指字节的值为零，则向后跳转，跳转到其对应的]的下一个指令处
]	若指针所指字节的值不为零，则向前跳转，跳转到其对应的[的下一个指令处
*/

extern bool isLegal(std::string);

void safeMemory(std::vector<char>& memory, int memoryPointer) {
	if (memoryPointer >= memory.size()) {
		memory.resize(memoryPointer + 1);
	}
}


void interpreter(std::string str,bool outputError = true) {
	if (!isLegal(str)) {
		return;
	}
	std::vector<char> memory;
	std::vector<int> stack;
	int commandPointer = 0;
	int memoryPointer = 0;
	while (commandPointer != str.length()) {
		safeMemory(memory, memoryPointer);
		switch (str[commandPointer])
		{
		case '>':
			memoryPointer++;
			break;
		case '<':
			if (memoryPointer == 0) {
				std::cout << "Error at" << commandPointer << ",memoryPointer is 0" << '\n';
			}
			else {
				memoryPointer--;
			}
			break;
		case '+':
			memory[memoryPointer]++;
			break;
		case '-':
			memory[memoryPointer]--;
			break;
		case '.':
			std::cout << memory[memoryPointer];
			break;
		case ',':
			char a;
			std::cin >> a;
			memory[memoryPointer] = a;
			break;
		case '[':
			if (memory[memoryPointer] != 0) {
				stack.push_back(commandPointer);
			}
			else {
				for (int i = commandPointer + 1; i < str.length(); i++) {
					if (str[i] == ']') {
						commandPointer = i;
						break;
					}
				}
			}
			break;
		case ']':
			if (memory[memoryPointer] == 0) {
				stack.pop_back();
			}
			else {
				commandPointer = stack.back();
			}
			break;
		default:
			if (outputError) {
				std::cout << "unknownCommand:\"" << str[commandPointer] << "\"\n";
			}
			break;
		}
		commandPointer++;
	}
	return;
}