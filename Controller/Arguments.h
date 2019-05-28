//
// Created by adrien on 21/05/19.
//

#ifndef ATAXX_ARGUMENTS_H
#define ATAXX_ARGUMENTS_H

#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;

class Arguments {
    map<char, string> options;
public:
    Arguments(const int& argc, char* const* argv, const char* shortOpts, const struct option longOpts[]);
    virtual ~Arguments() = default;
    const map<char, string>& getOptions() const noexcept;
    void display() noexcept;
};

#endif //ATAXX_ARGUMENTS_H
