#include"stdafx.h"
#include<vector>
#include<algorithm>
#include<functional>
#include<set>
using namespace std;
//�����С��k����
//2��˼·
//˼·1�����ÿ��ŵ�˼�룬�ҵ��±�Ϊk�Ļ���������k֮ǰ����Ϊ��С��k������O(n)
//˼·2��ʹ��һ��������¼��С��k������ÿ�ζ���һ���������������������Աȣ�
//���С�������,ɾ�������������������������Բ������ѣ���������д������Ҫһ����ʱ�䣬����ʹ��multiset(STL�л��ں����ʵ��)
int partition(vector<int> &numbers, int start ,int end);

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {   
	int length = input.size();
	vector<int> result;
	if(length == 0 || k<=0 || k > length)  return result;
	int start = 0;
	int end = length-1;
	int index = partition(input,start, end);
	while(index != (k-1)) {
		if(index < (k-1)) {
			start = index+1;
			index = partition(input, start, end);
		} else  {
			end = index -1;
			index = partition(input, start ,end);
		}
	}

	//�ҵ�λ����k�Ļ���������ǰk����
	for(int i =0 ; i < k; i++) {
		result.push_back(input[i]);
	}
	return result;
}


//������partition
//int partition(vector<int> &numbers, int start ,int end)
//{
//
//	int key = numbers.at(start);
//	int i = start;
//	int j = end;
//	while(i < j) {
//		//��������ɨ��
//		while( i<j && key < numbers.at(j) )
//			j--;
//		//����Ԫ��
//		if(i < j) {
//			int temp = key;
//			numbers[i] = numbers[j];
//			numbers[j] = temp;
//			i++;
//		}
//		//��������ɨ��
//		while(i < j && key >= numbers.at(i) ) 
//			i++;
//		if(i < j) {
//			int temp = numbers.at(i);
//			numbers[i]  = numbers[j];
//			numbers[j] = temp;
//		}
//	}
//	numbers[i] = key;
//	return i;
//}


//����2��ʹ�ú����������k��С�����������������
vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
	int length = input.size();
	vector<int> result;
	if(length ==0 || k < 0 || k > length) return result;

	multiset<int,less<int>> leastNumbers;
	leastNumbers.clear();

	vector<int>::const_iterator iter = input.begin();
	for(; iter!= input.end(); iter++) {
		if(leastNumbers.size()  < k) {
			leastNumbers.insert(*iter);
		} else {
			multiset<int, less<int>>::iterator iterGreatest = leastNumbers.end();
			iterGreatest--;
			if(*iter < *iterGreatest) {
				leastNumbers.erase(iterGreatest);
				leastNumbers.insert(*iter);
			}
		}
	}

	for(multiset<int, greater<int>>::iterator iter = leastNumbers.begin(); iter!=leastNumbers.end(); iter++) {
		result.push_back(*iter);
	}
	return result;
}

int main()
{
	int input[] = {4,5,1,6,2,7,3,8};
	vector<int> inputVector(input, input+sizeof(input)/sizeof(int));
	vector<int> result = getLeastNumbers_Solution(inputVector,4);
	for(int i = 0; i<result.size(); i++) {
		printf("%d ", result[i]);
	}
	return 0;
}
