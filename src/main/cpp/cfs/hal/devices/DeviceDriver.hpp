

namespace cfs::hal::devices
{
    class DeviceDriver
    {
        public:
            DeviceDriver(const stad::string name);
            ~DeviceDriver();

            virtual int	read(unsigned address, void *data, unsigned count) { return -ENODEV; }
            virtual int	write(unsigned address, void *data, unsigned count) { return -ENODEV; }

        	// no copy, assignment, move, move assignment
	        DeviceDriver(const DeviceDriver &) = delete;
        	DeviceDriver &operator=(const DeviceDriver &) = delete;
        	DeviceDriver(DeviceDriver &&) = delete;
        	DeviceDriver &operator=(DeviceDriver &&) = delete;

    };

}
