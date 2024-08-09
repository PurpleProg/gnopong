# ----------------------------
# Makefile Options
# ----------------------------

NAME = gnopong
ICON = icon.png
DESCRIPTION = "yin-yang pong"
COMPRESSED = NO

CFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
