#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

std::vector<int> prefixFunction(std::string string) {
    int len = string.length();
    std::vector<int> values(len);

    for (int i = 1; i < len; i++) {
        int j = values[i - 1];
        while (j > 0 && string[i] != string[j]) {
            j = values[j - 1];
        }
        if (string[i] == string[j]) {
            j++;
        }
        values[i] = j;
    }

    return values;
}

std::vector<int> kmp(std::string string, std::string pattern) {
    int slen = string.length();
    int plen = pattern.length();
    std::vector<int> answer;
    std::vector<int> prefix = prefixFunction(pattern + "#" + string);
    for (int i = 0; i < slen; i++) {
        if(prefix[plen + i + 1] == plen) {
            answer.push_back(i - plen + 1);
        }
    }

    if (answer.size() == 0) {
        answer.push_back(-1);
    }
    return answer;
}

int checkShiftKmp(const std::string checkingString, const std::string sourceString) {
   int checkingStringLength = checkingString.length();
   int sourceStringLength = sourceString.length();

   if (sourceStringLength != checkingStringLength) return -1;

   std::vector<int> prefix = prefixFunction(sourceString);

   int indexCheckingString = 0;
   int indexSourceString = 0;

   while (indexCheckingString < (2 * sourceStringLength - 1)) {
       if (checkingString[(indexCheckingString++ % checkingStringLength)]
               == sourceString[indexSourceString]) {
           ++indexSourceString;

           if (indexSourceString == sourceStringLength) {
               return indexSourceString - indexSourceString;
           }
       } else if (indexSourceString) {
           --indexCheckingString;
           indexSourceString = prefix[indexSourceString - 1];
       }

   }

   return -1;
}

long int kmpShiftAlgorithm (std::string pattern, std::string string)
{
    int plen = pattern.length();
    int slen = string.length();

    if (slen != plen) return -1;

    std::vector<int> prefix = prefixFunction(pattern);

    int indexPattern = 0;
    int indexString = 0;

    while (indexString < (2 * slen - 1))
        if (string[(indexString++ % slen)] == pattern[indexPattern])
        {
            ++indexPattern;
            if (indexPattern == plen)
                return (indexString - plen);
        }
        else if (indexPattern != 0)
        {
            --indexString;
            indexPattern = prefix[indexPattern - 1];
        }

    return -1;
}

int main() {

//    std::string input;
//    std::string pattern;
//    std::cin >> pattern;
//    std::cin >> input;
//    std::vector<int> result = kmp(input, pattern);

//    std::cout << result[0];
//    for (int i = 1; i < result.size(); i++) {
//        std::cout << "," << result[i];
//    }
//    std::cout << std::endl;

    std::string checkingString;
    std::string sourceString;
    std::cin >> checkingString;
    std::cin >> sourceString;

    //int result = checkShiftKmp(sourceString, sourceString);
    int result = kmpShiftAlgorithm(checkingString, sourceString);
    std::cout << result << std::endl;


    return 0;
}
