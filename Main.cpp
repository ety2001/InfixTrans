// Main.cpp
// Takes an infix expression and converts it to postfix using the Shunting Yard Algorithm

#include <iostream>
#include "Node.h"

using namespace std;

// pushes an operator onto stack
void push(Node*& stack, char newval){
	Node* newnode = new Node(newval);
	newnode->setNext(stack);
	stack = newnode;
}
// gets value and removes operator from top of stack
char pop(Node*& stack){
	char op = stack->getVal();
	stack = stack->getNext();
	return op;
}
// gets value from top of stack
char peak(Node*& stack){
  return stack->getVal();
}
// checks if stack is empty
bool empty(Node*& stack){
	return (stack==NULL);
}
// checks if token is operator
bool isOperator (char c){
  if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')'){
    return true;
  }
}
// checks if left parenthesis
bool isLeft (char c){
  if(c == '('){
    return true;
  }
  else{
    return false;
  }
}
// checks if right parenthesis
bool isRight (char c){
  if(c == ')'){
    return true;
  }
  else{
    return false;
  }
}
// gets weight of operator (for precedence)
int getWeight (char c){
  int weight = -1;
  if (c == '+' || c == '-') {
    weight = 1;
  }
  else if (c == '*' || c == '/'){
    weight = 2;
  }
  else if (c == '^'){
    weight = 3;
  }
  return weight;
}
// checks if two operators have lower/equal/higher precednce
int precedence(char a, char b){
// -1: a<b
// 0: a=b
// 1: a>b
  int aWeight = getWeight(a);
  int bWeight = getWeight(b);
  if (aWeight < bWeight){
    return -1;
  }
  else if (aWeight == bWeight){
    return 0;
  }
  else {
    return 1;
  }
}
// checks if operator is right associative
bool isRightAsso(char c){
  return(c == '^');
}

void convert(char* infix){
  Node* opstack = NULL;
  char top[10];
  int numchars = 0;
  for(int i = 0; infix[i]!='\0'; i++){
    // if operand, then print
    if(isdigit(infix[i])){
      top[numchars] = infix[i];
      numchars++;
    }
    // if space, end of token
    else if(infix[i] == ' '){
      // print if operand
      if(numchars>0){
        top[numchars] = '\0';
        cout<<top<<" ";
        numchars = 0;
      }
    }
    // if left, push to stack
    else if(isLeft(infix[i])){
      push(opstack, infix[i]);
    }
    // if right, discard and pop/print stack until left and discard left
    else if(isRight(infix[i])){
      while(peak(opstack)!='('){
        cout<<pop(opstack)<<" ";
      }
      pop(opstack);
    }
    // if operator
    else if(isOperator(infix[i])){
      // if stack is empty or (, push to stack
      if(empty(opstack) || peak(opstack)=='('){
        push(opstack, infix[i]);
      }
      else{
        // pop stack until if operator has higher precedence or rightAsso, then push to stack
        while(!empty(opstack) &&
              (precedence(infix[i], peak(opstack)) < 0 ||
               precedence(infix[i], peak(opstack)) == 0 && !isRightAsso(infix[i])
              )){
          cout<<pop(opstack)<<" ";
        }
        push(opstack, infix[i]);
      }
    }
  }
  if(numchars>0){
    top[numchars] = '\0';
    cout<<top<<" ";
  }
  // pop and print remaining operators on stack
  while(!empty(opstack)){
    cout<<pop(opstack)<<" ";
  }
}

int main(){
  char infix [200];
  cout<<"Enter your expression"<<endl;
  cin.getline(infix, 200);
  convert(infix);
}
