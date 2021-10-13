#ifndef _INTENTRECOGNIZER_
#define _INTENTRECOGNIZER_

#include <vector>
#include <optional>

#include "Rule.h"

namespace analizer
{

    class IntentRecognizer
    {
    public:
        IntentRecognizer(const parser::Tokenizer& tokenizer);
        IntentRecognizer() = delete;
        ~IntentRecognizer() = default;

        IntentRecognizer& addRule(const Rule& rule);
        std::optional<std::string> getRuleName(const std::string& inputString) const;

    private:
        std::vector<Rule> m_rules;
        const parser::Tokenizer m_tokenizer;
    };

}

#endif // _INTENTRECOGNIZER_
