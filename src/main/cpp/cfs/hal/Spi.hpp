
#ifndef CFS_HAL_SPI_HPP
#define CFS_HAL_SPI_HPP

#include <sys/cdefs.h>
#include <sys/types.h>

namespace cfs::hal
{
    /*!
    * @defgroup Spi Spi Interface
    * @brief Functions to control SPI pins.
    *        These functions can be used to control SPI.
    * @{
    **/
    
    class Spi 
    {
        /*!
        * @brief SPI chip select polarity.
        */
        enum class SpiCsPolarity
        {
            SPI_CS_POL_LOW = 0,
            SPI_CS_POL_HIGH = 1
        };

        /*!
        * @brief Endianness.
        */ 
        enum class SpiBitJustification : std::uint8_t
        {
            ASPI_LSB_FIRST = 0, /**< Least significant bits first */
            ASPI_MSB_FIRST = 1  /**< Most significant bits first */
        };
        /*!
        * @brief SPI modes (similar to the Linux kernel's modes).
        */ 
        enum SpiMode : std::uint8_t
        {
            SPI_DATA_MODE0 = 0, /**< CPHA=0, CPOL=0 */
            SPI_DATA_MODE1 = 1, /**< CPHA=1, CPOL=0 */
            SPI_DATA_MODE2 = 2, /**< CPHA=0, CPOL=1 */
            SPI_DATA_MODE3 = 3  /**< CPHA=1, CPOL=1 */
        };

        enum class bcm283x_spi_speed  : std::uint32_t
        {
            SPEED_4kHz = 0,
            SPEED_7kHz = 32768,
            SPEED_15kHz = 16384,
            SPEED_30kHz = 8192,
            SPEED_61kHz = 4096,
            SPEED_122kHz = 2048,
            SPEED_244kHz = 1024,
            SPEED_488kHz = 512,
            SPEED_976kHz = 256,
            SPEED_2MHz = 128,
            SPEED_4MHz = 64,
            SPEED_8MHz = 32,
            SPEED_15MHz = 16,
            SPEED_31MHz = 8,
            SPEED_62MHz = 4,
            SPEED_125MHz = 2
        };

    public:

        Spi();
        Spi(const Spi& orig) = default;
        Spi(Spi&& orig) = default;
        Spi & operator=(const Spi& orig) = default;
        Spi & operator=(Spi && orig) = default;
        virtual ~Spi() = default;
        
        /*
        * @brief Writes a buffer to the device.
        * @param[out] device Pointer to the ASpiDevice struct.
        * @param[out] data Buffer to write.
        * @param[in] len Length of the buffer.
        * @retval  0: Success
        * @retval  n: errno Error
        */
        int writeBuffer(const SpiDevice* device, const void* data, std::size_t len);

        /*!
        * @brief Reads a buffer from the device.
        * @param[out] device Pointer to the ASpiDevice struct.
        * @param[out] data Buffer to read into.
        * @param[in]  len Length of the buffer.
        * @retval  0: Success
        * @retval  n: errno Error
        */
        int readBuffer(const SpiDevice* device, void* data, std::size_t len);

        /*!
        * @brief Transfer data to the device.
        * @param[out] device Pointer to the ASpiDevice struct.
        * @param[out] tx_data Buffer to write.
        * @param[out] rx_data Buffer to read data in. If NULL, no data will be read.
        * @param[in] len Length of the buffers.
        * @retval  0: Success
        * @retval  n: errno Error
        */
        int transfer(const SpiDevice* device, const void* tx_data, void* rx_data, std::size_t len);
        /*!
        * @brief Sets the frequency in Hertz.
        * @param[out] device Pointer to the ASpiDevice struct.
        * @param[in] freq_hz Frequency to set.
        * @retval  0: Success
        * @retval  n: errno Error
        */
        int setFrequency(const SpiDevice* device, std::uint32_t freq_hz);

        /*!
        * @brief Sets the SPI mode.
        * @param[out] device Pointer to the ASpiDevice struct.
        * @param[in] mode Mode to use. One of SPI_MODE0, SPI_MODE1, SPI_MODE2, SPI_MODE3.
        * @retval  0: Success
        * @retval  n: errno Error
        */
        int setMode(const SpiDevice* device, SpiMode mode);

        /*!
        * @brief Sets the bit justification.
        * @param[out] device Pointer to the ASpiDevice struct.
        * @param[in]  bit_justification One of SPI_LSB_FIRST OR SPI_MSB_FIRST.
        * @retval  0: Success
        * @retval  n: errno Error
        */
        int setBitJustification(const SpiDevice* device, SpiBitJustification bit_justification);

        /*!
        * @brief Sets the number of bits per words.
        * @param[out]  device Pointer to the ASpiDevice struct.
        * @param[in]  bits_per_word Number of bits per word.
        * @retval  0: Success
        * @retval  n: errno Error
        */
        int setBitsPerWord(const SpiDevice* device, std::uint8_t bits_per_word);
        /*!
        * @brief Sets the delay to wait after each transfer.
        * @param[out] device Pointer to the ASpiDevice struct.
        * @param[in] delay_usecs Delay in microseconds.
        * @retval  0: Success
        * @retval  n: errno Error
        */
        int setDelay(const SpiDevice* device, std::uint16_t delay_usecs);
        /*!
        * @brief Sets the chip select behavior after each transfer.
        * @param[out] device Pointer to the ASpiDevice struct.
        * @param[in] change If set, cs will be active between transfers.
        * @retval  0: Success
        * @retval  n: errno Error
        */
        int setCsChange(const SpiDevice* device, std::uint32_t change);
        /*!
         * @}
         */ 

    private:

    };
}
#endif

