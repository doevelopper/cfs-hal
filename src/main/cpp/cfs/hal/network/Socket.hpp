

#ifndef CFS_HAL_SOCKET_HPP
#define CFS_HAL_SOCKET_HPP

#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>

#include <string>
#include <cstdint>

#include <cfs/hal/FileDescriptor.hpp>

namespace cfs::hal
{
    class Socket : public FileDescriptor
    {
        public:

            Socket() = delete;
            Socket(const Socket&) = default;
            Socket(Socket&&) = default;
            Socket& operator=(const Socket&) = default;
            Socket& operator=(Socket&&) = default;
            virtual ~Socket();

            void connect(const struct sockaddr *saddr, socklen_t len) const;
            void connect(const struct sockaddr_un &saddr) const;
            void connect(const struct sockaddr_in &saddr) const;
            void connect(const struct sockaddr_in6 &saddr) const;

            void bind(const struct sockaddr *saddr, socklen_t len) const;
            void bind(const struct sockaddr_un &saddr) const;
            void bind(const struct sockaddr_in &saddr) const;
            void bind(const struct sockaddr_in6 &saddr) const;

            void listen(std::int8_t backlog = 5) const;

            Socket accept() const;
            Socket accept(struct sockaddr *saddr, socklen_t *len) const;
            Socket accept(struct sockaddr_storage *saddr, socklen_t *len) const;

            std::size_t recv(char *buffer, std::size_t size, std::int8_t flags = 0) const;
            std::size_t recvmsg(struct msghdr &msg, std::int8_t flags = 0) const;
            std::size_t recvfrom(char *buffer,
                                 std::size_t size,
                                 struct sockaddr *saddr,
                                 socklen_t *len,
                                 std::int8_t flags = 0) const;
            std::size_t recvfrom(char *buffer, std::size_t size, std::int8_t flags = 0) const;
            std::size_t recvfrom(char *buffer,
                                 std::size_t size,
                                 struct sockaddr_storage *saddr,
                                 socklen_t *len,
                                 std::int8_t flags = 0) const;

            std::size_t send(const char *buffer, std::size_t size, std::int8_t flags = 0) const;
            std::size_t sendmsg(const struct msghdr &msg, std::int8_t flags = 0) const;
            std::size_t sendto(const char *buffer,
                               std::size_t size,
                               const struct sockaddr *saddr,
                               socklen_t len,
                               std::int8_t flags = 0) const;
            std::size_t sendto(const char *buffer,
                               std::size_t size,
                               const struct sockaddr_un &saddr,
                               std::int8_t flags = 0) const;
            std::size_t sendto(const char *buffer,
                               std::size_t size,
                               const struct sockaddr_in &saddr,
                               std::int8_t flags = 0) const;
            std::size_t sendto(const char *buffer,
                               std::size_t size,
                               const struct sockaddr_in6 &saddr,
                               std::int8_t flags = 0) const;

            void shutdown(std::int8_t mode) const;

            bool sockatmark() const;

            void getsockopt(int level, int name, char *val, socklen_t *len) const;
            int getsockopt(int level, int name) const;

            void setsockopt(int level, int name, const char *val, socklen_t len) const;
            void setsockopt(int level, int name, int val) const;

            void getsockname(struct sockaddr *saddr, socklen_t *len) const;
            void getsockname(struct sockaddr_storage *saddr, socklen_t *len) const;

            void getpeername(struct sockaddr *saddr, socklen_t *len) const;
            void getpeername(struct sockaddr_storage *saddr, socklen_t *len) const;

        private:

            explicit Socket(std::int32_t fd);
    };
}
#endif

