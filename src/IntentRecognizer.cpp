#include "IntentRecognizer.h"

namespace analizer
{
    IntentRecognizer::IntentRecognizer(const parser::Tokenizer& tokenizer) :
        m_tokenizer{tokenizer}
    {
    }

    IntentRecognizer& analizer::IntentRecognizer::addRule(const Rule& rule)
    {
        m_rules.push_back(rule);
        return *this;
    }

    std::optional<std::string> analizer::IntentRecognizer::getRuleName(const std::string& inputString) const
    {
        auto v = m_tokenizer.parse(inputString);

        for (const auto& rule: m_rules) {
            if (rule == v) return rule.getName();
        }

        return std::optional<std::string>();
    }

}
