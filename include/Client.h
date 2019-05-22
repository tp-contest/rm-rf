//
// Created by Aleksander
//

#ifndef PRJ_CLIENT_H
#define PRJ_CLIENT_H

#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

#include <sstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/beast/http.hpp>

using boost::asio::ip::tcp;
namespace http = boost::beast::http;

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

// ex:  client c(io_service, "127.0.0.1", "8080", "/tp-contest-api/", "GET", "45ezkf8vn1mgim686gwaaq61ry5y5gt4", "", "");
// Client c(io_service, "jufc.ru", "",  "/", "POST", "45ezkf8vn1mgim686gwaaq61ry5y5gt4", "aleksander", "1111");

class Client {
public:
    Client(boost::asio::io_service& io_service,
    const std::string& host, const std::string& port, const std::string& path, const std::string& method, const std::string& sessId,
    const std::string& name, const std::string& pass)
    : resolver_(io_service),
    socket_(io_service),
    method_(method),
    sessionId_(sessId),
    username_(name),
    password_(pass)
    {
        std::ostream request_stream(&request_);
        request_stream << method + " " << path << " HTTP/1.1\r\n";
        request_stream << "Host: " << host << "\r\n";
        request_stream << "Cookie: sessionId=" << sessId;
        if (name.empty() && pass.empty()) {
            request_stream << "; username=" << name << "; " << "password=" << pass << "\r\n";
        } else {
            request_stream << "\r\n";
        }
        request_stream << "Accept: */*\r\n";
        request_stream << "Connection: keep-alive\r\n\r\n";

        tcp::resolver::query query(host, port);
        resolver_.async_resolve(query,
                                boost::bind(&Client::resolve, this,
                                            boost::asio::placeholders::error,
                                            boost::asio::placeholders::iterator));
    }
    Client(boost::asio::io_service& io_service,
            const std::string& host, const std::string& port, const std::string& path, const std::string& method, boost::property_tree::ptree& body, const std::string& sessId,
            const std::string& name, const std::string& pass)
    : resolver_(io_service),
    socket_(io_service),
    method_(method),
    sessionId_(sessId),
    username_(name),
    password_(pass)
    {
        std::ostream request_stream(&request_);
        request_stream << method + " " << path << " HTTP/1.1\r\n";
        request_stream << "Host: " << host << "\r\n";
        request_stream << "Content-Length: " << body.size() << "\r\n";
        request_stream << "Content-Type: multipart/form-data; boundary=--Asrf456BGe4h" << "\r\n";
        request_stream << "Cookie: sessionId=" << sessId;
        if (!name.empty() && !pass.empty()) {
            request_stream << "; username=" << name << "; " << "password=" << pass << "\r\n";
        } else {
            request_stream << "\r\n";
        }
        request_stream << "Accept: */*\r\n";
        request_stream << "Connection: keep-alive\r\n\r\n";

        request_stream << "--Asrf456BGe4h\r\n";
        request_stream << "Content-Disposition: form-data; name=\"json\"\r\n";
        request_stream << "Content-Type: application/json\r\n\r\n";
        request_stream << body.data() << "\r\n";
        request_stream << "--Asrf456BGe4h--\r\n";

        tcp::resolver::query query(host, port);
        resolver_.async_resolve(query,
                                boost::bind(&Client::resolve, this,
                                            boost::asio::placeholders::error,
                                            boost::asio::placeholders::iterator));
    }

