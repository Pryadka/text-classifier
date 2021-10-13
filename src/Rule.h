#ifndef _RULE_
#define _RULE_

#include <string_view>
#include <string>
#include <vector>

#include "Tokenizer.h"

namespace analizer {

     class Rule
     {
     public:
         Rule(const std::string_view& ruleName);
         Rule() = delete;
         ~Rule() = default;
         Rule(const Rule&) = default;

         Rule& addPattern(const std::vector<parser::Token>& pattern);
         bool operator==(const std::vector<parser::Token>& pattern) const;
         const std::string& getName() const { return m_name; }
     
     private:
         const std::string m_name;
         std::vector < std::vector<parser::Token> > m_patternes;
     };

} // namespace analizer


#endif // _RULE_