//
// Created by adrien on 21/05/19.
//

#include <getopt.h>
#include <bits/stl_pair.h>
#include <iostream>
#include "Arguments.h"
#include "exception/invalid_argument.h"

using std::pair;
using std::cout;
using std::endl;

Arguments::Arguments(const int& argc, char* const* const argv, const char* const shortOpts, struct option longOpts[]) {
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
        vector<string> invalidArguments;
        //Saves any remaining command line argument in a vector (not options)
        while (optind < argc){
            invalidArguments.emplace_back(argv[optind]);
            optind++;
        }
        throw invalid_argument<vector<string>>("Arguments() constructor", invalidArguments);
    }
}

const map<char, string> &Arguments::getOptions() const {
    return options;
}

void Arguments::display(){
    cout << endl << "Options and corresponding arguments: " << endl;
    for (const auto& opt : this->options){
        cout << opt.first << " => " << opt.second << endl;
    }
}
