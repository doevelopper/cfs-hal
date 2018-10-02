
#include <cfs/hal/FileDescriptor.hpp>

FileDescriptor::FileDescriptor(std::int32_t fd)
  :  m_fileDescriptor(fd)
{
    if(m_fileDescriptor < 0)
    {
         // throw bad fd	
    }
}

FileDescriptor::FileDescriptor(FileDescriptor && rhs)
    : m_fileDescriptor(rhs.m_fileDescriptor)
{
    //rhs.m_fileDescriptor = -1
}

FileDescriptor::~FileDescriptor()
{
    if((m_fileDescriptor >= 0) && (::fcntl(m_fileDescriptor, F_GETFD) != -1 || errno != EBADF))
    {
        ::close(m_fileDescriptor)
    }
}

bool FileDescriptor::isInUse() const
{
    return (::fcntl(m_fileDescriptor, F_GETFD) != -1 || errno != EBADF);
}

