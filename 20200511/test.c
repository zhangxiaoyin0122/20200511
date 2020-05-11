#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef char DType;

typedef struct BinTreeNode {
	struct BinTreeNode* _left;
	struct BinTreeNode* _right;
	DType _value;
}BTNode;

//ͨ��ǰ���������������
BTNode* BinaryTreeCreat(char* str, int* idx) {
	if (str[*idx] != '#') {
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_value = str[*idx];
		++(*idx);
		root->_left = BinaryTreeCreat(str, idx);
		++(*idx);
		root->_right = BinaryTreeCreat(str, idx);
		return root;
	}
	else
		return NULL;
}

//������������
void BinaryTreeDestory(BTNode** root) {
	BTNode* cur = *root;
	while (cur) {
		BinaryTreeDestory(&cur->_left);
		BinaryTreeDestory(&cur->_right);
		free(cur);
		*root = NULL;
	}
}

//�������Ľڵ����
int BinaryTreeSize(BTNode* root) {
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
//�ۼӼ�������������ڵ����
int BinaryTreeSize2(BTNode* root,int* count) {
	if (root) {
		count++;
		BinaryTreeSize2(root->_left, count);
		BinaryTreeSize2(root->_right,count);
	}
	return 0;
}

//������Ҷ�ӽڵ�ĸ���
int BinaryTreeLeafSize(BTNode* root) {
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

//��������K��ڵ�ĸ���
int BinaryTreeLevelKSize(BTNode* root,int k) {
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
//����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, DType x) {
	if (root == NULL)
		return NULL;
	if (root->_value == x)
		return root;
	BTNode* ret = BinaryTreeFind(root->_left, x);
	if (ret)
		return ret;
	return BinaryTreeFind(root->_right, x);
}
//������ǰ��ݹ����
void BinaryTreePrevOrder(BTNode* root) {
	if (root) {
		printf("%c", root->_value);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}
void BinaryTreeInOrder(BTNode* root) {
	if (root) {
		BinaryTreePrevOrder(root->_left);
		printf("%c", root->_value);		
		BinaryTreePrevOrder(root->_right);
	}
}
void BinaryTreePostOrder(BTNode* root) {
	if (root) {
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
		printf("%c ", root->_value);
	}
}

int main() {
	char str[] = "ABD##E#H##CF##G##";
	int idx = 0;
	BTNode* root=BinaryTreeCreat(str, &idx);
	BinaryTreePrevOrder(root);
	system("pause");
	return 0;
}