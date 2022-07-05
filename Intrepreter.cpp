#include <iostream>
#include <vector>
/*
�ַ�	����
>	ָ���һ
<	ָ���һ
+	ָ����ָ�ֽڵ�ֵ��һ
-	ָ����ָ�ֽڵ�ֵ��һ
.	���ָ����ָ�ֽ����ݣ�ASCII�룩
,	��ָ����ָ���ֽ��������ݣ�ASCII�룩
[	��ָ����ָ�ֽڵ�ֵΪ�㣬�������ת����ת�����Ӧ��]����һ��ָ�
]	��ָ����ָ�ֽڵ�ֵ��Ϊ�㣬����ǰ��ת����ת�����Ӧ��[����һ��ָ�
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