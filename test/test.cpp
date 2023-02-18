//
// Created by 東口拓也 on 2023/02/16.
//
#include "gtest/gtest.h"

#include "MockHttpClient.h"
#include "library.h"

#define HTTP_CLIENT_ITF const HttpRequest& request, const RequestCallback& callback

TEST(TestTest, equal) {
    EXPECT_EQ(1, 1);
}

TEST(MyLibraryTest, get_normal)
{
    MyLibrary mylib;
    mylib.get("header", nullptr);
}

TEST(MyLibraryTest, get_arg_header)
{
    HttpRequest savedRequest;

    MockHttpClient client;
    EXPECT_CALL(client, get(testing::_, testing::_))
            .WillOnce(testing::SaveArg<0>(&savedRequest));

    MyLibrary mylib;
    mylib.setHttpClient(&client);
    mylib.get("header string", nullptr);

    EXPECT_EQ(savedRequest.getHeader(), "header string");
}

TEST(MyLibraryTest, get_callback_success)
{
    MockHttpClient client;
    EXPECT_CALL(client, get(testing::_, testing::_))
            .WillOnce(testing::Invoke(
                    [] (HTTP_CLIENT_ITF)
                    {
                        callback(true, 1);
                    })
            );

    MyLibrary mylib;
    mylib.setHttpClient(&client);
    MyLibCallback callback = [](MyLibError error) {
        EXPECT_EQ(error, MyLibError::None);
    };
    mylib.get("header string", &callback);
}

TEST(MyLibraryTest, get_callback_error_a)
{
    MockHttpClient client;
    EXPECT_CALL(client, get(testing::_, testing::_))
            .WillOnce(testing::Invoke(
                    [] (HTTP_CLIENT_ITF)
                    {
                        callback(false, 1);
                    })
            );

    MyLibrary mylib;
    mylib.setHttpClient(&client);
    MyLibCallback callback = [](MyLibError error) {
        EXPECT_EQ(error, MyLibError::A);
    };
    mylib.get("header string", &callback);
}

TEST(MyLibraryTest, get_callback_error_unknown)
{
    MockHttpClient client;
    EXPECT_CALL(client, get(testing::_, testing::_))
            .WillOnce(testing::Invoke(
                    [] (HTTP_CLIENT_ITF)
                    {
                        callback(false, 1111);
                    })
            );

    MyLibrary mylib;
    mylib.setHttpClient(&client);
    MyLibCallback callback = [](MyLibError error) {
        EXPECT_EQ(error, MyLibError::UnknownError);
    };
    mylib.get("header string", &callback);
}
