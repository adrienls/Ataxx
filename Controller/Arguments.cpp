//
// Created by adrien on 21/05/19.
//

#include <getopt.h>
#include <bits/stl_pair.h>
#include <iostream>
#include "Arguments.h"
#include "exception/too_many_arguments.h"

using std::pair;
using std::cout;
using std::endl;

Arguments::Arguments(const int& argc, char* const* const argv, const char* const shortOpts, const struct option longOpts[]) {
    int optionIndex = 0; //getopt_long stores the option index here
    int optionValue = getopt_long(argc, argv, shortOpts, longOpts, &optionIndex);

    while(optionValue != -1) {
        if(optionValue != 0){ //optionValue is 0 if a flag is set
            string arg = (optarg == nullptr)? "" : optarg; //makes sure a valid string is added to the map
            this->options.insert(pair<char, string>(optionValue, arg));
        }
        optionValue = getopt_long(argc, argv, shortOpts, longOpts, &optionIndex);
    }

    if (optind < argc) {
        stringstream invalidArguments;
        //Saves any remaining command line argument in a stringstream (not options)
        invalidArguments << argv[optind];
        optind++;
        while (optind < argc){
            invalidArguments << ", " << argv[optind];
            optind++;
        }
        throw too_many_arguments("Arguments() constructor", invalidArguments.str());
    }
}

const map<char, string> &Arguments::getOptions() const noexcept{
    return options;
}

void Arguments::display() noexcept{
    cout << endl << "Options and corresponding arguments: " << endl;
    for (const auto& opt : this->options){
        cout << opt.first << " => " << opt.second << endl;
    }
}
