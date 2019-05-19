//
// Created by adrien on 18/05/19.
//

#ifndef ATAXX_INVALIDVALUE_H
#define ATAXX_INVALIDVALUE_H

#include <string>
#include <iostream>
#define UNEXPECTED_ERROR "Unexpected error."

using std::string;
using std::cout;
using std::endl;

template<typename Error>
class InvalidValue{
private:
    string functionName;
    Error value;
public:
    const string &getFunctionName() const { return functionName; }
    Error getValue() const { return value; }

    InvalidValue(const string &functionName, Error value) : functionName(functionName), value(value) {}
    virtual ~InvalidValue() = default;
    virtual const string specificMessage(){
        return "Value is invalid for unkown reason.";
    }
    void what(){
        cout << "Invalid value: \"" << getValue() << "\", used in function \"" << getFunctionName()
             << "\". " << specificMessage() << endl;
    }
};

#endif //ATAXX_INVALIDVALUE_H
