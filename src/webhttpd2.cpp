//
// Created by Ran Bao on 31/01/17.
//

#include <iostream>
#include "Config.h"
#include <boost/network/protocol/http/parser.hpp>


using namespace std;

namespace http = boost::network::http;


int main()
{
    ifstream conf_file("../config/webhttpd_config.json");

    Config conf(conf_file);

    conf_file.close();

    cout << conf.find("") << endl;

    http::client client;
    std::ostringstream url;
    url << "http://www.google.com/";
    http::client::request request(url.str());
    http::client::response response =
            client.get(request);

    for (auto &entry : response.headers())
    {
        cout << entry.first << ":" << entry.second << endl;
    }


    return 0;
}