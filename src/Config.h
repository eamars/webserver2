//
// Created by Ran Bao on 30/01/17.
//

#ifndef WEBSERVER2_CONFIG_H
#define WEBSERVER2_CONFIG_H

#include <json/json.h>
#include <string>
#include <fstream>

class Config {
private:
    Json::Value root;

    Json::Value find_helper(Json::Value &node, std::string &key);

public:
    // default constructor (always return default settings)
    Config();

    // read configuration from file
    Config(std::ifstream &file);

    // read configuratio from text
    Config(std::string &text);

    // de-constructor
    ~Config();

    // recursively search for a specific key
    Json::Value find(std::string key);

    // dump the whole json structrue to human readable strings
    std::string dump();
    void dump(std::ofstream &file);
};


#endif //WEBSERVER2_CONFIG_H
