//
// Created by 東口拓也 on 2023/02/18.
//

#include <iostream>
#include "HttpClient.h"

void HttpClient::get(const HttpRequest& request, const RequestCallback& callback)
{
    std::cout << "header: " << request.getHeader() << std::endl;

    if (request.getHeader().empty()) {
        callback(false, -1);
    }
    else {
        callback(true, 1);
    }
}
