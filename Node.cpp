// Node.cpp
// Implements methods for Node class

#include "Node.h"

Node::Node(char newval){
	val = newval;
	next = NULL;
}

Node::~Node(){
	delete val;
	delete next;
}

Node* Node::push(Node*& oldstack, char newval){
	Node* newnode = new Node(newval);
	newnode->setNext(oldstack);
  return newnode;
}

char Node::pop(Node*& oldstack){
	oldstack->next = oldstack->next->next;
	return oldstack->val;
}

bool Node::empty(Node*& stack){

}
