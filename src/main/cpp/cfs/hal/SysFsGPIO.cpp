
#include <cfs/hal/SysFsGPIO.hpp>

const std::string cfs::hal::SysFsGPIO::SYSFS_CLASS_GPIO_EXPORT        = "/sys/class/gpio/export";
const std::string cfs::hal::SysFsGPIO::SYSFS_CLASS_GPIO_UNEXPORT      = "/sys/class/gpio/unexport";
const std::string cfs::hal::SysFsGPIO::PREFIX                         = "/sys/class/gpio/cfsio";
const std::string cfs::hal::SysFsGPIO::POSTFIX_VALUE                  = "/value";
const std::string cfs::hal::SysFsGPIO::POSTFIX_DIRECTION              = "/direction";
const std::string cfs::hal::SysFsGPIO::POSTFIX_ACTIVE_LOW             = "/active_low";

cfs::hal::SysFsGPIO::SysFsGPIO()
  :  m_fileDescriptor(::open(PATH_EXPORT,O_WRONLY | O_NONBLOCK))
  ,  m_value(new std::fstream("/dev/urandom"))
  ,  m_active(new std::fstream("/dev/urandom"))
  ,  m_direction(new std::fstream("/dev/urandom"))
{
}

cfs::hal::SysFsGPIO::~SysFsGPIO() 
{
}

bool cfs::hal::SysFsGPIO::pinExists()
{
    
}

void cfs::hal::SysFsGPIO::pinExport()
{
    
}

void cfs::hal::SysFsGPIO::pinUnexport()
{
    
}
