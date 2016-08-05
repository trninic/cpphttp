#pragma once
#include "Socket.hpp"
#include "Os.hpp"
#include <cstdint>
namespace http
{
    class TcpSocket : public Socket
    {
    public:
        TcpSocket();
        TcpSocket(const std::string &host, uint16_t port);
        TcpSocket(SOCKET socket, const sockaddr *address);
        virtual ~TcpSocket();

        TcpSocket(const TcpSocket&) = delete;
        TcpSocket& operator= (const TcpSocket&) = delete;

        TcpSocket(TcpSocket &&mv);
        TcpSocket& operator = (TcpSocket &&mv);

        void set_socket(SOCKET socket, const sockaddr *address);
        SOCKET get_socket() { return socket; }
        void connect(const std::string &host, uint16_t port);

        virtual std::string address_str()const override;
        const std::string &host()const { return _host; }
        uint16_t port()const { return _port;; }
        virtual void disconnect()override;
        virtual size_t recv(void *buffer, size_t len)override;
        virtual size_t send(const void *buffer, size_t len)override;
        virtual bool check_recv_disconnect()override;
    private:
        SOCKET socket;
        std::string _host;
        uint16_t _port;
    };
}
