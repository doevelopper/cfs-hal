

#ifndef CFS_HAL_UART_HPP
#define CFS_HAL_UART_HPP

#include <cstdlib>
#include <cstdint>
#include <cstring>

#include <chrono>
#include <ostream>
#include <string>

#include <sys/cdefs.h>
#include <sys/types.h>

namespace cfs::hal
{
    /*!
     * @brief The SerialConfig struct for serial attributes
     */
    struct UartConfig
    {
        int baud_rate;
        int data_bits;
        ::UartParity parity;
        int timeout_value_in_usec;
    };

    /*!
     * @defgroup Uart Uart device interface
     * @brief Functions to control an UART device.
     *        These functions can be used to control an UART device.
     *
     * @{
     */
    class Uart
    {
        enum class UartBaudRate : std::uint8_t
        {
            BAUDRATE_110BPS,
            BAUDRATE_300BPS,
            BAUDRATE_600BPS,
            BAUDRATE_1200BPS,
            BAUDRATE_2400BPS,
            BAUDRATE_4800BPS,
            BAUDRATE_9600BPS,
            BAUDRATE_19200BPS,
            BAUDRATE_38400BPS,
            BAUDRATE_57600BPS,
            BAUDRATE_115200BPS,
            BAUDRATE_230400BPS,
            BAUDRATE_460800BPS,
            BAUDRATE_500000BPS,
            BAUDRATE_576000BPS,
            BAUDRATE_921600BPS,
            BAUDRATE_1000000BPS,
            BAUDRATE_1152000BPS,
            BAUDRATE_1500000BPS,
        };

        enum class UartStopBits : std::uint8_t
        {
            STOPBITS_1BIT,
            STOPBITS_2BITS
        };

        enum class UartDataBits : std::uint8_t
        {
            DATABITS_5BITS,
            DATABITS_6BITS,
            DATABITS_7BITS,
            DATABITS_8BITS
        };

        /*!
         * UART Parity
         */
        enum class UartParity : std::uint8_t
        {
            AUART_PARITY_NONE = 0, /**< No parity */
            AUART_PARITY_EVEN = 1, /**< Even parity */
            AUART_PARITY_ODD = 2,  /**< Odd parity */
            AUART_PARITY_MARK = 3, /**< Mark parity, always 1 */
            AUART_PARITY_SPACE = 4 /**< Space parity, always 0 */
        };
        /*!
         * Modem control lines.
         */
        enum class UartModemControlLine : std::uint8_t
        {
            AUART_MODEM_CONTROL_LE = 1 << 0,      /**< Data set ready/Line enable */
                AUART_MODEM_CONTROL_DTR = 1 << 1, /**< Data terminal ready */
                AUART_MODEM_CONTROL_RTS = 1 << 2, /**< Request to send */
                AUART_MODEM_CONTROL_ST = 1 << 3,  /**< Secondary TXD */
                AUART_MODEM_CONTROL_SR = 1 << 4,  /**< Secondary RXD */
                AUART_MODEM_CONTROL_CTS = 1 << 5, /**< Clear to send */
                AUART_MODEM_CONTROL_CD = 1 << 6,  /**< Data carrier detect */
                AUART_MODEM_CONTROL_RI = 1 << 7,  /**< Ring */
                AUART_MODEM_CONTROL_DSR = 1 << 8  /**< Data set ready */
        };
        /*!
         * Hardware Flow Control
         */
        enum class UartHardwareFlowControl : std::uint8_t
        {
            AUART_HARDWARE_FLOW_CONTROL_NONE = 0,                                                 /**< No hardware flow
                                                                                                     control */
            AUART_HARDWARE_FLOW_CONTROL_AUTO_RTSCTS = 1                                           /**< Auto RTS/CTS */
                                                      AUART_HARDWARE_FLOW_CONTROL_XONXOFF         /** Software flow
                                                                                                     control (XON/XOFF).
                                                                                                   */
                                                      AUART_HARDWARE_FLOW_CONTROL_RTSCTS_XONXOFF, /** Hardware flow
                                                                                                     control (RTS/CTS).
                                                                                                   */
        };
        /*!
         * Flush queue selection
         */

