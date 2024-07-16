#include <string>
#include <vector>

using namespace std;
char operand[3] = { '*', '+', '-' };

string calc(const string exp, int op) {
	string ret = "";
	long long a = 0, b = 0, val;
	bool isCalc = false, isMinus = false;
	for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '-' && (i == 0 || exp[i - 1] == '*' || exp[i - 1] == '+' || exp[i - 1] == '-')) {
	        isMinus = true;
	        i++;
        }
		if (exp[i] == operand[op]) {
			if (!isCalc) {
				isCalc = true;
                if(isMinus) {
                    a *= -1;
                    isMinus = false;
                }
			}
			else {
                if (isMinus) {
			    	b *= -1;
				    isMinus = false;
                }
				if (op == 0) val = a * b;
				else if (op == 1) val = a + b;
				else val = a - b;
				a = val;
				b = 0;
			}
		}
		else if (exp[i] == '*' || exp[i] == '+' || exp[i] == '-') {
			if (!isCalc) {
                if (isMinus) {
				    a *= -1;
				    isMinus = false;
                }
				ret += to_string(a);
				ret += exp[i];
			}
			else {
                if (isMinus) {
				    b *= -1;
				    isMinus = false;
                }
				if (op == 0) val = a * b;
				else if (op == 1) val = a + b;
				else val = a - b;
				ret += to_string(val);
				ret += exp[i];
				isCalc = false;
			}
			a = 0;
			b = 0;
			
		}
		else {
			if (!isCalc) {
				a *= 10;
				a += exp[i] - '0';
			}
			else {
				b *= 10;
				b += exp[i] - '0';
			}
		}
	}
	if (isCalc) {
		if (isMinus) b *= -1;
		if (op == 0) val = a * b;
		else if (op == 1) val = a + b;
		else val = a - b;
		ret += to_string(val);
	}
	else {
		if (isMinus) a *= -1;
		ret += to_string(a);
	}
	return ret;
}

long long solution(string expression) {
    long long answer = 0, res = 0;
    string s1, s;

    for (int i = 0; i < 3; i++) {
	    s1 = calc(expression, i);
	    for (int j = 0; j < 3; j++) {
		    if (i == j) continue;
		    s = calc(s1, j);
		    s = calc(s, 3 - i - j);
		    res = stoll(s);
		    if (res < 0) res *= -1;
		    answer = max(answer, res);
    	}
    }
    return answer;
}