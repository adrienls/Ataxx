//
// Created by adrien on 18/05/19.
//

#ifndef ATAXX_INVALIDVALUE_H
#define ATAXX_INVALIDVALUE_H

#include <string>
#include <iostream>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::exception;
using std::stringstream;

template<typename Error>
class invalid_value : public exception{
private:
    string functionName;
    Error value;
    string specificMessage;
public:
    invalid_value() = delete;
    invalid_value(const invalid_value& e) noexcept : invalid_value(e.getFunctionName(), e.getValue(), e.getSpecificMessage()) {}
    invalid_value(const string& functionName, Error value, const string& specificMessage = "") noexcept : functionName(functionName), value(value), specificMessage(specificMessage) {}
    virtual ~invalid_value() = default;

    const string &getFunctionName() const {return functionName;}
    Error getValue() const {return value;}
    const string &getSpecificMessage() const {return specificMessage;}

    virtual const char* what() const noexcept override{
        stringstream what;
        what << "Invalid value: \"" << this->value << "\", used in function \"" << this->functionName
             << "\". " << this->specificMessage << endl;
        return what.str().c_str();
    }
};

#endif //ATAXX_INVALIDVALUE_H