        enum class UartFlushDirection : std::uint8_t
        {
            AUART_FLUSH_IN = 0,    /**< Flushes data received but not read */
            AUART_FLUSH_OUT = 1,   /**< Flushes data written but not transmitted */
            AUART_FLUSH_IN_OUT = 2 /**< Flushes both in and out */
        };

        public:

            Uart();
            Uart(const std::string & filename,
                 const UartUartBaudRate & baudRate = BAUDRATE_9600BPS,
                 const UartDataBits & dataBits = DATABITS_8BITS,
                 const UartHardwareFlowControl & flowControl = FLOWCONTROL_OFF,
                 const UartParity & parity = AUART_PARITY_NONE,
                 const UartStopBits & stopBits = STOPBITS_1BIT,
                 const int& flags = O_RDWR | O_NONBLOCK | O_NOCTTY);
            Uart(const std::string& path, std::uint32_t baudrate, UartDataBits databits, UartParity parity, UartStopBits
                 stopbits, UartHardwareFlowControl handshake);
            Uart(const std::string& path, std::uint32_t baudrate, UartDataBits databits, UartParity parity, UartStopBits
                 stopbits);
            Uart(const std::string& path, std::uint32_t baudrate);
            Uart(const Uart& orig) = delete;
            Uart(Uart&& orig) = delete;
            Uart & operator=(const Uart& orig) = delete;
            Uart & operator=(Uart && orig) = delete;
            virtual ~Uart() = default;
            /*!
             * @brief Receive : Read data on serial bus
             * @param size : amount of data to be read
             * @return : array of data read
             */
            virtual std::vector<std::uint8_t> receive(int size) = 0;

            /*!
             * @brief Send : write data on serial bus
             * @param buffer : buffer to be written
             * @param size : size of data to be written
             */
            virtual void send(const std::vector<std::uint8_t> & buffer) = 0;

            /*!
             * @brief SetRts : allow user to set rts
             * @param level : 0 to disable rts , 1 to enable rts
             */
            virtual void setRts(int level) = 0;
            /*!
             * @brief Writes to a UART device.
             * @param[out] device Pointer to the AUartDevice struct.
             * @param[out] data Data to write.
             * @param[in] len Size of the data to write.
             * @param[in] bytes_written Output pointer to the number of bytes written.
             * @retval  0: Success
             * @retval  n: errno Error
             */
            int write(const UartDevice* device, const void* data, std::uint32_t len, std::uint32_t* bytes_written);


