// Node.h

class Node{
	private:
		Node* next;
		char val;
	public:
		Node(char);
		~Node();
		Node* push(Node*&, char);
		char pop(Node*&);
		bool empty(Node*&);
};
