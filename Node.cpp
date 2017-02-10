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

Node* Node::push(Node*& newnode, char newval){

