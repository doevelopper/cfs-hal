
#ifndef CFS_HAL_PERIPHERALREFCOUNTER_HPP
#define CFS_HAL_PERIPHERALREFCOUNTER_HPP

#include <array>
#include <cassert>

#include <cfs/hal/NonCopyable.hpp>

namespace cfs::hal
{
template<class Peripheral, std::size_t COUNT>
class PeripheralRefCounter : private NonCopyable<PeripheralRefCounter<Peripheral, COUNT>>
{
    protected:
        explicit PeripheralRefCounter(Peripheral& peripheral)
        {
            const std::int32_t index = getAvailableIndex(m_usedMask);
            assert(index >= 0);

            m_index = static_cast<std::size_t>(index);

            m_usedMask |= (1 << m_index);
            m_peripherals[m_index] = &peripheral;
        }

        ~PeripheralRefCounter()
        {
            m_usedMask &= ~(1 << m_index);
            m_peripherals[m_index] = nullptr;
        }

        std::size_t get_index() const
        {
            return m_index;
        }

        static Peripheral& reference(const std::size_t index)
        {
            assert(index < COUNT && m_peripherals[index] != nullptr);

            return *m_peripherals[index];
        }

        static Peripheral* pointer(const std::size_t index)
        {
            assert(index < COUNT);

            return m_peripherals[index];
        }

        static std::int32_t get_used()
        {
            // Count the number of bits set
            return __builtin_popcount(m_usedMask);
        }

    private:
        static constexpr std::int32_t getAvailableIndex(const std::uint32_t used_mask)
        {
            for(std::size_t p = 0; p < COUNT; ++p)
            {
                if((used_mask & (1 << p)) == 0)
                {
                    return p;
                }
            }

            return -1;
        }

        std::size_t m_index;
        static std::array<Peripheral*, COUNT> m_peripherals;
        static std::uint32_t m_usedMask;
};


// Static initialization
template <class Peripheral, std::size_t COUNT>
std::array<Peripheral*, COUNT> PeripheralRefCounter<Peripheral, COUNT>::m_peripherals 
{ nullptr };

template <class Peripheral, std::size_t COUNT>
std::uint32_t PeripheralRefCounter<Peripheral, COUNT>::m_usedMask
{ 0 };

}
#endif

