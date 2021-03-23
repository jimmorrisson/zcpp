#/bin/sh

openocd -f board/stm32f4discovery.cfg -c "program build/zcpp.hex verify reset exit"
