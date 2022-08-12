# eng <ahmed>
cc= arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2
INCS = -I .
LIBS =
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
As_OBJ = $(As:.s=.o)
PROJECT_NAME=learn-in-depth-cortexm3
all: $(PROJECT_NAME).bin
	@echo "---------all is done--------"
startup.o: startup.s
	$(cc)as.exe  $(CFLAGS) $(INCS) $< -o $@
%.o: %.c
	$(cc)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

$(PROJECT_NAME).elf: $(OBJ) $(As_OBJ)
	$(cc)ld.exe -T  linker_script.ld $(LIBS) $(OBJ) $(As_OBJ) -o $@ -Map=map_file.map
$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	$(cc)objcopy.exe -O binary $< $@
clean_all:
	rm *.o *.bin *.elf

clean:
	rm *.bin *.elf