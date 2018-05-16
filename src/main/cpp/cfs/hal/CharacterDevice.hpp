#ifndef CFS_HAL_CHARACTERDEVICE_HPP
#define CFS_HAL_CHARACTERDEVICE_HPP

namespace cfs::hal
{

    class CharacterDevice
    {
        enum class Access 
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
    private:
    };
}
#endif

