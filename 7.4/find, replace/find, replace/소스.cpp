#include <iostream>
#include <string>

int main()
{
	std::string s1;
	std::cout << "문장을 입력 : ";
	std::getline(std::cin, s1, '\n');
	std::cin.ignore(); // 버퍼 초기화

	std::string s2, s3;
	std::cout << "찾을단어 : ";
	std::getline(std::cin, s2, '\n');
	std::cout << "바꿀 단어 : ";
	std::getline(std::cin, s3, '\n');

	int index=0;

	while (1)
	{
		int fix_index = s1.find(s2, index);
		if (fix_index == -1)
			break;
		s1.replace(fix_index, s2.length(), s3);
		index = fix_index + s3.length();
	}
	std::cout << s1 << std::endl;
}