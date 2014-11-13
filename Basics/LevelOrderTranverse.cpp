#include <iostream>
using namespace std;
struct TreeNode{
	TreeNode(int x):val(x),left(0),right(0),next(0) {}
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode * next;
};

void LevelOrderTranverse(TreeNode * root){
	TreeNode * startLevel = 0;
	TreeNode * front = root, *tail = root;
	while (front != 0){
		if (front->left != 0){
			tail->next = front->left;
			tail = tail->next;
			if (startLevel == 0) startLevel = tail;
		}
		if (front->right != 0){
			tail->next = front->right;
			tail = tail->next;
			if (startLevel == 0) startLevel = tail;
		}

		if (front->next == startLevel){
			front->next = 0;
			front = startLevel;
			startLevel = 0;
		}else{
			front = front->next;
		}
	}
}

int main(int argc, char const *argv[])
{
	TreeNode * a = new TreeNode(1);
	TreeNode * b = new TreeNode(2);
	TreeNode * c = new TreeNode(3);
	TreeNode * d = new TreeNode(4);
	TreeNode * e = new TreeNode(5);
	TreeNode * f = new TreeNode(6);
	a->left = b;
	a->right = c;
	c->left = d;
	c->right = e;
	b->left = f;
	LevelOrderTranverse(a);
	cout << a->next << endl;
	cout << b->next << endl;
	cout << c->next << endl;
	cout << d->next << endl;
	cout << e->next << endl;
	cout << f->next->val << endl;
	return 0;
}