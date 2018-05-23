#ifndef KMP_H
#define KMP_H

#include <string>
#include <vector>

class KMP {

public:

  std::vector<int> patternSearch(const std::string&, const std::string&);

  int checkShift(const std::string&, const std::string&);

  std::vector<int> prefixFunction(const std::string&);

};

#endif
