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
  char infix [100];
  cout<<"Enter your expression"<<endl;
  cin.getline(infix);
  cin.ignore();

  char postfix [] = convert(infix);
  cout<<postfix<<endl;
}

String convert(char[] infix){
  char postfix [100]= {0};
  for(int i=0; i<???; i++){
/*
if operand, then print
if left, push to stack
if right, discard and pop/print stack until left and discard left
if operator and stack is empty or (. push to stack
if operator has higher as op on top, push to stack
if operator and lower or equal pre as op on top, pop stack until not true, push incoming operator
pop and print all operators

*/
  }
  return postfix;
}

bool isOperand (char c){
  if(isdigit(c) == true){
    return true;
  }
  else{
    return false;
  }
}

bool isOperator (char c){
  if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')'){
    return true;
  }
}

bool isPar (char c){
  if(c == "(" || c == ")"){
    return true;
  }
}

bool isLeft (char c){
  if(c == "("){
    return true;
  }
  else{
    return false;
  }
}

bool isRight (char c){
  if(c == ")"){
    return true;
  }
  else{
    return false;
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

bool higherPrecedence(char a, char b){
//a is stack
//b is current
//keep popping the stack until higher
  int aWeight = getWeight(a);
  int bWeight = getWeight(b);
  if (aWeight > b weight){
    return true;
  }
  else{
    return false;
  }
}
