#include "Rule.h"

namespace analizer {

    Rule::Rule(const std::string_view& ruleName) :
        m_name{ ruleName }
    {
    }

    Rule& Rule::addPattern(const std::vector<parser::Token>& pattern)
    {
        m_patternes.push_back(pattern);
        return *this;
    }

    bool Rule::operator==(const std::vector<parser::Token>& pattern) const
    {
        for (auto& p : m_patternes) {
            if (p.size() == pattern.size() && std::equal(p.begin(), p.end(), pattern.begin())) {
                return true;
            }
        }

        return false;
    }

} // namespace analizer