            /*!
             * @brief Reads from a UART device.
             * @param[out] device Pointer to the AUartDevice struct.
             * @param[out] data Buffer to read the data into.
             * @param[in] len Number of bytes to read.
             * @param[out] bytes_read Output pointer to the number of bytes read.
             * @retval  0: Success
             * @retval  n: errno Error
             */
            int read(const UartDevice* device, void* data, std::uint32_t len, std::uint32_t* bytes_read);
            /*!
             * @brief Sets the input and output speed of a UART device.
             * @param[out] device Pointer to the AUartDevice struct.
             * @param[int] baudrate Speed in baud.
             * @retval  0: Success
             * @retval  n: errno Error
             */
            int setBaudrate(const UartDevice* device, std::uint32_t baudrate);
            /*!
             * @brief Sets number of stop bits for the UART device.
             * @param[out]device Pointer to the AUartDevice struct.
             * @param[in] stop_bits Number of stop bits. Typically 1 or 2.
             * @retval  0: Success
             * @retval  n: errno Error
             */
            int setStopBits(const UartDevice* device, std::uint32_t stop_bits);
            /*!
             * @brief Sets the data size of a character for the UART device.
             * @param[out] device Pointer to the AUartDevice struct.
             * @param[in] data_size Number of bits per character. Typically between 5 and 8.
             * @retval  0: Success
             * @retval  n: errno Error
             */
            int setDataSize(const UartDevice* device, std::uint32_t data_size);
            /*!
             * @brief Sets the parity mode for the UART device.
             * @param[out] device Pointer to the AUartDevice struct.
             * @param[out] mode Parity mode.
             * @retval  0: Success
             * @retval  n: errno Error
             */
            int setParity(const UartDevice* device, UartParity mode);
            /*!
             * @brief Sets the hardware flow control mode for the UART device.
             * @param[out] device Pointer to the AUartDevice struct.
             * @param[in] mode Flow control mode.
             * @retval  0: Success
             * @retval  n: errno Error
             */
            int setHardwareFlowControl(const UartDevice* device, UartHardwareFlowControl mode);
            /*!
             * @brief Sets the modem control bits for the UART device.
             * @param[out] device Pointer to the UartDevice struct.
             * @param[inn] lines Lines to set. AUartModemControlLine values OR'ed together.
             * @retval  0: Success
             * @retval  n: errno Error
             */
            int setModemControl(const AUartDevice* device, std::uint32_t lines);
            /*!
             * @brief Clears the modem control bits for the UART device.
             * @param[out] device Pointer to the UartDevice struct.
             * @param[in] lines Lines to clear. UartModemControlLine values OR'ed together.
             * @retval  0: Success
             * @retval  n: errno Error
             */
            int clearModemControl(const UartDevice* device, std::uint32_t lines);
            /*!
             * @brief Sends a break to the UART device.
             * @param[out] device Pointer to the AUartDevice struct.
             * @param[in] duration Duration of break transmission in milliseconds. If 0,
             *            transmits zero-valued bits for at least 0.25 seconds, and not more
             *            than 0.5 seconds.
             * @retval  0: Success
             * @retval  n: errno Error
             */
            int sendBreak(const UartDevice* device, std::uint32_t duration_msecs);
            /*!
             * @brief Flushes specified queue for the UART device.
             * @param[out] device Pointer to the AUartDevice struct.
             * @param[in] direction Direction to flush.
             * @retval  0: Success
             * @retval  n: errno Error
             */
            int flush(const UartDevice* device, UartFlushDirection direction);
            /*!
             * @brief Gets a file descriptor to be notified when data can be read.
             *        You can use this file descriptor to poll on incoming data instead of
             *        actively reading for new data.
             * @param[out] device Pointer to the AUartDevice struct.
             * @param[out] fd Output pointer to the file descriptor.
             * @retval  0: Success
             * @retval  n: errno Error
             */
            int getPollingFd(const UartDevice* device, std::uint8_t * fd);

            /*!
             * @brief Acknowledges an input event.
             *        This must be called after receiving an event notification on the polling
             *        descriptor.
             *        If you don't acknowledge an event, peripheral manager will assume you are
             *        still processing it and you will not receive any more events.
             *        If you acknowledge an event before reading the data from the device, you
             *        will receive an event immediately as there will still be data available.
             *
             * @param[in] fd File descriptor to acknowledge the event on.
             * @retval  0: Success
             * @retval  n: errno Error
             */
            int ackInputEvent(std::uint8_t fd);

        private:

            UartStopBits m_stopBits;
            struct termios m_current;
            std::string m_filename;
            std::int8_t m_flags;
            UartHardwareFlowControl m_flowControl;
            UartParity m_parity;
            UartDataBits m_dataBits;
            struct termios m_restore;
            std::uint32_t m_fd;
    };
    /*
     * @}
     */

    /*!
     * @brief OpenSerialPort : Returns the serial connection
     * @param device : port of the device e.g. /dev/ttyUSB0, \\\\.\\COM8
     * @param config SerialConfig struct for serial attributes
     * @return pointer to the SerialConnection
     */
    std::unique_ptr<Uart> openSerialPort(const std::string & device, const UartConfig& config);
}
#endif

