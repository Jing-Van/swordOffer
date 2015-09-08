//��������Ѱ��һ����
//���飬�����ӡ�������
//˼·���Ӿ��������У��ҳ���ͨ���ɣ������Ͻǿ�ʼ���ң�����򷵻أ�key>ֵ��ȥ���У�key<ֵ��ȥ����

#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;

bool Find(vector<vector<int> > array,int target)
{
	//bool result = false;
	int rows = array.size();
	if(rows == 0) return false;
	int columns = array[0].size();
	if(columns == 0 ) return false;

	int row = 0, column = columns-1;
	while(row < rows && column >= 0) {
		if(array.at(row).at(column) == target)
			return true;
		else if(array.at(row).at(column) > target)
			column--;
		else row++;
	}
	return false;
}

int main()
{
	//int array[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,9,12},{6,8,11,15}};
	vector<vector<int>> input(4,vector<int>(4));
	int count = 1;
	for(int i=0;i<4;i++) {
		for(int j=0;j <4; j++) {
			input.at(i).at(j) =  count;
			count++;
		}
	}
	bool result = Find(input,7);
	cout << result << endl;
	return 0;
}


