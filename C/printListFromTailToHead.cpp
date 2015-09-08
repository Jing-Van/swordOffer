//��β��ͷ��ӡ������
//�ܲ��ܸı䵥����Ļ���������Է�ת������
//���ܸı�Ļ���������������value��ջ������������ʱ�򣬽�ջ��Ԫ�س�ջ���ɡ�
//ͨ��ѭ����ջ��ʵ�֣�һ�㶼����ת���ɵݹ���ʵ��

#include "stdafx.h"
#include<vector>
#include<stack>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};


vector<int> printListFromTailToHead(struct ListNode* head) {
	vector<int> result;
	if(head == NULL) return result;

	stack<int> nodes;

	ListNode * pNode = head;
	while(pNode != NULL) {
		nodes.push(pNode->val);
		pNode = pNode->next;
	}

	while(!nodes.empty()) {
		result.push_back(nodes.top());
		nodes.pop();
	}

	return result;
}