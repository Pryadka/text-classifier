#include "gtest/gtest.h"
#include "Tokenizer.h"

class ParserTest : public ::testing::Test
{
protected:
    ParserTest() : 
        tok{ {"the"},
             {
               {"x", parser::Token::is},
               {"y", parser::Token::is},
               {"aa", parser::Token::What},
               {"bb", parser::Token::Weather},
             }
         }
    {}
    parser::Tokenizer tok;
};


TEST_F(ParserTest, emptyInput) {
    std::string input{""};
    auto v = tok.parse(input);
    EXPECT_TRUE(v.empty());
}

TEST_F(ParserTest, simpleTest) {
    std::string input{ "the x y Aa bb." };
    auto v = tok.parse(input);

    //EXPECT_EQ(v.size(), 4);
    EXPECT_EQ(v[0], parser::Token::is);
    EXPECT_EQ(v[1], parser::Token::is);
    EXPECT_EQ(v[2], parser::Token::What);
    //EXPECT_EQ(v[3], parser::Token::Weather);
}

TEST_F(ParserTest, emptyItemTest) {
    std::string input{ "x y z" };
    auto v = tok.parse(input);
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v.back(), parser::Token::Empty);
}
