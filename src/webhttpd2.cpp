//
// Created by Ran Bao on 31/01/17.
//

#include <iostream>
#include "Config.h"

using namespace std;

int main()
{
    ifstream conf_file("../config/webhttpd_config.json");

    Config conf(conf_file);

    conf_file.close();

    cout << conf.find("user");


    return 0;
}