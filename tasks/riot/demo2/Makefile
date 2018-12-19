# name of your application
APPLICATION = Demo2

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
CFLAGS += -DDEVELHELP

# Change this to 0 show compiler invocation lines by default:
QUIET ?= 1

# Modules to include:
USEMODULE += shell
USEMODULE += shell_commands
USEMODULE += ps
USEMODULE += gnrc_netdev_default
USEMODULE += auto_init_gnrc_netif
USEMODULE += gnrc_ipv6_default
USEMODULE += gnrc_icmpv6_echo
USEMODULE += gnrc_sock_udp

# Use our benchmarking module & helpers
USEMODULE += periph_gpio_irq
USEMODULE += bench_context_switching
USEMODULE += xtimer

include $(RIOTBASE)/Makefile.include
