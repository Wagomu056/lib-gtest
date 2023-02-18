//
// Created by 東口拓也 on 2023/02/18.
//

#ifndef LIB_GTEST_HTTPCLIENTINTERFACE_H
#define LIB_GTEST_HTTPCLIENTINTERFACE_H

#include "HttpRequest.h"

typedef std::function<void(bool, int)> RequestCallback;

class HttpClientInterface
{
public:
    virtual ~HttpClientInterface()
    {
    };

    virtual void get(const HttpRequest& request, const RequestCallback& callback) = 0;
};

#endif //LIB_GTEST_HTTPCLIENTINTERFACE_H
