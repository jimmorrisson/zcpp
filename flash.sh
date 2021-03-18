#/bin/sh

openocd -f board/stm32f4discovery.cfg -c "program build/DiscoveryBlinky.hex verify reset exit"