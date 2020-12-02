// =================================================================
//
// File: splay.h
// Author: Pedro Perez
// Description: This file contains the implementation of TDA
//							Splay Tree.
// Modified from:
// 	https://github.com/PetarV-/Algorithms/blob/master/Data%20Structures/Splay%20Tree.cpp
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include "registro.h"

class Node {
private:
	Registro registro;
	Node *left, *right, *parent;
	Node(Registro r);
	void preOrder(stringstream&) const;
	friend class SplayTree;
};

Node::Node(Registro r) : registro(r), left(NULL), right(NULL), parent(NULL) {}

void Node::preOrder(stringstream &aux) const {

	aux << registro.ip << endl;
	if (left != NULL) {
		left->preOrder(aux);
	}
	if (right != NULL) {
		right->preOrder(aux);
	}
}

class SplayTree {
private:
	Node *root;

	void zig(Node*);
	void zigZig(Node*);
	void zigZag(Node*);
	void splay(Node*);

	Node* subtreeMax(Node *);
	Node* subtreeMin(Node *);

public:
	SplayTree();
	string byLevel() const;
	bool empty() const;
	Node* find(Registro r);
	void  add(Registro r);
	void  remove(Registro r);
	string preOrder() const;

};

SplayTree::SplayTree(): root(NULL) {}

bool SplayTree::empty() const {
	return (root == NULL);
}

void SplayTree::zig(Node *x) {
	Node *p = x->parent;

	if (p->left == x) {
		Node *A = x->left;
		Node *B = x->right;
		Node *C = p->right;

		x->parent = NULL;
		x->right = p;

		p->parent = x;
		p->left = B;

		if (B != NULL) {
			B->parent = p;
		}
	} else {
		Node *A = p -> left;
    Node *B = x -> left;
    Node *C = x -> right;

    x->parent = NULL;
    x->left = p;

    p->parent = x;
    p->right = B;

    if (B != NULL) {
			B->parent = p;
		}
	}
}

void SplayTree::zigZig(Node *x) {
    Node *p = x->parent;
    Node *g = p->parent;

    if (p->left == x) {
			Node *A = x->left;
			Node *B = x->right;
			Node *C = p->right;
			Node *D = g->right;

			x->parent = g->parent;
			x->right = p;

			p->parent = x;
			p->left = B;
			p->right = g;

			g->parent = p;
			g->left = C;

			if (x->parent != NULL) {
				if (x->parent->left == g) {
					x->parent->left = x;
				} else {
					x->parent->right = x;
				}
			}

			if (B != NULL) {
				B->parent = p;
			}

			if (C != NULL) {
				C->parent = g;
			}
    } else {
			Node *A = g->left;
			Node *B = p->left;
			Node *C = x->left;
			Node *D = x->right;

			x->parent = g->parent;
			x->left = p;

			p->parent = x;
			p->left = g;
			p->right = C;

			g->parent = p;
			g->right = B;

			if (x->parent != NULL) {
				if (x->parent->left == g) {
					x->parent->left = x;
				} else {
					x->parent->right = x;
				}
			}

			if (B != NULL) {
				B->parent = g;
			}

			if (C != NULL) {
				C->parent = p;
			}
    }
}

void SplayTree::zigZag(Node *x) {
	Node *p = x->parent;
	Node *g = p->parent;

	if (p->right == x) {
		Node *A = p->left;
		Node *B = x->left;
		Node *C = x->right;
		Node *D = g->right;

		x->parent = g->parent;
		x->left = p;
		x->right = g;

		p->parent = x;
		p->right = B;

		g->parent = x;
		g->left = C;

		if (x->parent != NULL) {
			if (x->parent->left == g) {
				x->parent->left = x;
			}
			else {
				x->parent->right = x;
			}
		}

		if (B != NULL) {
			B->parent = p;
		}

		if (C != NULL) {
			C->parent = g;
		}
	}
	else {
		Node *A = g->left;
		Node *B = x->left;
		Node *C = x->right;
		Node *D = p->right;

		x->parent = g->parent;
		x->left = g;
		x->right = p;

		p->parent = x;
		p->left = C;

		g->parent = x;
		g->right = B;

		if (x->parent != NULL) {
			if (x->parent->left == g) {
				x->parent->left = x;
			} else {
				x->parent->right = x;
			}
		}

		if (B != NULL) {
			B->parent = g;
		}

		if (C != NULL) {
			C->parent = p;
		}
	}
}

void SplayTree::splay(Node *x) {
	while (x->parent != NULL) {
		Node *p = x->parent;
		Node *g = p->parent;
		if (g == NULL) {
			zig(x);
		} else if (g->left == p && p->left == x) {
			zigZig(x);
		}	else if (g->right == p && p->right == x) {
			zigZig(x);
		} else {
			zigZag(x);
		}
	}
	this -> root = x;
}

Node* SplayTree::find(Registro r) {
	Node *ret = NULL;
	Node *curr = this -> root;
	Node *prev = NULL;

	while (curr != NULL) {
		prev = curr;
		if (r.get_ip() < curr->registro.get_ip()) {
			curr = curr -> left;
		} else if (r.get_ip() > curr->registro.get_ip()) {
			curr = curr -> right;
		} else {
			ret = curr;
			break;
		}
	}

	if (ret != NULL) {
		splay(ret);
	} else if (prev != NULL) {
		splay(prev);
	}
	return ret;
}

void SplayTree::add(Registro r) {
	if (root == NULL) {
		root = new Node(r);
		return;
	}

	Node *curr = this->root;
	while (curr != NULL) {
		if (r.get_ip() < curr->registro.get_ip()) {
			if (curr->left == NULL) {
				Node *newNode = new Node(r);
				curr->left = newNode;
				newNode->parent = curr;
				splay(newNode);
				return;
			} else {
				curr = curr->left;
			}
		} else if (r.get_ip()  > curr->registro.get_ip()) {
			if (curr->right == NULL) {
				Node *newNode = new Node(r);
				curr->right = newNode;
				newNode->parent = curr;
				splay(newNode);
				return;
			} else {
				curr = curr->right;
			}
		} else {
			splay(curr);
			return;
		}
	}
}

string SplayTree::preOrder() const {
	stringstream aux;

	aux << "[";
	if (!empty()) {
		root->preOrder(aux);
	}
	aux << "]";
	return aux.str();
}

string SplayTree::byLevel() const {

	queue<Node*> queue;
	Node* nodeAux;
	stringstream aux;
aux<<"[\n";

	if(root == NULL){
		aux<<"]";
		return aux.str();
	}

	queue.push(root);

	while(queue.size()<6){

		nodeAux = queue.front();
		queue.pop();
		aux << nodeAux->registro.ip << endl;

		if(nodeAux->left != NULL){
			queue.push(nodeAux->left);
		}
		if(nodeAux->right != NULL){
			queue.push(nodeAux->right);
		}
	}

	aux<<"]";
	return aux.str();
}

#endif /* SPLAYTREE_H */
