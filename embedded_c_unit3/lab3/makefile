# eng <ahmed>
cc= arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -gdwarf-2 -g
INCS = -I .
LIBS =
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
As_OBJ = $(As:.s=.o)
PROJECT_NAME=learn-in-depth-cortex_m4
all: $(PROJECT_NAME).bin
	@echo "---------all is done--------"

%.o: %.c
	$(cc)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

$(PROJECT_NAME).elf: $(OBJ) $(As_OBJ)
	$(cc)ld.exe -T  linker_script.ld $(LIBS) $(OBJ) $(As_OBJ) -o $@ -Map=map_file.map
	#copy elf to axf to debug with kiel 
	cp $(PROJECT_NAME).elf $(PROJECT_NAME).axf
$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	$(cc)objcopy.exe -O binary $< $@
clean_all:
	rm *.o *.bin *.elf

clean:
	rm *.bin *.elf