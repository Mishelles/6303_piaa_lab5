#include "KMP.h"

std::vector<int> KMP::prefixFunction(const std::string& string) {
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

std::vector<int> KMP::patternSearch(const std::string& string, const std::string& pattern) {
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

int KMP::checkShift(const std::string& pattern, const std::string& string)
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
