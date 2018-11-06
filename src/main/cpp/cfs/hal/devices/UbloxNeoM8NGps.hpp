

#ifndef CFS_HAL_DEVICES_UBLOXNEOM8NGPS_HPP
#define CFS_HAL_DEVICES_UBLOXNEOM8NGPS_HPP

class UbloxNeoM8NGps
{
    public:

        UbloxNeoM8NGps();
        UbloxNeoM8NGps(const UbloxNeoM8NGps& orig) = default;
        UbloxNeoM8NGps(UbloxNeoM8NGps&& orig) = default;
        UbloxNeoM8NGps & operator=(const UbloxNeoM8NGps& orig) = default;
        UbloxNeoM8NGps & operator=(UbloxNeoM8NGps && orig) = default;
        virtual ~UbloxNeoM8NGps();

    private:
};

#endif

