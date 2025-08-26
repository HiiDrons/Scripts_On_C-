#include <iostream>

using namespace std;

int main() {

 char oper;
 float a, b;
 cout << " Введите два числа: ";
 cin >> a >> b;
 cout << " Введите операцию: ";
 cin >> oper;

switch (oper) {

case '+':
 cout << a + b;
 endl;
 break;

case '-':
 cout << a - b;
 break;

case '*':
 cout << a * b;
 break;

case '/':
 cout << a / b;
 break;
}
 return 0;
}
