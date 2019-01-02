

#ifndef CFS_HAL_FILEDESCRIPTOR_HPP
#define CFS_HAL_FILEDESCRIPTOR_HPP

#include <unistd.h>
#include <cstddef>
#include <cstdint>

namespace cfs::hal
{
    class FileDescriptor
    {
        public:

            FileDescriptor() = delete;
            FileDescriptor(std::int32_t fd);
            FileDescriptor(const FileDescriptor&) = delete;
            FileDescriptor(FileDescriptor&&);
            FileDescriptor& operator=(const FileDescriptor&) = delete;
            FileDescriptor& operator=(FileDescriptor&&);
            virtual ~FileDescriptor();

            inline operator int() const
            {
                return (m_fileDescriptor);
            }

            std::int32_t fileDescriptor()
            {
                return (m_fileDescriptor);
            }

            std::int32_t fileDescriptorOperations(std::int32_t command);
            std::int32_t fileDescriptorOperations(std::int32_t command, std::uint8_t arguments);
            std::int32_t fileDescriptorOperations(std::int32_t command, struct flock * fileLocking);
            std::size_t read(char *buffer, std::size_t size) const;
            std::size_t write(const char *buffer, std::size_t size) const;
            std::size_t pread(char *buffer, std::size_t size, std::size_t off) const;
            std::size_t pwrite(const char *buffer, std::size_t size, std::size_t off) const;
            bool isInUse() const;

        private:

            std::int32_t m_fileDescriptor;
    };
}
#endif

