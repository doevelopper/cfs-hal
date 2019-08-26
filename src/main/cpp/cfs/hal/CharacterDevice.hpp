

#ifndef CFS_HAL_CHARACTERDEVICE_HPP
#define CFS_HAL_CHARACTERDEVICE_HPP

#include <string>
#include <chrono>
#include <ostream>
namespace cfs::hal
{
    class CharacterDevice
    {
        enum class Access : std::uint8_t
        {
            ReadOnly,
            WriteOnly,
            ReadWrite
        };

        public:

            CharacterDevice();
            CharacterDevice(const std::string& path, Access access);
            CharacterDevice(const CharacterDevice& orig) = default;
            CharacterDevice(CharacterDevice&& orig) = default;
            CharacterDevice & operator=(const CharacterDevice& orig) = default;
            CharacterDevice & operator=(CharacterDevice && orig) = default;
            virtual ~CharacterDevice() = default;

            bool poll(std::chrono::milliseconds timeout) const;
            void flush() const;
            unsigned int input() const;
            unsigned int output() const;

        private:
    };
}
#endif

