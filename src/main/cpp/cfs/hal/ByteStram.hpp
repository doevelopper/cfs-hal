

#include <cstdint>
#include <vector>
#include <array>

namespace cfs::hal
{
    class ByteStram : public std::stringstream
    {
        enum class Endianess : std:uint8_t
        {
            BIG,
            LITTLE,
            NATIVE
        };

        enum class BitEndianess : std:uint8_t
        {
            MSB,
            LSB
        };

        public:

        ByteStram() noexcept;
        ~ByteStram() noexcept;
        ByteStram(const ByteStram & other);
        ByteStram(ByteStram && other) noexcept;
        ByteStram& operator=(const ByteStram & other);
        ByteStram& operator=(ByteStram && other) noexcept;
        void clear
        void reset();
        bool empty();
        unsigned int length();
        template <typename T>
        ByteStream & operator>>(T& outData)
        {
            this->read(reinterpret_cast<char *>(&outData), sizeof(outData));
            return (*this);
        }

        template <typename T>
        ByteStream & operator<<(T& outData)
        {
            this->write(reinterpret_cast<const char *>(&data), sizeof(data));
            return (*this);
        }
	ByteStream & operator<<(const std::uint8_t & data);
	ByteStream & operator>>(std::uint8_t & data);
	ByteStream & operator<<(const std::uint16_t & data);
	ByteStream & operator>>(std::uint16_t & data);
	ByteStream & operator<<(const std::uint32_t & data);
	ByteStream & operator>>(std::uint32_t & data);
	ByteStream & operator<<(const std::uint64_t & data);
	ByteStream & operator>>(std::uint64_t & data);
	ByteStream & operator<<(const std::int8_t & data);
	ByteStream & operator>>(std::int8_t & data);
	ByteStream & operator<<(const std::int16_t & data);
	ByteStream & operator>>(std::int16_t & data);
	ByteStream & operator<<(const std::int32_t & data);
	ByteStream & operator>>(std::int32_t & data);
	ByteStream & operator<<(const std::int64_t & data);
	ByteStream & operator>>(std::int64_t & data);
    ByteStream & operator<<(const bool & data);
    ByteStream & operator>>(bool & data);
    ByteStream & operator<<(const char & data);
    ByteStream & operator>>(char & data);
    ByteStream & operator<<(const short & data);
    ByteStream & operator>>(short & data);
    ByteStream & operator<<(const int & data);
    ByteStream & operator>>(int & data);
    ByteStream & operator<<(const long & data);
    ByteStream & operator>>(long & data);
    ByteStream & operator<<(const long long & data);
    ByteStream & operator>>(long long & data);
    ByteStream & operator<<(const float & data);
    ByteStream & operator>>(float & data);
    ByteStream & operator<<(const double & data);
    ByteStream & operator>>(double & data);
    ByteStream & operator<<(const long double & data);
    ByteStream & operator>>(long double & data);
    ByteStream & operator<<(const unsigned char & data);
    ByteStream & operator>>(unsigned char & data);
    ByteStream & operator<<(const unsigned short & data);
    ByteStream & operator>>(unsigned short & data);
    ByteStream & operator<<(const unsigned int & data);
    ByteStream & operator>>(unsigned int & data);
    ByteStream & operator<<(const unsigned long & data);
    ByteStream & operator>>(unsigned long & data);
    ByteStream & operator<<(const unsigned long long & data);
    ByteStream & operator>>(unsigned long long & data);
    ByteStream & operator<<(const std::string & data);
    ByteStream & operator>>(std::string & data);
    ByteStream & operator<<(const std::vector<char> & data);
    ByteStream & operator>>(std::vector<char> & data);
    ByteStream & operator<<(const std::array<char> & data);
    ByteStream & operator>>(std::array<char> & data);
        protected:
        private:
    };
}
