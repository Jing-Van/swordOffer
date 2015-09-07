#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;
//�����г���һ�������
//˼·1��������ڣ�һ�����������λ��
//˼·2�����������ʱ�򣬳���һ�������Ӧ�����κ�ʱ��
int partition(vector<int> &numbers, int start ,int end);
bool checkMoreThanHalf(vector<int> &numbers,int key);

int moreThanHalfNumber(vector<int> numbers)
{
	int length = numbers.size();
	if(length == 0) return 0; //ע��߽��������
	int start = 0;
	int end = length-1; 
	int middle = length/2;
	int index = partition(numbers, start ,end);
	while( index!=middle ) {
		if(index > middle) {
			end = index -1;
			index = partition(numbers, start ,end);
		} else if(index < middle) {
			start = index + 1;
			index = partition(numbers,start ,end);
		}
	}
	int result = numbers.at(middle);
	//У��������Ƿ��ǳ���һ�������
	if(!checkMoreThanHalf(numbers,result))
		result = 0;
	return result;
}

//������partition
int partition(vector<int> &numbers, int start ,int end)
{

	int key = numbers.at(start);
	int i = start;
	int j = end;
	while(i < j) {
		//��������ɨ��
		while( i<j && key < numbers.at(j) )
			j--;
		//����Ԫ��
		if(i < j) {
			int temp = key;
			numbers[i] = numbers[j];
			numbers[j] = temp;
			i++;
		}
		//��������ɨ��
		while(i < j && key >= numbers.at(i) ) 
			i++;
		if(i < j) {
			int temp = numbers.at(i);
			numbers[i]  = numbers[j];
			numbers[j] = temp;
		}
	}
	numbers[i] = key;
	return i;
}

bool checkMoreThanHalf(vector<int> &numbers,int key)
{
	int length = numbers.size();
	int count = 0;
	for(int i=0; i< length; i++) {
		if(numbers.at(i) == key) count++;
	}
	if(count > length/2)
		return true;
	else 
		return false;
}

//˼·2
int MoreThanHalfNumber(vector<int> numbers)
{
	int length = numbers.size();
	if(length == 0) return 0;

	int result = numbers[0];
	int times = 1;
	for(int i = 1; i< length; i++ ) {
		if(numbers[i] == result) times++;
		else if(times == 0) {
			result = numbers[i];
			times = 1;
		} else times--;
	}

	int count = 0;
	for( int i=0; i< length; i++) {
		if(numbers[i] == result) count++;
	}
	if(count >= length/2) return result;
	else return 0;

}
int main()
{
	int a[] = {3,2,5,3,3,4,2,3,3,3,3};
	vector<int> input(a,a+sizeof(a)/sizeof(int));
	int result = MoreThanHalfNumber(input);
	cout << result << endl;
	return 0;
}

