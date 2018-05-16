#ifndef CFS_HAL_FILEDESCRIPTOR_HPP
#define CFS_HAL_FILEDESCRIPTOR_HPP

#include <unistd.h>
#include <cstddef>

namespace cfs::hal
{
    class FileDescriptor
    {
	 public:

   	     FileDescriptor() = delete;
	     FileDescriptor(std::int32_t fd);
	     FileDescriptor(const FileDescriptor&) = delete;
             FileDescriptor(FileDescriptor&&) = delete;
	     FileDescriptor& operator=(const FileDescriptor&) = delete;
             FileDescriptor& operator=(FileDescriptor&&) = delete;
             virtual ~FileDescriptor();

	     inline operator int() const 
	     {
                 return m_fileDescriptor;
	     }

	 private:

             std::int32_t m_fileDescriptor;
    };
}
#endif
