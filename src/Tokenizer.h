#ifndef _TOKENIZER_
#define _TOKENIZER_

#include <string>
#include <set>
#include <map>
#include <vector>

namespace parser
{
    enum class Token : uint16_t {
        Empty = 0,
        What,
        is,
        Weather,
        Like,
        Time,
        Tell,
        Adjective,
        Pronoun,
        Fact,
        In,
    };

    class Tokenizer
    {
    public:
        Tokenizer(const std::set<std::string> & ignoreList, const std::map<std::string, Token> & tokenList);
        Tokenizer() = delete;
        ~Tokenizer() = default;

        std::vector<Token> parse(const std::string& inputString) const;

    private:
        std::set<std::string> m_ignoreList;
        std::map<std::string, Token> m_tokenList;
    };

} // parser

#endif
