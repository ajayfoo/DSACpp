#include <cassert>
#include <string>
#include"my_stack.h"
#include <iostream>

namespace expr {
	bool is_operand(char tk) {
		return (tk >= '0' && tk <= '9') || (tk >= 'a' && tk <= 'z') || (tk >= 'A' && tk <= 'Z');
	}

	int get_prec(char op) {
		switch (op) {
			case '^':
				return 5;
			case '*':
			case '/':
				return 4;
			case '+':
			case '-':
				return 3;
			default:
				assert(false && "Invalid operator passed");
				abort();
		}
	}

	bool is_higher_prec(char op1, char op2) {
		return get_prec(op1) >= get_prec(op2);
	}

	std::string infix_to_postfix(const std::string& expr) {
		Stack<char, 10> stk;
		std::string res="";
		std::cout<<"Size of expr: "<<expr.size()<<'\n';
		for (int i = 0; i < expr.size(); ++i) {
			if (is_operand(expr[i])) {
				res.push_back(expr[i]);
				continue;
			}
			while (!stk.is_empty() && is_higher_prec(stk.peek(), expr[i])) {
				res.push_back(stk.peek());
				stk.pop();
			}
			stk.push(expr[i]);
		}
		while(!stk.is_empty()){
			res.push_back(stk.peek());
			stk.pop();
		}
		return res;
	}
}


