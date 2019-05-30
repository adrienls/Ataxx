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

class invalid_value : public exception{
private:
    string functionName;
    string value;
    string specificMessage;
    string displayError;
public:
    invalid_value() = delete;
    invalid_value(const invalid_value& e) noexcept
    : invalid_value(e.getFunctionName(), e.getValue(), e.getSpecificMessage()) {}

    invalid_value(const string& functionName, const string& value, const string& specificMessage = "") noexcept
    : functionName(functionName), value(value), specificMessage(specificMessage) {
        stringstream what;
        what << "Invalid value: \"" << this->value << "\", used in function \""
        << this->functionName << "\". " << this->specificMessage;
        this->displayError = what.str();
    }

    virtual ~invalid_value() = default;

    const string &getFunctionName() const noexcept {return functionName;}
    const string &getValue() const noexcept {return value;}
    const string &getSpecificMessage() const noexcept {return specificMessage;}

    virtual const char* what() const noexcept override{
        return this->displayError.c_str();
    }
};

#endif //ATAXX_INVALIDVALUE_H