    Client(boost::asio::io_service& io_service,
            const std::string& host, const std::string& port, const std::string& path, const std::string& method, const char* body, const std::string& filename, const std::string& sessId,
            const std::string& name, const std::string& pass)
    : resolver_(io_service),
    socket_(io_service),
    method_(method),
    sessionId_(sessId),
    username_(name),
    password_(pass)
    {
        std::ostream request_stream(&request_);
        request_stream << method + " " << path << " HTTP/1.1\r\n";
        request_stream << "Host: " << host << "\r\n";
        request_stream << "Content-Length: " << strlen(body) << "\r\n";
        request_stream << "Content-Type: multipart/form-data; boundary=--Asrf456BGe4h" << "\r\n";
        request_stream << "Cookie: sessionId=" << sessId;
        if (!name.empty() && !pass.empty()) {
            request_stream << "; username=" << name << "; " << "password=" << pass << "\r\n";
        } else {
            request_stream << "\r\n";
        }
        request_stream << "Accept: */*\r\n";
        request_stream << "Connection: keep-alive\r\n\r\n";

        request_stream << "--Asrf456BGe4h\r\n";
        request_stream << "Content-Disposition: form-data; name=\"file\"; filename=\"" << filename << "\"\r\n";
        request_stream << "Content-Type: application/octet-stream\r\n\r\n";
        request_stream << body << "\r\n";
        request_stream << "--Asrf456BGe4h--\r\n";

        tcp::resolver::query query(host, port);
        resolver_.async_resolve(query,
                                boost::bind(&Client::resolve, this,
                                            boost::asio::placeholders::error,
                                            boost::asio::placeholders::iterator));
    }

private:
    void resolve(const boost::system::error_code &err, tcp::resolver::iterator endpoint_iterator) {
        if (!err) {
            tcp::endpoint endpoint = *endpoint_iterator;
            socket_.async_connect(endpoint,
                                  boost::bind(&Client::connect, this,
                                              boost::asio::placeholders::error, ++endpoint_iterator));
        } else {
            std::cout << "Error resolve: " << err.message() << "\n";
        }
    }

    void connect(const boost::system::error_code &err, tcp::resolver::iterator endpoint_iterator) {
        if (!err) {
            // The connection was successful. Send the request.
            boost::asio::async_write(socket_, request_,
                                     boost::bind(&Client::writeRequest, this,
                                                 boost::asio::placeholders::error));
        } else if (endpoint_iterator != tcp::resolver::iterator()) {
            // The connection failed. Try the next endpoint in the list.
            socket_.close();
            tcp::endpoint endpoint = *endpoint_iterator;
            socket_.async_connect(endpoint,
                                  boost::bind(&Client::connect, this,
                                              boost::asio::placeholders::error, ++endpoint_iterator));
        } else {
            std::cout << "Error connect: " << err.message() << "\n";
        }
    }

    void writeRequest(const boost::system::error_code &err) {
        if (!err) {
            // Read the response status line.
            boost::asio::async_read_until(socket_, response_, "\r\n",
                                          boost::bind(&Client::readStatusLine, this,
                                                      boost::asio::placeholders::error));
        } else {
            std::cout << "Error writeRequest: " << err.message() << "\n";
        }
    }

    void readStatusLine(const boost::system::error_code &err) {
        if (!err) {
            // Check that response is OK.
            std::istream response_stream(&response_);
            std::string httpVersion;
            unsigned int statusCode;
            response_stream >> httpVersion;
            response_stream >> statusCode;
            std::string status_message;
            std::getline(response_stream, status_message);
            if (!response_stream || httpVersion.substr(0, 5) != "HTTP/") {
                std::cout << "Invalid response\n";
                return;
            }
            if (statusCode != 200) {
                std::cout << "Response returned with status code ";
                std::cout << statusCode << "\n";
                return;
            }
            boost::asio::async_read_until(socket_, response_, "\r\n\r\n",
                                          boost::bind(&Client::readHeaders, this,
                                                      boost::asio::placeholders::error));
        } else {
            std::cout << "Error Status: " << err << "\n";
        }
    }

    void readHeaders(const boost::system::error_code &err) {
        if (!err) {
            std::istream response_stream(&response_);
            std::string header;
            while (std::getline(response_stream, header) && header != "\r") {
                std::cout << header << "\n";
            }
            std::cout << "\n";
            if (response_.size() > 0) {
                std::cout << &response_;
            }
            boost::asio::async_read(socket_, response_,
                                    boost::asio::transfer_at_least(1),
                                    boost::bind(&Client::readContent, this,
                                                boost::asio::placeholders::error));
        } else {
            std::cout << "Error readHeaders: " << err << "\n";
        }
    }

    void readContent(const boost::system::error_code &err) {
        if (!err) {
            std::cout << &response_;
            boost::asio::async_read(socket_, response_,
                                    boost::asio::transfer_at_least(1),
                                    boost::bind(&Client::readContent, this,
                                                boost::asio::placeholders::error));
        } else if (err != boost::asio::error::eof) {
            std::cout << "Error readContent: " << err << "\n";
        }
    }

    tcp::resolver resolver_;
    tcp::socket socket_;
    boost::asio::streambuf request_;
    boost::asio::streambuf response_;
    std::string sessionId_;
    std::string method_;
    std::string username_;
    std::string password_;
};


#endif //PRJ_CLIENT_H
