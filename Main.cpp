// Main.cpp

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

bool isOperator (char character){
  if(C=='+'||C=='-'||C=='*'||C=='/'||C=='^'||C=='('||C==')'){
    return true;
  }
}
