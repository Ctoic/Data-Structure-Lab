#pragma once
#include <iostream>
using namespace std;

template<class T>
class Node
{
public:

	Node<T>* left;
	T key;
	int height1;
	Node<T>* right;

	//default constructor.
	Node<T>()
	{
		left = NULL;
		height1 = 1;
		right = NULL;
	}

	Node<T>(T d)
	{
		left = NULL;
		key = d;
		height1 = 0;
		right = NULL;
	}

};

template<class T>
class AVLTree
{
private:

public:
	Node<T>* root;
	AVLTree<T>()
	{
		this->root = NULL;

	}

	int height()
	{
		return maxDepth(root);
	}

	int maxDepth(Node<T>* node)
	{
		if (node == NULL)
		{
			return -1;
		}
		else
		{
			int lDepth = maxDepth(node->left);
			int rDepth = maxDepth(node->right);

			//comparing the depth of left and right sub tree.
			if (lDepth > rDepth)
			{
				return(lDepth + 1);
			}
			else
			{
				return(rDepth + 1);
			}
		}
	}

	//balance factor function.
	int BalanceFactor(Node<T>* n)
	{
		if (n->left && n->right)
		{
			return n->left->height1 - n->right->height1;
		}
		else if (n->left && n->right == NULL)
		{
			return n->left->height1;
		}
		else if (n->left == NULL && n->right)
		{
			return -n->right->height1;
		}
	}

	//LL rotation.
	Node<T>* LLrotation(Node<T>* n)
	{
		Node<T>* p;
		Node<T>* tp;
		p = n;
		tp = p->left;

		p->left = tp->right;
		tp->right = p;

		return tp;
	}

	//RR rotation
	Node<T>* RRrotation(Node<T>* n)
	{
		Node<T>* p;
		Node<T>* tp;
		p = n;
		tp = p->right;

		p->right = tp->left;
		tp->left = p;

		return tp;
	}

	//RL rotation.
	Node<T>* RLrotation(Node<T>* n)
	{
		Node<T>* p;
		Node<T>* tp;
		Node<T>* tp2;
		p = n;
		tp = p->right;
		tp2 = p->right->left;

		p->right = tp2->left;
		tp->left = tp2->right;
		tp2->left = p;
		tp2->right = tp;

		return tp2;
	}

	//LR rotation.
	Node<T>* LRrotation(Node<T>* n)
	{
		Node<T>* p;
		Node<T>* tp;
		Node<T>* tp2;
		p = n;
		tp = p->left;
		tp2 = p->left->right;

		p->left = tp2->right;
		tp->right = tp2->left;
		tp2->right = p;
		tp2->left = tp;

		return tp2;
	}

	Node<T>* insert1(Node<T>* r, Node<T>* temp)
	{

		if (r)
		{
			if (temp->key < r->key)
			{
				if (r->left)
				{
					r->left = insert1(r->left, temp);
				}
				else
				{
					r->left = temp;
				}
			}
			else
			{
				if (r->right)
				{
					r->right = insert1(r->right, temp);
				}
				else
				{
					r->right = temp;
				}
			}

			//r->height1 = maxDepth(r);

			if (BalanceFactor(r) == 2 && BalanceFactor(r->left) == 1)
			{
				r = LLrotation(r);
			}
			else if (BalanceFactor(r) == -2 && BalanceFactor(r->right) == -1)
			{
				r = RRrotation(r);
			}
			else if (BalanceFactor(r) == -2 && BalanceFactor(r->right) == 1)
			{
				r = RLrotation(r);
			}
			else if (BalanceFactor(r) == 2 && BalanceFactor(r->left) == -1)
			{
				r = LRrotation(r);
			}

		}
		else
		{
			root = temp;
		}

		return r;

	}

	//insert function.
	void insert(Node<T> r)
	{
		Node<T>* NewNode = new Node<T>(r.key);
		insert1(root, NewNode);
	}

	//destructor.
	~AVLTree()
	{
		delete root;
	}
};
