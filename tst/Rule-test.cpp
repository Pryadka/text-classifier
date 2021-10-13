#include "gtest/gtest.h"
#include "Rule.h"

class RuleTest : public ::testing::Test
{
protected:
    RuleTest() :
        rule{"the"}
    {}

    void SetUp() override
    {
        rule.addPattern({ parser::Token::What, parser::Token::is }).
            addPattern({ parser::Token::What, parser::Token::is, parser::Token::Fact });
    }

    analizer::Rule rule;
};

TEST_F(RuleTest, wrongPattern) {
    EXPECT_FALSE((rule == std::vector<parser::Token>{ parser::Token::Tell, parser::Token::Pronoun, parser::Token::Adjective, parser::Token::Fact }));
}

TEST_F(RuleTest, truePattern) {
    EXPECT_TRUE((rule == std::vector<parser::Token>{parser::Token::What, parser::Token::is}));
}

