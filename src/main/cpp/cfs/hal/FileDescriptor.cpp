
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
    if(m_fileDescriptor >= 0)
    {
        close(m_fileDescriptor)
    }
}
