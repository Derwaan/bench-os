# name of your application
APPLICATION = button-hello

# If no BOARD is found in the environment, use this default:
BOARD ?= nucleo-f401re

# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= $(CURDIR)/../../../os/riot/

# Comment this out to disable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
DEVELHELP ?= 1

FEATURES_REQUIRED += periph_gpio_irq

# Change this to 0 show compiler invocation lines by default:
QUIET ?= 1

include $(RIOTBASE)/Makefile.include
