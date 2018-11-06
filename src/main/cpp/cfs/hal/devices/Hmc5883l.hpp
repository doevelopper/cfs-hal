

#ifndef CFS_HAL_DEVICES_HMC5883L_HPP
#define CFS_HAL_DEVICES_HMC5883L_HPP

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

namespace cfs::hal::devices
{
    class Hmc5883l
    {
        public:

            Hmc5883l();
            Hmc5883l(const Hmc5883l& orig) = default;
            Hmc5883l(Hmc5883l&& orig) = default;
            Hmc5883l & operator=(const Hmc5883l& orig) = default;
            Hmc5883l & operator=(Hmc5883l && orig) = default;
            virtual ~Hmc5883l();

        private:
    };
}
#endif

