#!/bin/sh

openocd -f /usr/local/Cellar/open-ocd/0.11.0/share/openocd/scripts/interface/stlink-v2-1.cfg -f /usr/local/Cellar/open-ocd/0.11.0/share/openocd/scripts/board/stm32f4discovery.cfg -c "gdb_port 4242"
