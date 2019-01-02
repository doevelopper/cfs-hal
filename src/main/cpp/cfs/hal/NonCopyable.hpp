
#ifndef CFS_HL_NONCOPIABLE_HPP
#define CFS_HL_NONCOPIABLE_HPP

namespace cfs::hal
{
template<typename Type>
class NonCopyable
{
        // The template parameter 'Type' is the type that should be made non copyable.
        // It prevent cases where the empty base optimization cannot be applied and
        // therefore ensure zero cost while using this class.
    
    protected:

        // Prevent the use of this class as a final one (without being derived)
        NonCopyable()
        {}

        ~NonCopyable()
        {}

    private:

        // NonCopyable copy constructor
        NonCopyable(const NonCopyable&) = delete;

        // NonCopyable copy assignment operator
        NonCopyable& operator = (const NonCopyable&) = delete;
};

}

#endif

