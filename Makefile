# Firmware name
NAME=main

# Options for specific architecture
ARCH_FLAGS=-mthumb -mcpu=cortex-m3

# Options for specific architecture

# Compiler & Linker
ARCH=arm-none-eabi
CC=$(ARCH)-gcc
OBJCOPY=$(ARCH)-objcopy

# -Os -flto -ffunction-sections -fdata-sections to compile for code size
CFLAGS=$(ARCH_FLAGS) $(STARTUP_DEFS) -Os -flto -ffunction-sections -fdata-sections

# Create map file
MAP=-Wl,-Map=$(NAME).map

# Startup code
STARTUP=startup_ARMCM3.S
STARTUP_DEFS=-D__STARTUP_CLEAR_BSS -D__START=main

# Linker script (Link for code size)
GC=-Wl,--gc-sections
LDSCRIPTS=-L. -T nokeep.ld
LFLAGS=$(LDSCRIPTS) $(GC) $(MAP)

$(NAME).bin: $(NAME).elf
	$(OBJCOPY) -O binary $(NAME).elf $(NAME).bin

$(NAME).elf: $(NAME).c $(STARTUP)
	$(CC) $^ $(CFLAGS) $(LFLAGS) -o $@

flash: $(NAME).bin
	st-flash erase
	st-flash write $(NAME).bin 0x08000000

clean: 
	rm -f *.elf *.map *.o *.bin
