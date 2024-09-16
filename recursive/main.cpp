#include <iostream>
#include <ostream>

using namespace std;

int fatorial(int);

int main(int argc, char *argv[]) {
  int value;
  cout << "Digite um número pra calcular o fatorial dele: " << endl;
  cin >> value;
  int result = fatorial(value);
  cout << "O fatorial de " << value << " é: " << result << endl;
  return 0;
}

int fatorial(int value) {
  if (value == 1)
    return value;
  return value * fatorial(value - 1);
}
