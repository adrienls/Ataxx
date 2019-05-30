//
// Created by adrien on 21/05/19.
//

#ifndef ATAXX_ARGUMENTS_H
#define ATAXX_ARGUMENTS_H

#include <map>
#include <string>
#include <getopt.h>

using std::map;
using std::string;

const map<char, string> arguments(const int& argc, char* const* argv, const char* shortOpts, const struct option longOpts[]);

#endif //ATAXX_ARGUMENTS_H
