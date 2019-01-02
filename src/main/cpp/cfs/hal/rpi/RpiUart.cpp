

#include <cfs/hal/rpi/RpiUart.hpp>

using namespace cfs::hal::rpi;

/*RpiUART::RpiUART()
   {
   }
 */
RpiUART::~RpiUART()
{
}

/*
   void cfs::hal::rpi::RpiUART::setRts(int level)
   {
    int status = TIOCM_RTS;
    if (level)
    {
        if (ioctl(FileDescriptor::operator(), TIOCMBIS, &status) == -1)  // (*this)() i place of
                                                                         // FileDescriptor::operator()
        {
            // error while tuning on RTS
        }
    }
    else
    {
        if (ioctl(FileDescriptor::operator(), TIOCMBIC, &status) == -1)
        {
            // Eroro while turning off RTS
        }
    }
   }

   cfs::hal::rpi::RpiUART::RpiUART (const std::string & device, const SerialConfig & config)
    :  FileDescriptor(::open(device.c_str(), O_RDWR | O_NOCTTY))
   {
    termios options = {0};

    if (tcgetattr(FileDescriptor::operator(), &options) < 0)
    {
        // handle serial configuration failure
    }

    unsigned int posixBaud = 0;

    switch (config.baud_rate)
    {
    case 110:    posixBaud = B110;
    default:     throw std::runtime_error("UNSUPPORTED BAUD RATE");
    }

    cfsetispeed(&options, posixBaud);
    cfsetospeed(&options, posixBaud);
    cfmakeraw(&options);

    // resetting possibly set bits
    options.c_cflag &= ~(CSIZE | PARODD | CSTOPB);

    switch (config.parity)
    {
    case Parity::NONE:
        break;
    case Parity::EVEN:
        options.c_cflag |= PARENB;
        break;
    case Parity::ODD:
        options.c_cflag |= PARENB | PARODD;
        break;
    default: throw std::runtime_error("UNSUPPORTED PARITY");
    }


    switch (config.data_bits)
    {
    case 8:
        options.c_cflag |= CS8;
        break;
    case 7:
        options.c_cflag |= CS7 | CSTOPB;
        break;
    default: throw std::runtime_error("UNSUPPORTED DATA BITS");
    }

    if (tcsetattr(FileDescriptor::operator(), TCSANOW, &options) < 0)
    {
    }
   }

   cfs::hal::rpi::RpiUART::receive(int size)
   {
    int actualSize = 0;
    std::vector<std::uint8_t> data(size);

    for(;;)
    {
        struct pollfd poll_fd = {FileDescriptor::operator(), POLLIN};

        auto pollrc = poll(&poll_fd, 1, timeout_us / 1000L);

        if (!pollrc)
        {
            //timeout
        }

        if (pollrc < 0)
        {
            // error while reading data
        }

        if (poll_fd.revents != POLLIN)
        {
            //Serial pooling error condition
        }

        if(poll_fd.revents & POLLIN)
        {
            auto to_read = data.size() - actualSize;
            auto result = read(fd_, data.data() + actualSize, to_read);

            if (result == to_read)
            {
                return data;
            }
            actualSize += result;
        }
    }

    return data;
   }


   cfs::hal::rpi::RpiUART::send(const std::vector<uint8_t> &buffer)
   {
    auto res = write(FileDescriptor::operator(), buffer.data(), buffer.size());

    if (res < 0)
    {
        //handle write to serial failure
    }

    if (static_cast<decltype(buffer.size())>(res) != buffer.size())
    {
        //Not all data writtent
    }

    ::tcflush(FileDescriptor::operator(), TCIFLUSH);
   }
 */

