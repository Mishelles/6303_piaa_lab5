#include <iostream>
#include "KMP.h"

using namespace std;

int main() {
  string checkingString;
  string sourceString;
  cin >> checkingString;
  cin >> sourceString;

  auto kmp = new KMP();

  int result = kmp->checkShift(sourceString, checkingString);
  cout << result << endl;

  return 0;
}
