################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include COTS/MCAL/DIO/subdir.mk
-include COTS/HAL/SevenSegment/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
SEVSEG_APP.lss \

FLASH_IMAGE += \
SEVSEG_APP.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: SEVSEG_APP.elf secondary-outputs

# Tool invocations
SEVSEG_APP.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SEVSEG_APP.map -mmcu=atmega32 -o "SEVSEG_APP.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SEVSEG_APP.lss: SEVSEG_APP.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SEVSEG_APP.elf  >"SEVSEG_APP.lss"
	@echo 'Finished building: $@'
	@echo ' '

SEVSEG_APP.hex: SEVSEG_APP.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SEVSEG_APP.elf  "SEVSEG_APP.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SEVSEG_APP.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SEVSEG_APP.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SEVSEG_APP.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
