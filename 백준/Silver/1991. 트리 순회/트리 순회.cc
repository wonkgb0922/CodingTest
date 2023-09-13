#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

pair<char,char> t[26];
int n;

void preorder(char node) {
	printf("%c", node);
	if (t[node - 'A'].first != '.') preorder(t[node - 'A'].first);
	if (t[node - 'A'].second != '.') preorder(t[node - 'A'].second);
}

void inorder(char node) {
	if (t[node - 'A'].first != '.') inorder(t[node - 'A'].first);
	printf("%c", node);
	if (t[node - 'A'].second != '.') inorder(t[node - 'A'].second);
}

void postorder(char node) {
	if (t[node - 'A'].first != '.') postorder(t[node - 'A'].first);
	if (t[node - 'A'].second != '.') postorder(t[node - 'A'].second);
	printf("%c", node);
}

int main() {
	char in, in2, in3;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in >> in2 >> in3;
		t[in - 'A'].first = in2;
		t[in - 'A'].second = in3;
	}
	preorder('A');
	printf("\n");
	inorder('A');
	printf("\n");
	postorder('A');
	
	return 0;
}