//
// Created by 東口拓也 on 2023/02/18.
//

#ifndef LIB_GTEST_HTTPCLIENT_H
#define LIB_GTEST_HTTPCLIENT_H

#include "HttpClientInterface.h"

class HttpClient : public HttpClientInterface
{
public:
    ~HttpClient()
    {
    };

    void get(const HttpRequest& request, const RequestCallback& callback) override;
};


#endif //LIB_GTEST_HTTPCLIENT_H
