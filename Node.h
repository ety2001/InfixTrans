// Node.h
// Node class for creating an operator stack
class Node{
	private:
		Node* next;
		char val;
	public:
		Node(char);
		Node* getNext();
		char getVal();
		void setNext(Node*);
};
