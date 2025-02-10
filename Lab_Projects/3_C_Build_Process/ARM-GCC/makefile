CC = arm-none-eabi-
CFLAGS = -mcpu=cortex-m4 -mthumb -g
INCS=-I .
SRC= $(wildcard *.c)
SRCOBJ= $(SRC:.c=.o)
ASM= $(wildcard *.s)
ASMOBJ= $(ASM:.s=.o)
Project-name= ARM-GCC
LDFLAGS = -T tm4c123gh6pm.ld -nostartfiles

all: $(Project-name).bin
	@echo "========================================Build is Done========================================"

startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c $< -o $@

$(Project-name).elf: $(SRCOBJ) $(ASMOBJ)
	$(CC)ld.exe $(LDFLAGS) -Map=Map_file.map $(SRCOBJ) $(ASMOBJ) -o $@

$(Project-name).bin: $(Project-name).elf
	$(CC)objcopy.exe -O binary $< $@

clean-all:
	rm *.o *.elf *.bin *.map

clean:
	rm *.elf *.bin *.map