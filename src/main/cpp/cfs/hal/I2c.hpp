#ifndef CFS_HAL_I2C_HPP
#define CFS_HAL_I2C_HPP

#include <linux/i2c.h>
#include <linux/i2c-dev.h>

namespace cfs::hal
{
    /*!
    * @defgroup I2c I2c device interface
    * @brief Functions to control an I2C device.
    *        These functions can be used to control GPIO.
    * @{
    */
    class I2c 
    {

    public:

        I2c();
        I2c(const I2c& orig) = default;
        I2c(I2c&& orig) = default;
        I2c & operator=(const I2c& orig) = default;
        I2c & operator=(I2c && orig) = default;
        virtual ~I2c() = default;
        /*!
        * @brief Reads from the device.
        * @param[out] data Output buffer to write the data to.
        * @param[in] len Number of bytes to read. 
        * @param[out] device
        * @retval  0: Success
        * @retval  n: errno Error
        */
        std::int8_t read(const I2cDevice* device, void* data, std::int32_t len);
        /*!
        * @brief Reads a byte from an I2C register.
        * @param[in] reg Register to read from.
        * @param[in] val Output pointer to value to read.
        * @param[out] device
        * @retval  0: Success
        * @retval  n: errno Error
        */
        std::int8_t readRegisterByte(const I2cDevice * device,  std::uint8_t reg, std::uint8_t * val);
        /*!
        * @brief  Reads a word from an I2C register.
        * @param[in] reg Register to read from.
        * @param[in] val Output pointer to value to read.
        * @param[out] device
        * @retval  0: Success
        * @retval  n: errno Error
        */
        std::int8_t readRegisterWord(const I2cDevice* device, std::uint8_t reg, std::uint16_t * val);
        /*!
        * @brief Reads from an I2C register.
        * @param[in] reg Register to read from.
        * @param[out] data Output buffer to write the data to.
        * @param[in] len Number of bytes to read.
        * @param[out] device
        * @retval  0: Success
        * @retval  n: errno Error
        */
        std::int8_t readRegisterBuffer(const I2cDevice* device, std::uint8_t reg, void* data, std::uint32_t len);
        /*!
        * @brief Writes to the device.
        * @param[in] reg Register to read from.
        * @param[out] data Buffer to write.
        * @param[in] len Number of bytes to write.
        * @param[out] device
        * @retval  0: Success
        * @retval  n: errno Error
        */
        std::int8_t write(const I2cDevice* device, std::uint8_t reg, void* data, std::uint32_t len);
        /*!
        * @brief Writes a byte to an I2C register.
        * @param[in] reg Register to write to.
        * @param[in]  val Value to write.
        * @param[out] device
        * @retval  0: Success
        * @retval  n: errno Error
        */
        std::int8_t writeRegisterByte(const I2cDevice* device, std::uint8_t reg, std::uint8_t val);
        /*!
        * @brief Writes a word to an I2C register.
        * @param[out] device 
        * @param[in] reg Register to write to.
        * @param[in] val Value to write.
        * @retval  0: Success
        * @retval  n: errno Error
        */
        std::uint8_t writeRegisterWord(const I2cDevice* device, std::uint8_t reg, std::uint16_t val);
        /*!
        * @brief Writes to an I2C register.
        * @param[out] device Pointer to the I2cDevice struct.
        * @param[in] reg Register to write to.
        * @param[out] data Data to write.
        * @param[in] len Number of bytes to write.
        * @retval  0: Success
        * @retval  n: errno Error
        */
        std::uint8_t writeRegBuffer(const I2cDevice* device, std::uint8_t reg, const void* data, std::uint32_t len);

    private:

    };
    /*!
     * @}
     */ 
};

#endif

