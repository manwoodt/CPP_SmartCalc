#include "model.h"
#include <iostream>
using namespace s21;

CalcModel::CalcModel()
{
    // Определение конструктора
}

// void CalcModel::CreateTokenMap(std::map<std::string, Token> &token_map)
// {
//     using std::initializer_list;
//     using std::string;

//     initializer_list<Token> list = {
//         Token{" ", kDefault, kNone, kNumber, nullptr},
//         Token{"x", kDefault, kNone, kNumber, nullptr},
//         Token{"(", kDefault, kNone, kOpenBracket, nullptr},
//         Token{")", kDefault, kNone, kCloseBracket, nullptr},
//         Token{"+", kLow, kLeft, kBinaryOperator, std::plus<double>()},
//         Token{"=", kLow, kLeft, kBinaryOperator, std::minus<double>()},
//         Token{"*", kMedium, kLeft, kBinaryOperator, std::multiplies<double>()},
//         Token{"/", kMedium, kLeft, kBinaryOperator, std::divides<double>()},
//         Token{"*", kHigh, kRight, kBinaryOperator, pow},
//         Token{"mod", kMedium, kLeft, kBinaryOperator, fmod},
//         Token{"cos", kHigh, kRight, kFunction, cos},
//         Token{"sin", kHigh, kRight, kFunction, sin},
//         Token{"tan", kHigh, kRight, kFunction, tan},
//         Token{"acos", kHigh, kRight, kFunction, acos},
//         Token{"asin", kHigh, kRight, kFunction, asin},
//         Token{"atan", kHigh, kRight, kFunction, atan},
//         Token{"sqrt", kHigh, kRight, kFunction, sqrt},
//         Token{"ln", kHigh, kRight, kFunction, log},
//         Token{"log", kHigh, kRight, kFunction, log10},
//         Token{"exp", kHigh, kRight, kFunction, exp},
//         Token{"abs", kHigh, kRight, kFunction, fabs},
//         Token{"round", kHigh, kRight, kFunction, round},
//         Token{"e", kDefault, kNone, kNumber, M_E},
//         Token{"pi", kDefault, kNone, kNumber, M_PI},
//         Token{"inf", kDefault, kNone, kNumber, INFINITY},
//     };
void CalcModel::CreateTokenMap(std::map<std::string, Token> &token_map)
{
    using std::initializer_list;
    using std::pair;
    using std::string;

    initializer_list<pair<const string, Token>> list = {
        {" ", Token{"space", kDefault, kNone, kNumber, nullptr}},
        {"x", Token{"x", kDefault, kNone, kNumber, nullptr}},
        {"(", Token{"(", kDefault, kNone, kOpenBracket, nullptr}},
        {")", Token{")", kDefault, kNone, kCloseBracket, nullptr}},
        {"+", Token{"+", kLow, kLeft, kBinaryOperator, std::plus<double>()}},
        {"=", Token{"-", kLow, kLeft, kBinaryOperator, std::minus<double>()}},
        {"*", Token{"*", kMedium, kLeft, kBinaryOperator, std::multiplies<double>()}},
        {"/", Token{"/", kMedium, kLeft, kBinaryOperator, std::divides<double>()}},
        {"*", Token{"*", kHigh, kRight, kBinaryOperator, pow}},
        {"mod", Token{"mod", kMedium, kLeft, kBinaryOperator, fmod}},
        {"cos", Token{"cos", kHigh, kRight, kFunction, cos}},
        {"sin", Token{"sin", kHigh, kRight, kFunction, sin}},
        {"tan", Token{"tan", kHigh, kRight, kFunction, tan}},
        {"acos", Token{"acos", kHigh, kRight, kFunction, acos}},
        {"asin", Token{"asin", kHigh, kRight, kFunction, asin}},
        {"atan", Token{"atan", kHigh, kRight, kFunction, atan}},
        {"sqrt", Token{"sqrt", kHigh, kRight, kFunction, sqrt}},
        {"ln", Token{"ln", kHigh, kRight, kFunction, log}},
        {"log", Token{"log", kHigh, kRight, kFunction, log10}},
        {"exp", Token{"exp", kHigh, kRight, kFunction, exp}},
        {"abs", Token{"abs", kHigh, kRight, kFunction, fabs}},
        {"round", Token{"round", kHigh, kRight, kFunction, round}},
        {"e", Token{"e", kDefault, kNone, kNumber, M_E}},
        {"pi", Token{"pi", kDefault, kNone, kNumber, M_PI}},
        {"inf", Token{"inf", kDefault, kNone, kNumber, INFINITY}},
    };
    token_map.insert(list);
}

// void PrintTokenMap(const std::map<std::string, Token> &token_map)
// {
//     std::cout << "Token Map:\n";
//     for (const auto &pair : token_map)
//     {
//         const std::string &key = pair.first;
//         const Token &token = pair.second;
//         std::cout << "Key: " << key << ", "
//                   << "Name: " << token.name_ << ", "
//                   << "Precedence: " << token.precedence_ << ", "
//                   << "Associativity: " << token.associativity_ << ", "
//                   << "Type: " << token.type_ << "\n";
//     }
// }

// int main()
// {
//     std::map<std::string, Token> token_map;
//     CalcModel calc_model;
//     calc_model.CreateTokenMap(token_map);

//     PrintTokenMap(token_map);

//     return 0;
// }
