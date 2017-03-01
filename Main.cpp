// Main.cpp
/*
if number
  push to output queue
if function
  push to stack
  if parentheses
      until top of stack is "(" pop operators of stack onto queue

for operator o1 and o2
o2 is at the top of the stack
o1 is left associative and is less than or equal to o2
OR o1 is right asso and less than o2
  then pop o2 off operator stack and onto output queue
then push o1 onto operator stack

if parentheses
  "(" push onto stack
*/
#include <iostream>
#include "Node.h"

int main(){
  String infix;
  cout<<"Enter your expression"<<endl;
  cin.getline(infix);
  cin.ignore();
  String postfix = convert(infix);
  cout<<postfix<<endl;
}

String convert(string infix){
  String postfix = "";
  for(int i=0; i<infix.length(); i++){

  }
  return postfix;
}

bool isOperator (char c){
  if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')'){
    return true;
  }
}

bool isParentheses (char c){
  if(c == "(" || c == ")"){
    return true;
  }
}

int getWeight (char c){
  int weight = -1;
  if (c == "+" || c == "-") {
    weight = 1;
  }
  else if (c == "*" || c == "/"){
    weight = 2;
  }
  else if (c == "^"){
    weight = 3;
  }
  return weight;
}
