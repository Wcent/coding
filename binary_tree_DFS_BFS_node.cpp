// binary tree node class ~ Node.h
class Node
{
private:
	int m_nodeValue;
	Node *m_leftSubNode;
	Node *m_rightSubNode;
	
public:
	Node();
	Node(int nodeValue);
	Node(const Node &node);
	virtual ~Node();
	Node & operator =(int nodeValue);
	Node & operator =(const Node &node);
	void setNodeValue(int value);
	int getNodeValue();
	void setLeftSubNode(const Node &node);
	void setRightSubNode(const Node &node);
	Node & getLeftSubNode() const;
	Node & getRightSubNode() const;
	void clear();
};

// binary tree node class ~ cpp
#include "Node.h"
#include <iostream>

using namespace std;

Node::Node()
{
	m_nodeValue = 0;
	m_leftSubNode = NULL;
	m_rightSubNode = NULL;
}

Node::Node(int nodeValue)
{
	m_nodeValue = nodeValue;
	m_leftSubNode = NULL;
	m_rightSubNode = NULL;
}

Node::Node(const Node &node)
{
	m_nodeValue = node.getNodeValue();
	m_leftSubNode = &(node.getLeftSubNode());
	m_rightSubNode = &(node.getRightSubNode());
}

Node::~Node()
{
	clear();
}

Node & Node::operator =(int nodeValue)
{
	m_nodeValue = nodeValue;
	m_leftSubNode = NULL;
	m_rightSubNode = NULL;
	return (*this);
}

Node & Node::operator =(const Node &node)
{
	m_nodeValue = node.getNodeValue();
	m_leftSubNode = node.getLeftSubNode();
	m_rightSubNode = node.getRightSubNode();
	return (*this);
}

void Node::setNodeValue(int nodeValue)
{
	m_nodeValue = nodeValue;
}

int Node::getNodeValue()
{
	return m_nodeValue;
}

void Node::setLeftSubNode(const Node &node)
{
	m_leftSubNode = &node;
}

void Node::setRightSubNode(const Node &node)
{
	m_rightSubNode = &node;
}

Node & Node::getLeftSubNode()
{
	return (*m_leftSubNode);
}

Node & Node::getRightSubNode()
{
	return (*m_rightSubNode);
}

void Node::clear()
{
	m_nodeValue = 0;
	m_leftSubNode = NULL;
	m_rightSubNode = NULL;
}

// binary tree class ~ BinTree.h
class BinTree
{
private:
	Node *bTree;
	
public:
	BinTree();
//	BinTree(const int *nodeValueArray);
	BinTree(const Node *nodeArray, int len);
	~BinTree();
//	bool insertNode(Node &nodeKey, bool flag, int nodeValue);
	bool insertNode(const Node &keyNode, bool flag, const Node &newNode);
//	bool deleteNode(int nodeValue);
	bool deleteNode(const Node &keyNode);
	Node * getNodeParent(const Node &keyNode) const;
//	bool nodeIsExist(int nodeValue);
	Node * nodeIsExist(const Node &keyNode) const;
//	bool DFS_node(int nodeValue);
	Node * DFS_node(const Node &keyNode) const;
//	bool BFS_node(int nodeValue);
	Node * BFS_node(const Node &keyNode) const;
	void clear();
};

BinTree::BinTree()
{
	bTree = NULL;
}

BinTree::BinTree(const Node *nodeArray, int len)
{
	int root;
	int left, right;
	Node *node;
	
	for (int i=len-1; i>0; i--)
	{
		node = new Node(nodeArray[i]);
		root = (i - 1) / 2;
		left = 2 * root + 1;
		right = 2 * root + 2
		if (i == left)
			nodeArray[root].setLeftSubNode(*node);
		else if (i == right)
			nodeArray[root].setRightSubNode(*node);
	}
	node = new Node(nodeArray[0]);
	bTree = node;
}

bool Node::insertNode(const Node &keyNode, bool flag, const Node &newNode)
{
}

bool Node::deleteNode(const Node &keyNode)
{
	Node *node = nodeIsExist(keyNode);
	if (node != NULL)
	{
		Node *parent = getNodeParent(bTree, keyNode);
		if (parent != NULL)
		{
			parent->setLeftSubNode(node->getLeftSubNode());
			parent->setRightSubNode(node->getRightSubNode());
			delete [] node;
		}
		else
		{
			delete [] node;
			bTree = NULL;
		}
		return true;
	}
	else
		return false;
}

Node * getNodeParent(const Node *root, const Node &keyNode) const
{
	Node *left = root->getLeftSubNode();
	Node *right = root->getRightSubNode();
	
	if (root == keyNode)
		return NULL;
	else if (left == keyNode || right == keyNode)
		return root;
	if (left != NULL)
	{
		root = getNodeParent(left, keyNode);
		if (root != NULL)
			return root;
	}
	if (right != NULL)
	{
		root = getNodeParent(right, keyNode);
		if (root != NULL)
			return root;
	}
	return NULL;	
}

Node * nodeIsExist(const Node &keyNode) const
{
}

// DFS - binary tree
Node * DFS_node(const Node &keyNode) const
{
}

// BFS - binary tree
Node * BFS_node(const Node &keyNode) const
{
}

BinTree::~BinTree()
{
	clear();
}

void BinTree::clear()
{
	if (bTree->getLeftSubNode() != NULL)
		bTree->getLeftSubNode().clear();
	if (bTree->getRightSubNode() != NULL)
		bTree->getRightSubNode().clear();
	delete [] bTree;
	bTree = NULL;
}


