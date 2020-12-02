// =================================================================
// File: activity.h
// Author: José Miguel Luna Vega - A01706424
// Date: 11/10/2020
// =================================================================
#ifndef ACTIVITY23_H
#define ACTIVITY23_H

#include <iostream>
#include <string>
#include <cctype>
#include <queue>
#include <stack>

using namespace std;

// =================================================================
// Auxiliar function. Receives a string and separates it into its
// basic elements, placing them in a queue of strings. For example,
// if the input is the string "123 34 7 + * -", then it returns a
// queue with the following elements: "123", "34", "7", "+", "*",
// and "-" .
//
// @param expr, a string with an arithmetic expression in infix
//              notation.
// @return a string with an arithmetic expression in infix notation.
// =================================================================
queue<string> tokenize(string str) {
	int i = 0;
	int length = str.size();
	string aux;
	queue<string> result;

	while (i < length) {
		if (isdigit(str[i])) {
			aux.clear();
			do {
				aux += str[i];
				i++;
			} while(isdigit(str[i]));
			result.push(aux);
		} else if (isspace(str[i])) {
			i++;
		} else {
			aux.clear();
			aux += str[i];
			result.push(aux);
			i++;
		}
	}
	return result;
}

// =================================================================
// Auxiliar function. Determine if the element at the top of the
// stack has higher precedence than the op operator.
//
// @param stackTop, the operator at the top of the stack.
// @param op, the operator being evaluated
// @return true if the operator at the top of the stack has higher
//         precedence than op, false otherwise.
// =================================================================
bool hasHigherPrecedence(const string &stackTop, const string &op) {
	return !((stackTop == string("+") || stackTop == string("-")) &&
			 (op == string("*")       || op == string("/")));
}

// =================================================================
// Returns true if the expr string that it receives as a parameter
// contains an expression where all its grouping symbols
// (parentheses (), square brackets [] and braces {}) are correctly
// nested and balanced. Returns false otherwise. Any character in
// expr other than parentheses, brackets, or braces should be
// ignored.
//
// @param expr, a string where all characters are grouping symbols.
// @return true if the string are correctly nested and balanced,
//         false otherwise
// =================================================================
bool balancedBrackets(const string &expr) {
	stack<char> pila;
	//Recorremos todo el string, por lo tanto, O(n)
	for(int i = 0; i<expr.size(); i++){
		//Si es un bracket de apertura, insertalo en el tope
		if(expr[i] == '(' || expr[i] == '{' || expr[i] == '['){
			pila.push(expr[i]);
		}
		//Si es de cierre, verifica que haga match, de lo contrario no esta balanceada
		else if(expr[i] == ')'){
			if(pila.empty()!=true && pila.top()=='('){
				pila.pop();
			}
			else{
				return false;
			}
		}
		else if(expr[i] == '}'){
			if(pila.empty()!=true && pila.top()=='{'){
				pila.pop();
			}
			else{
				return false;
			}
		}
		else if(expr[i] == ']'){
			if(pila.empty()!=true && pila.top()=='['){
				pila.pop();
			}
			else{
				return false;
			}
		}
	}
	//Si no hay un bracket sin pareja es que esta balanceado
	return pila.empty();
}

// =================================================================
// Receives as a parameter the string expr that contains an
// arithmetic expression in infix notation. Returns a string with
// the equivalent expression in postfix notation. It does not perform
// any kind of validation against the input expression.
//
// @param expr, a string with an arithmetic expression in infix
//              notation.
// @return a string with the equivalent expression in postfix
//         notation
// =================================================================
string convertInfixToPostfix(const string &expr) {

  //colas, pilas y strings a utilizar
	queue<string> input;
	queue<string> result;
	stack<string> stack;
  string token;
	string res = "";
	input = tokenize(expr);

	//mientras que la cola de entrada tenga elementos
	//como depende del numero de caracteres, hablamos de O(n)
	while (!input.empty()) {
		//guarda en un token el elemento de enfrente
    token = input.front();

		//dependiendo de que sea haz una indicacion
		if(isdigit(token[0])){
			result.push(token);
		}
		else if (token == "("){
			stack.push(token);
		}
		else if (token == "+" || token == "-" || token == "*" || token == "/" ){
			while(stack.empty()!=true && stack.top()!="(") {
				if(hasHigherPrecedence(stack.top(),token)) {
					result.push(stack.top());
					stack.pop();
				}
				else{
					break;
				}
			}
			stack.push(token);
		}
		else if(token == ")"){
			while(stack.empty()!=true && stack.top()!="("){
				result.push(stack.top());
				stack.pop();
			}
			if(stack.empty()!=true && stack.top()=="("){
				stack.pop();
			}
		}
    input.pop();
  }
  //si aun no se vacia la pila, lleva todos los operadores al resultado
	while(!stack.empty()){
			result.push(stack.top());
			stack.pop();
		}
  //guarda en un string el resultado separado por espacios
	int length = result.size();
	for(int i = 0; i<length-1; i++){
 		res = res + result.front() + " ";
 		result.pop();
	}
  res = res + result.front();
  result.pop();

	//haz el return
	return res;
}

#endif /* ACTIVITY23_H */
