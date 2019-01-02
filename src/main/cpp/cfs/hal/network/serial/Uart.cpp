

#include <cfs/hal/network/serial/Uart.hpp>

using namespace cfs::hal::network::serial;

Uart::Uart(const std::string & filename,
           const UartBaudRate & baudRate,
           const UartDataBits & dataBits,
           const UartHardwareFlowControl & flowControl,
           const UartParity & parity,
           const UartStopBits & stopBits,
           const std::int8_t & flags)
    : m_stopBits(stopBits)
    ,m_filename(filename)
    ,m_flags(flags)
    ,m_flowControl(flowControl)
    ,m_parity(parity)
    ,m_dataBits(dataBits)
    ,m_restore()
    ,m_current()
    ,m_filed(-1)

{
}

Uart::~Uart()
{
}

