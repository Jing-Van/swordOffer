//����ǰ����������й��������

#include "stdafx.h"
#include<vector>
using namespace std;



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
	//�ж���ֹ����
	if(pre.size() == 0 || in.size() ==0 ) return NULL;

	//������ڵ�
	int root = pre[0];
	TreeNode * node = new TreeNode(root);

	//�����������ı�������
	vector<int> preLeft,preRight,inLeft,inRight;
		//����ڵ������������е�λ��
	int rootIndex = 0;
	int leftLength = 0;

	for(int i=0; i<in.size();i++) {
		if(in.at(i) == root) {
			rootIndex = i;
			break;
		}
	}
	leftLength = rootIndex;
		//������������ǰ���������
	for(int i= 1; i <= leftLength; i++) {
		preLeft.push_back(pre[i]);
	}
	for(int i= leftLength+1; i<pre.size(); i++) {
		preRight.push_back(pre[i]);
	}

		//�����������������������
	for(int i = 0; i<leftLength; i++) {
		inLeft.push_back(in[i]);
	}
	for(int i = leftLength+1;i<in.size();i++) {
		inRight.push_back(in[i]);
	}

	node->left = reConstructBinaryTree(preLeft,inLeft);
	node->right = reConstructBinaryTree(preRight,inRight);
	return node;
}
