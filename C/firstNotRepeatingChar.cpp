//��ȡ�ַ����е�һ��ֻ����һ�ε��ַ�
//˼·�������ַ������ͺ����ÿһ���ַ��Ƚϣ����û���ظ��ͷ���,O(n^2)
//����˼·���ʹ�����أ�������ͳ�ƴ����������ַ�����ͳ��ÿ���ַ����ֵĴ���(��ϣ��洢�����ڶ��α������ӹ�ϣ����ȡ���ݣ��������Ϊ1�ͷ���
#include "stdafx.h"
#include<string>
using namespace std;
int firstNotRepeatingChar(string str) {
	int length = str.length();
	if(length == 0) return -1;

	//����������
	int hashTable[256]={0};
	for(int i=0; i< length; i++) {
		hashTable[str.at(i)]++;
	}
	//���������Ҽ���
	int i=0;
	for(i=0; i< length; i++) {
		if(hashTable[str.at(i)] == 1)
			return i;
	}
	if(i == length)
		return -1;
}


int main()
{
	string input = "hehllo,world";
	int index = firstNotRepeatingChar(input);
	printf("%d\n",index);
	return 0;
}

