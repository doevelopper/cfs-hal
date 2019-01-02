#ifndef CFS_HAL_IMPLCHECK_HPP
#define CFS_HAL_IMPLCHECK_HPP

#include <type_traits>

namespace cfs::hal
{
	template <typename...>
	class InheritsFrom;

	template <typename Derived, typename F, typename... R>
	class InheritsFrom<Derived, F, R...> 
	: public InheritsFrom<Derived, R...>
	{
		static_assert(std::is_base_of<F, Derived>::value,
		"Implementation does not satisfy all interfaces");
	};

	template <typename Derived>
	class InheritsFrom<Derived> {};
}

#endif

