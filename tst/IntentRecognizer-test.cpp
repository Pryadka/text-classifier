#include "gtest/gtest.h"
#include "IntentRecognizer.h"

class IntentRecognizer : public ::testing::Test
{
protected:
    IntentRecognizer() :
        tok{
             {"the"},
             {
               {"x", parser::Token::is},
               {"y", parser::Token::is},
               {"aa", parser::Token::What},
               {"bb", parser::Token::Weather},
             }
           },
        recognizer{tok}
    {}

    void SetUp() override
    {
        analizer::Rule rule1{ "name1" };

        rule1.addPattern({ parser::Token::What, parser::Token::is }).
            addPattern({ parser::Token::What, parser::Token::is, parser::Token::Fact });

        analizer::Rule rule2{ "name2" };

        rule2.addPattern({ parser::Token::is, parser::Token::What}).
            addPattern({ parser::Token::is, parser::Token::What, parser::Token::Fact });

        recognizer.addRule(rule1).addRule(rule2);
    }

    parser::Tokenizer tok;
    analizer::IntentRecognizer recognizer;
};

TEST_F(IntentRecognizer, truePatternTest) {
    const std::string t1{ "aa x?" };
    const std::string t2{ "x aa." };

    EXPECT_TRUE(recognizer.getRuleName(t1));
    EXPECT_EQ(recognizer.getRuleName(t1).value(), "name1");

    EXPECT_TRUE(recognizer.getRuleName(t2));
    EXPECT_EQ(recognizer.getRuleName(t2).value(), "name2");
}

TEST_F(IntentRecognizer, emptyPatternTest) {
    const std::string t0{ "aa bb." };

    EXPECT_FALSE(recognizer.getRuleName(t0));
}