//
// Created by 東口拓也 on 2023/02/18.
//

#ifndef LIB_GTEST_HTTPREQUEST_H
#define LIB_GTEST_HTTPREQUEST_H

#include <string>

class HttpRequest
{
public:
    HttpRequest()
    : m_header("")
    {};

    void setHeader(const std::string& header) {
        m_header = header;
    };

    const std::string& getHeader() const {
        return m_header;
    };

private:
    std::string m_header;
};

#endif //LIB_GTEST_HTTPREQUEST_H
