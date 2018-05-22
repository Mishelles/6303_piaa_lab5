#include <iostream>
#include "KMP.h"

using namespace std;

int main() {

     string input;
     string pattern;
     cin >> pattern;
     cin >> input;

     auto kmp = new KMP();

     vector<int> result = kmp->patternSearch(input, pattern);

     cout << result[0];
     for (int i = 1; i < result.size(); i++) {
         cout << "," << result[i];
     }
     cout << endl;

     return 0;
}
