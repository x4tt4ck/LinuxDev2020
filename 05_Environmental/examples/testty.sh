#!/bin/sh
test "`./KeyScan < /dev/null 2>&1`" = "./KeyScan: Not a tty"
