//
// Created by 東口拓也 on 2023/02/18.
//

#ifndef LIB_GTEST_MOCKHTTPCLIENT_H
#define LIB_GTEST_MOCKHTTPCLIENT_H

#include "../src/http_client/HttpClientInterface.h"
#include <gmock/gmock.h>

class MockHttpClient : public HttpClientInterface
{
public:
    ~MockHttpClient()
    {
    };

    MOCK_METHOD2(get,  void(const HttpRequest& request, const RequestCallback& callback));
};

#endif //LIB_GTEST_MOCKHTTPCLIENT_H
