#include <iostream>
#include "Tokenizer.h"
#include "IntentRecognizer.h"

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cout << "Wrong usage!!!" << std::endl;
        std::cout << "Enter the input string in quotation marks." << std::endl;
        return 1;
    }

    std::cout << argv[1] << std::endl;

    /// initialization. can be moved to addition function
    const std::set<std::string_view> ignore{
        "the", "a", "an"
    };

    const std::map<std::string_view, parser::Token> tokens{
        {"is", parser::Token::is},
        {"was", parser::Token::is},
        {"what", parser::Token::What},
        {"how", parser::Token::What},
        {"weather", parser::Token::Weather},
        {"like", parser::Token::Like},
        {"today", parser::Token::Time},
        {"yesterday", parser::Token::Time},
        {"tomorrow", parser::Token::Time},
        {"morning", parser::Token::Time},
        {"evening", parser::Token::Time},
        {"tell", parser::Token::Tell},
        {"interesting", parser::Token::Adjective},
        {"some", parser::Token::Adjective},
        {"me", parser::Token::Pronoun},
        {"us", parser::Token::Pronoun},
        {"them", parser::Token::Pronoun},
        {"fact", parser::Token::Fact},
        {"in", parser::Token::In},
    };

    parser::Tokenizer tok(ignore, tokens);

    analizer::IntentRecognizer recognizer{ tok };

    analizer::Rule r1{ "Get Weather" };
    r1.addPattern({ parser::Token::What, parser::Token::is, parser::Token::Weather, parser::Token::Like, parser::Token::Time}).
       addPattern({ parser::Token::What, parser::Token::is, parser::Token::Weather, parser::Token::Time});

    analizer::Rule r2{ "Get Weather City" };
    r2.addPattern({ parser::Token::What, parser::Token::is, parser::Token::Weather, parser::Token::Like, parser::Token::In, parser::Token::Empty}).
        addPattern({ parser::Token::What, parser::Token::is, parser::Token::Weather, parser::Token::In, parser::Token::Empty }).
        addPattern({ parser::Token::What, parser::Token::is, parser::Token::Weather, parser::Token::Like, parser::Token::In, parser::Token::Empty, parser::Token::Time});

    analizer::Rule r3{ "Get Fact" };
    r3.addPattern({ parser::Token::Tell, parser::Token::Pronoun, parser::Token::Adjective, parser::Token::Fact });

    recognizer.addRule(r1).addRule(r2).addRule(r3);

    /// lets do it
    auto ruleName = recognizer.getRuleName(argv[1]);
    if (ruleName) {
        std::cout << "Intent: " << ruleName.value();
    }
    else {
        std::cout << "Sorry, I cant recognize your intent.";
    }

    std::cout << std::endl;
}

