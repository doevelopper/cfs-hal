
#ifndef HMC5883L_HPP
#define HMC5883L_HPP

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

class Hmc5883l 
{
public:
    Hmc5883l();
    Hmc5883l(const Hmc5883l& orig) = default;
    Hmc5883l(Hmc5883l&& orig) = default;
    Hmc5883l & operator=(const Hmc5883l& orig) = default;
    Hmc5883l & operator=(Hmc5883l && orig) = default;
    virtual ~Hmc5883l() = default;
private:

};

#endif

