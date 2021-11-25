/*
  Copyright (c) 2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/

/*!
  \file    gpio2040.h
  \brief   Raspberry PI Pico board - basic IO control header
  \version 20211125
*/

#ifndef _GPIO2040_H
#define _GPIO2040_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  LED = 25,
} led_t;

#define RESET_BASE_ADDR                (0x4000C000)
#define RESET_APPLY                    (*(volatile unsigned int*)(RESET_BASE_ADDR + 0x00u))

#define RESET_IO_BANK0_MASK            (1 << 5)
#define RESET_IO_PADS_BANK0_MASK       (1 << 8)

#define GPIO_BASE_ADDR                 (0x40014000)
#define GPIOx_STATUS(x)                (*(volatile unsigned int*)(GPIO_BASE_ADDR + (x * 8u) + 0x00u))
#define GPIOx_CTRL(x)                  (*(volatile unsigned int*)(GPIO_BASE_ADDR + (x * 8u) + 0x04u))

#define PAD_BASE_ADDR                  (0x4001C000)
#define PAD_GPIOx_CTRL(x)              (*(volatile unsigned int*)(PAD_BASE_ADDR + 0x04u + (x * 4u)))

#define SIO_BASE_ADDR                  (0xD0000000)
#define SIO_GPIO_OUT                   (*(volatile unsigned int*)(SIO_BASE_ADDR + 0x10u))
#define SIO_GPIO_OUT_SET               (*(volatile unsigned int*)(SIO_BASE_ADDR + 0x14u))
#define SIO_GPIO_OUT_CLR               (*(volatile unsigned int*)(SIO_BASE_ADDR + 0x18u))
#define SIO_GPIO_OUT_XOR               (*(volatile unsigned int*)(SIO_BASE_ADDR + 0x1Cu))
#define SIO_GPIO_OE                    (*(volatile unsigned int*)(SIO_BASE_ADDR + 0x20u))
#define SIO_GPIO_OE_SET                (*(volatile unsigned int*)(SIO_BASE_ADDR + 0x24u))
#define SIO_GPIO_OE_CLR                (*(volatile unsigned int*)(SIO_BASE_ADDR + 0x28u))
#define SIO_GPIO_OE_XOR                (*(volatile unsigned int*)(SIO_BASE_ADDR + 0x2Cu))

#define SIO_GPIO_FSEL_F5               (5u)

void gpio_oe_set                       (led_t);
void gpio_oe_clear                     (led_t);
void gpio_set                          (led_t);
void gpio_clear                        (led_t);
void gpio_toggle                       (led_t);
void gpio_init                         (led_t);

#ifdef __cplusplus
}
#endif

#endif  // GPIO2040_H
