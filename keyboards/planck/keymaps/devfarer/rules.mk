ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif

SRC += muse.c
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
AUTO_SHIFT_ENABLE = yes
MOUSEKEY_ENABLE = yes
SPACE_CADET_ENABLE = yes
CAPS_WORD_ENABLE = yes
