#include "Tokenizer.h"
#include <sstream>
#include <algorithm>

namespace parser {
    parser::Tokenizer::Tokenizer(const std::set<std::string>& ignoreList, const std::map<std::string, Token>& tokenList) :
        m_ignoreList(ignoreList),
        m_tokenList(tokenList)
    {
    }

    std::vector<Token> parser::Tokenizer::parse(const std::string& inputString) const
    {
        std::vector<Token> result;
        std::istringstream iss(inputString);
        std::string word;
        while (std::getline(iss, word, ' ')) {
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);

            // handle trailling characters
            std::size_t notTraillingPos = word.find_last_not_of("?,.!;\n\t");
            if (notTraillingPos == std::string::npos) continue;
            word.erase(notTraillingPos + 1);

            if (m_ignoreList.find(word) != m_ignoreList.end()) {
                continue;
            }

            auto it = m_tokenList.find(word);
            result.push_back(it == m_tokenList.end() ? Token::Empty : it->second);
        }

        return result;
    }

}
