#include <iostream>
#include <vector>




bool isLegal(std::string str) {
	//����ջ��ȷ���Ƿ�Ϸ�
	std::vector<char> a;
	for (int i = 0; i < str.length(); i++) {
		switch (str[i])
		{
		case '[':
			a.push_back('[');
			break;
		case ']':
			if (a.size() == 0) {
				return false;
			}
			else {
				a.pop_back();
			}
			break;
		default:
			break;
		}
	}
	
	return (a.size() == 0) ? true : false;
}
