

#ifndef CFS_HAL_SYSFSGPIO_HPP
#define CFS_HAL_SYSFSGPIO_HPP

#include <sys/cdefs.h>
#include <sys/types.h>
#include <linux/gpio.h>

#include <string>
#include <fstream>
#include <memory>

namespace cfs::hal
{
    /*!
     * @defgroup Gpio Gpio Interface
     * @brief Functions to control GPIO pins.
     *        These functions can be used to control GPIO.
     * @{
     **/
    class SysFsGPIO
    {
        /*!
         * @brief Edge trigger types.
         */
        enum class GpioEdge : std::int8_t
        {
            GPIO_EDGE_NONE = 0,    /**<  None */
            GPIO_EDGE_RISING = 1,  /**<  Rising edge */
            GPIO_EDGE_FALLING = 2, /**<  Falling edge */
            GPIO_EDGE_BOTH = 3     /**<  Both edges */
        };
        /*!
         * @brief GPIO direction types.
         */
        enum class GpioDirection : std::int8_t
        {
            GPIO_DIRECTION_IN = 0,                 /**<  Input mode */
            GPIO_DIRECTION_OUT_INITIALLY_HIGH = 1, /**<  Output mode, initially high */
            GPIO_DIRECTION_OUT_INITIALLY_LOW = 2   /**<  Output mode, initially low */
        };
        /*
         * @brief GPIO Possible active types.
         */

        enum class GpioActiveType : std::int8_t
        {
            GPIO_ACTIVE_LOW = 0, /**<  Active Low */
            GPIO_ACTIVE_HIGH = 1 /**<  Active High */
        };
        /*!
         * @brief GPIO range parameters
         *       Used to set boundary for a GPIO device
         */
        struct gpioRange
        {
            std::int8_t min;    /**< Minimum GPIO number for a device */
            std::int8_t max;    /**< Maximum GPIO number for a device */
        };

        public:

            SysFsGPIO();
            /*!
             * @brief Construt an input or output GPIO object.
             * @param[in] id The GPIO ID. Often referred to as "pin number".
             * @param[in] direction  The type (INPUT or OUTPUT) of GPIO to construct.
             */
            SysFsGPIO( unsigned short id, GpioDirection direction);
            /*!
             * @brief Construt an input GPIO object which will call a callback function every time a
             *        transition of type edge occurs.
             * @param[in]   id    The GPIO ID. Often referred to as "pin number".
             * @param[in]   edge  The type (INPUT or OUTPUT) of GPIO to construct.
             * @param[in]   isr   The function to call when transitions of type edge occur.
             * @note If function isr throws an exception, IT WILL NOT BE HANDLED OR IGNORED BY THIS CLASS.
             *       Therefore, it is recommended to make this function noexcept.
             */
            SysFsGPIO(unsigned short id, GpioEdge edge, std::function<void(Value)> isr);
            SysFsGPIO(const SysFsGPIO& rsh) = delete;
            SysFsGPIO(SysFsGPIO&& rsh) = delete;
            SysFsGPIO & operator=(const SysFsGPIO& rsh) = delete;
            SysFsGPIO & operator=(SysFsGPIO && rsh) = delete;
            /*!
             * @brief
             * @warning Improper use can  will be left in an exported state which will prevent subsequent
             *     construction of a GPIO object with the same id.
             */
            virtual ~SysFsGPIO();

            /*!
             * @brief Sets the GPIO direction to output.
             * @param[in] direction One of DIRECTION_IN,
             *            DIRECTION_OUT_INITIALLY_HIGH,
             *            DIRECTION_OUT_INITIALLY_LOW.
             * @param[out] gpio
             * @retval  0: Success
             * @retval  n: errno Error
             *
             * This method does unbelievably useful things.
             * And returns exceptionally useful results.
             * Use it everyday with good health.
             */
            std::int8_t setDirection(const Gpio* gpio, GpioDirection direction);
            /*!
             * @brief Sets the interrupt edge trigger type.
             * @param[in] type One of NONE_EDGE,
             *            RISING_EDGE,
             *            FALLING_EDGE
             *            BOTH_EDGE.
             * @param[out] gpio
             * @retval  0: Success
             * @retval  n: errno Error
             */
            std::int8_t setEdgeTriggerType(const Gpio* gpio, GpioEdge type);
            /*!
             * @brief Sets the GPIO’s active low/high status.
             * @param[in] type One of ACTIVE_HIGH, ACTIVE_LOW.
             * @param[out] gpio
             * @retval  0: Success
             * @retval  n: errno Error
             */
            std::int8_t setActiveType(const Gpio* gpio, GpioActiveType type);
            /*!
             * @brief Sets the GPIO value (for output GPIO only).
             * @param[in] value Value to set.
             * @param[out] gpio
             * @retval  0: Success
             * @retval  n: errno Error
             */
            std::int8_t setValue(const Gpio* gpio, std::int8_t value);
            /*
             * @brief Gets the GPIO value (for input GPIO only).
             * @param[in]  value Output pointer to the value of the GPIO.
             * @param[out] gpio
             * @retval  0: Success
             * @retval  n: errno Error
             */
            std::int8_t getValue(const Gpio* gpio, std::int8_t * value);
            /*!
             * @brief Returns a file descriptor that can be used to poll on new data.
             *        Can be passed to select/epoll to wait for data to become available.
             * @param[out]  fd Output pointer to the file descriptor number.
             * @param[out] gpio
             * @retval  0: Success
             * @retval  n: errno Error
             */
            std::int8_t getPollingFd(const Gpio* gpio, std::int8_t * fd);
            /*!
             * @brief Acknowledges the interrupt and resets the file descriptor.
             *        This must be called after each event triggers in order to be able to
             *        poll/select for another event.
             * @param[in]  fd Polling file descriptor to reset.
             * @retval  0: Success
             * @retval  n: errno Error
             */
            std::int8_t ackInterruptEvent(std::int8_t fd);

            std::uint32_t operator()()
            {
                std::uint32_t r;

                //device->read(reinterpret_cast<char *>(&r), sizeof(std::uint32_t));
                return (r);
            }

        private:

            bool pinExists();
            void pinExport();
            void pinUnexport();

            std::int8_t m_fileDescriptor;
            Gpio & m_gpio;

            std::shared_ptr<std::fstream> m_value;
            std::shared_ptr<std::fstream> m_active;
            std::shared_ptr<std::fstream> m_direction;

            static const std::string SYSFS_CLASS_GPIO_EXPORT;
            static const std::string SYSFS_CLASS_GPIO_UNEXPORT;
            static const std::string PREFIX;
            static const std::string POSTFIX_VALUE;
            static const std::string POSTFIX_ACTIVE_LOW;
            static const std::string POSTFIX_DIRECTION;
    };
    /*!
     * @}
     */
}
#endif

