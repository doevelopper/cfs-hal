

#ifndef CFS_HAL_FILEDESCRIPTORTEST_HPP
#define CFS_HAL_FILEDESCRIPTORTEST_HPP

#include <gtest/gtest.h>
#include <array>
#include <cfs/hal/FileDescriptor.hpp>

namespace cfs::hal::test
{
    class FileDescriptorTest : public ::testing::Test 
    {
    public:
	FileDescriptorTest();
	~FileDescriptorTest();

	void SetUp() override;
	void TearDown() override;
 
    protected:
	static constexpr off_t begin = 0;
	static constexpr std::ssize_t rwbufLen{256};
	static constexpr std::size_t len{256};
	static constexpr char fileName[len] = "./FileDescriptor.test";
        std::array<uint8_t, rwbufLen> writeBuffer{{}};

        ::testing::AssertionResult open(const char *fd, FileDescriptor fileDescriptor);
        ::testing::AssertionResult descriptorWrite(const char *fd, FileDescriptor fileDescriptor);
        ::testing::AssertionResult descriptorRead(const char *fd, FileDescriptor fileDescriptor);
        ::testing::AssertionResult writeThenTead(const char *fd, FileDescriptor fileDescriptor);

    }
}

#endif

