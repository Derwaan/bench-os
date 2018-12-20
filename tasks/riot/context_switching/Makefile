# Set the name of your application:
APPLICATION = context_switching

# If no BOARD is found in the environment, use this default:
# BOARD ?= nucleo-f401re
BOARD ?= native

# Use our benchmarking module
USEMODULE += bench_context_switching

USEMODULE += xtimer

# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= $(CURDIR)/../../../os/riot
include $(RIOTBASE)/Makefile.include