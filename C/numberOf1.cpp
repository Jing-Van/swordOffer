#include "stdafx.h"
//��Ŀ����һ��������������������Ʊ�ʾ��1�ĸ���


//���ڸ��������ܻ������ѭ��
//int numberOf1(int n)
//{
//	int count = 0;
//	while(n) {
//		int result = n&1;
//		if(result == 1) count++;
//		n = n>>1;
//	}
//	return count;
//}
//���Խ������������ѭ�������⣬������Ҫѭ��32�Σ�Ч�ʲ��ߡ�
//int numberOf1(int n)
//{
//	int count = 0;
//	unsigned int flag = 1;
//	while(flag) {
//		if(n & flag)
//			count++;
//		flag = flag << 1;
//	}
//	return count;
//}

//ʹ��n&(n-1)�����ұ�һ��1��Ϊ0
int numberOf1(int n)
{
	int count = 0;
	while(n) {
		count++;
		n = n&(n-1);
	}
	return count;
}

int main()
{
	int result = numberOf1(9999);
	printf("%d\n",result);

	return 0;
}

//test
//0x80000000
//9999