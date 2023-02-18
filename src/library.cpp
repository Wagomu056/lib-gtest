#include "library.h"
#include "http_client/HttpClient.h"

MyLibrary::MyLibrary()
: m_httpClient(new HttpClient())
{
}

void MyLibrary::get(const std::string &header, const MyLibCallback* callback)
{
    HttpRequest request;
    request.setHeader(header);

    m_httpClient->get(request, [callback](bool isSuccess, int code){
        if (callback == nullptr) return;

        if (isSuccess) { (*callback)(MyLibError::None); }
        else {
            switch (code) {
                case 1:
                    (*callback)(MyLibError::A);
                    break;
                case 2:
                    (*callback)(MyLibError::B);
                    break;
                case 3:
                    (*callback)(MyLibError::C);
                    break;
                default:
                    (*callback)(MyLibError::UnknownError);
                    break;
            }
        }
    });
}

void MyLibrary::setHttpClient(HttpClientInterface *client)
{
    if (m_httpClient) {
        delete(m_httpClient);
        m_httpClient = nullptr;
    }
    m_httpClient = client;
}