#include<iostream>

using namespace std;

struct Branch {
public:
	int ind;
	Branch* left = NULL;
	Branch* right = NULL;

	Branch(int i) {
		ind = i;
	}
};

struct BinTree {

private:
	void burn(Branch* bran) {
		if (bran) {
			burn(bran->left);
			burn(bran->right);
			delete bran;
		}
	}

	void get_children(Branch* parent, Branch* grand_bran, Branch* little_bran) {
		if (parent == NULL)
			first = little_bran;
		else if (parent->left == grand_bran)
			parent->left = little_bran;
		else if
			(parent->right == grand_bran) parent->right = little_bran;
	}

public:
	Branch* first;

	BinTree() {
		first = NULL;
	}

	~BinTree() {
		burn(first);
	}

	void Add(int i) {
		Branch** now = &first;
		while (*now)
		{
			Branch& little_bran = **now;

			if (i < little_bran.ind)
				now = &little_bran.left;
			else if (i > little_bran.ind)
				now = &little_bran.right;
			else
				return;
		}

		*now = new Branch(i);
	}

	Branch* search(int i) {
		Branch* parent = first;

		while (parent != NULL)
		{
			if (parent->ind == i)
			{
				return parent;
			}
			else if (parent->ind > i)
			{
				parent = parent->left;
			}
			else if (parent->ind < i)
			{
				parent = parent->right;
			}
		}

		return NULL;

	}

	void remove(int i) {
		Branch* parent = NULL;
		Branch* bran = first;

		while (true)
		{
			if (bran == NULL) return;
			if (i < bran->ind)
			{
				parent = bran;
				bran = bran->left;
			}
			else if (i > bran->ind)
			{
				parent = bran;
				bran = bran->right;
			}
			else break;
		}

		Branch* result = NULL;

		if (bran->left == NULL) result = bran->right;
		else if (bran->right == NULL) result = bran->left;
		else {
			Branch* min_bran_parent = bran;
			Branch* min_bran = bran->right;

			while (min_bran->left != NULL)
			{
				min_bran_parent = min_bran;
				min_bran = min_bran->left;
			}

			result = bran;
			bran->ind = min_bran->ind;
			get_children(min_bran_parent, min_bran, min_bran->right);
		}

		get_children(parent, bran, result);
	}

};

int main() {}