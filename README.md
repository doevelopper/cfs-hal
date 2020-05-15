``` txt
 @@@@@@@  @@@@@@@@   @@@@@@      @@@  @@@   @@@@@@   @@@
@@@@@@@@  @@@@@@@@  @@@@@@@      @@@  @@@  @@@@@@@@  @@@
!@@       @@!       !@@          @@!  @@@  @@!  @@@  @@!
!@!       !@!       !@!          !@!  @!@  !@!  @!@  !@!
!@!       @!!!:!    !!@@!!       @!@!@!@!  @!@!@!@!  @!!
!!!       !!!!!:     !!@!!!      !!!@!!!!  !!!@!!!!  !!!
:!!       !!:            !:!     !!:  !!!  !!:  !!!  !!:
:!:       :!:           !:!      :!:  !:!  :!:  !:!   :!:
 ::: :::   ::       :::: ::      ::   :::  ::   :::   :: ::::
 :: :: :   :        :: : :        :   : :   :   : :  : :: : :

01000011 01000110 01010011  01001000 01000001 01001100
                    -- A.H.L --
```




Features

* GPIO managements
    1. Export & unexport GPIO pins
    2. Configure GPIO pin direction
    3. Configure GPIO pin edge detection
    4. Control/write GPIO pin states
    5. Pulse GPIO pin state
    6. Read GPIO pin states
    7. Listen for GPIO pin state changes (interrupt-based; not polling)
    8. Automatically set GPIO states on program termination (GPIO shutdown)
    9. Triggers for automation based on pin state changes
    10. Extensible GPIO Provider interface to add GPIO capacity via expansion boards
* Serial Communications
    - Send & receive data via RS232 serial communication
    - I2C Communication
    - SPI Communication
* Wrapper classes for direct access to access CPU, memory ....

