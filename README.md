# STM32F103 Bare-Metal LED Blink

A simple bare-metal STM32F103 LED blink project written in C without using STM32 HAL.

The project demonstrates:

- STM32F103 GPIO configuration
- RCC peripheral clock enable
- GPIO output using BSRR
- GPIO input/output register access
- CMSIS device headers
- ARM GCC toolchain
- Custom linker script
- Startup assembly
- Building an ELF firmware image
- Flashing through ST-LINK/SWD
- Command-line firmware development workflow

---

## Target Hardware

- MCU: STM32F103
- Core: ARM Cortex-M3
- Board: STM32 Blue Pill
- LED: PC13
- Programmer: ST-LINK/V2
- Debug interface: SWD

### ST-LINK Connections

| ST-LINK | STM32 Blue Pill |
|---------|------------------|
| SWDIO   | PA13             |
| SWCLK   | PA14             |
| GND     | GND              |
| 3.3V    | 3.3V             |
| NRST    | NRST             |

BOOT0 should be set to `0` for normal Flash boot.

---

## Project Structure

```text
STM32F103_BareMetal/
│
├── Application/
│   └── LED.c
│
├── BSP/
│
├── CMSIS/
│   ├── core_cm3.h
│   ├── cmsis_compiler.h
│   ├── cmsis_gcc.h
│   ├── cmsis_version.h
│   ├── stm32f103xb.h
│   ├── stm32f1xx.h
│   ├── system_stm32f1xx.c
│   └── system_stm32f1xx.h
│
├── Configuration/
│
├── Core/
│
├── Drivers/
│   ├── GPIO/
│   │   ├── GPIO.c
│   │   └── GPIO.h
│   │
│   └── RCC/
│       ├── RCC.c
│       └── RCC.h
│
├── Linker/
│   ├── startup_stm32f103xb.s
│   └── STM32F103XX_FLASH.ld
│
├── Startup/
├── Utilities/
│
└── README.md