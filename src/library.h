#ifndef LIB_GTEST_LIBRARY_H
#define LIB_GTEST_LIBRARY_H

#include "http_client/HttpClientInterface.h"

enum class MyLibError
{
    None,
    A,
    B,
    C,
    UnknownError,
};

typedef std::function<void(MyLibError)> MyLibCallback;

class MyLibrary
{
public:
    MyLibrary();

    void get(const std::string &header, const MyLibCallback* callback);

    void setHttpClient(HttpClientInterface* client);

private:
    HttpClientInterface* m_httpClient;
};

#endif //LIB_GTEST_LIBRARY_H
