
#ifndef CFS_HAL_I2S_HPP
#define CFS_HAL_I2S_HPP

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
    class I2s 
    {
        /*!
         * @brief Edge trigger types.
         */ 
        enum class I2sEncoding : std::int8_t  
        {
            AI2S_ENCODING_PCM_8_BIT,
            AI2S_ENCODING_PCM_16_BIT,
            AI2S_ENCODING_PCM_24_BIT,
            AI2S_ENCODING_PCM_32_BIT
        };
        /*!
         * @brief Flags to specify I2s bus direction.
         */ 
        enum class I2sFlags : std::uint8_t
        {
            AI2S_FLAG_DIRECTION_IN = 1 << 0,
            AI2S_FLAG_DIRECTION_OUT = 1 << 1
        };

    public:

        I2s();
        I2s(const I2s& orig) = default;
        I2s(I2s&& orig) = default;
        I2s & operator=(const I2s& orig) = default;
        I2s & operator=(I2s && orig) = default;
        virtual ~I2s() = default;

        /*!
        * @brief Writes raw data to the I2S device. Multi-channel audio data is interleaved.
        * @param[out] i2s Pointer to the AI2s struct.
        * @param[out]  data Data to write.
        * @param[in] offset Offset to first byte in data.
        * @param[in] size Number of bytes to write.
        * @param[out] bytes_written Number of bytes written.
        * @retval  0: Success
        * @retval  n: errno Error
        */
        int write(const I2sDevice* i2s, const void* data, int offset, int size, int * bytes_written);
        /*!
        * @brief Reads raw data from the I2S device. Multi-channel audio data is interleaved.
        * @param[out] i2s Pointer to the AI2s struct.
        * @param[out] data Buffer to fill with data read.
        * @param[in] offset Offset to first byte in data.
        * @param[in] size Number of bytes to read.
        * @param[out] bytes_read Number of bytes read.
        * @retval  0: Success
        * @retval  n: errno Error
        */
        int read( const I2sDevice* i2s, void* data, int offset, int size, int* bytes_read);
        /*
        * @brief Gets the timestamp when a specific sample entered the kernel.
        * @param[out] i2s Pointer to the AI2s struct.
        * @param[out] frame_position Output indicating number of frames read.
        * @param[out] nano_time Output indicating time (ns) when the frame was read.
        * @param[out] success Output indicating success (1) or failure (0).
        * @retval  0: Success
        * @retval  n: errno Error
        *          This will only be nonzero on a fatal
        *          error such as the I2S device couldn't be found; in the normal case
        *          that a timestamp isn't available the success param will be used.  
        */
        int getInputTimestamp(const I2sDevice* i2s, int64_t* frame_position, int64_t* nano_time, int* success);
        /*!
        * @brief Gets the timestamp when a specific sample exited the kernel.
        * @param[out] i2s Pointer to the AI2s struct.
        * @param[out] frame_position Output indicating number of frames written.
        * @param[out] nano_time Output indicating time (ns) when the frame was written.
        * @param[in] success Output indicating success (1) or failure (0).
        * @retval  0: Success
        * @retval  n: errno Error
        *          This will only be nonzero on a fatal
        *          error such as the I2S device couldn't be found; in the normal case
        *          that a timestamp isn't available the success param will be used.  
        */
        int getOutputTimestamp(const I2sDevice* i2s, int64_t* frame_position, int64_t* nano_time, int * success);

    private:

    };
    /*!
     * @}
     */
}
#endif

