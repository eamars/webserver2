//
// Created by Ran Bao on 30/01/17.
//

#include <iostream>
#include "Config.h"

using namespace std;

Config::Config() {

}

Config::Config(std::ifstream &file) {
    // parse as json file
    Json::Reader reader;
    reader.parse(file, root);
}

Config::Config(std::string &text) {
    // read from string
    Json::Reader reader;
    reader.parse(text, root);
}

Config::~Config() {

}

Json::Value Config::find(std::string key) {
    return find_helper(root, key);
}

std::string Config::dump() {
    Json::StyledWriter writer;
    return writer.write(root);
}

void Config::dump(std::ofstream &file) {
    // write json to file
    Json::StyledWriter writer;
    file << writer.write(root);
}

Json::Value Config::find_helper(Json::Value &node, std::string &key) {
    // is object and array type
    if (node.type() == Json::objectValue)
    {
        for (auto &item : node.getMemberNames())
        {
            // see if current node is the right one
            if (item == key)
            {
                return node[item];
            }

            // search in child
            Json::Value result = find_helper(node[item], key);
            if (!result.isNull())
            {
                return result;
            }
        }
    }

    return Json::Value();
}
