//�滻�ַ����еĿո�Ϊ%20
//Ū����ܷ��������µĿռ�ȥ�洢�����ﲻ�¿��ٴ洢�ռ�
//˼·����ͳ�ƿո�ĸ����������ת����Ŀռ䣬Ȼ��Ӻ�����ǰ���滻�ո�
#include "stdafx.h"
#include<string.h>

void replaceSpace(char *str,int length) {
	if(str == nullptr) return;
	int spaceCount = 0;
	for(int i=0;i < length; i++) {
		if(str[i] == ' ') spaceCount++;
	}
	int afterLength = length + spaceCount*2;

	int indexOfOriginal = length-1;
	int indexOfNew = afterLength-1;
	while(indexOfOriginal >=0 && indexOfNew > indexOfOriginal) {
		if(str[indexOfOriginal] == ' ') {
			str[indexOfNew --] = '0';
			str[indexOfNew --] = '2';
			str[indexOfNew --] = '%';
			indexOfOriginal--;
		} else {
			str[indexOfNew --] = str[indexOfOriginal--];
		}
	}
}

int main()
{
	char input[20] = "hello world";
	replaceSpace(input,strlen(input)+1);
	printf("%s\n",input);
	return 0;
}
