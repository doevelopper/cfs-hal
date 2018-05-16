
#ifndef CFS_HAL_RPI_RPI_UART_HPP
#define CFS_HAL_RPI_RPI_UART_HPP

#include <cfs/hal/Uart.hpp>
#include <cfs/hal/FileDescriptor.hpp>

namespace cfs::hal
{
    namespace ::rpi
    {
        class RpiUART final : public Uart, public FileDescriptor
        {
        public:
            RpiUART () = delete;
            RpiUART (const std::string & device, const SerialConfig & config);
            RpiUART (const Uart& orig) = delete;
            RpiUART (RpiUART&& orig) = delete;
            RpiUART & operator=(const RpiUART & orig) = delete;
            RpiUART & operator=(RpiUART && orig) = delete;
            virtual ~RpiUART() = default;

            void setRts(int level);
            std::vector<std::uint8_t> receive(int size);
            void send(const std::vector<std::uint8_t> &buffer);

        };
    }

    std::unique_ptr<::Uart> openSerialPort(const std::string& device, const SerialConfig& config) 
    {
      return std::unique_ptr<Uart>(new RpiUART(device, config));
    }
}
#endif

