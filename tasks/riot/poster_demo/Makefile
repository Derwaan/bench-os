# name of your application
APPLICATION = poster_demo

# If no BOARD is found in the environment, use this default:
# BOARD ?= native
BOARD ?= remote-reva

# This has to be the absolute path to the RIOT base directory:
# RIOTBASE ?= $(CURDIR)/../RIOT
RIOTBASE ?= $(CURDIR)/../../../os/riot

# Uncomment this to enable scheduler statistics for ps:
#CFLAGS += -DSCHEDSTATISTICS

# Comment this out to disable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
#CFLAGS += -DDEVELHELP

# Change this to 0 show compiler invocation lines by default:
QUIET ?= 1

# Modules to include:
USEMODULE += gnrc_netdev_default
USEMODULE += auto_init_gnrc_netif
USEMODULE += gnrc_ipv6_default
USEMODULE += gnrc_sock_udp

# Use our benchmarking module & helpers
USEMODULE += periph_gpio_irq
USEMODULE += bench_context_switching

include $(RIOTBASE)/Makefile.include
