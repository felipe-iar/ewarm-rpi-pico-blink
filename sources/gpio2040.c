/*
  Copyright (c) 2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/

/*!
  \file    gpio2040.c
  \brief   Raspberry PI Pico board - basic IO control
  \version 20211125
*/

#include "gpio2040.h"

void gpio_oe_set(led_t led)
{
  SIO_GPIO_OE_SET = (1 << led);
}

void gpio_oe_clear(led_t led)
{
  SIO_GPIO_OE_CLR = (1 << led);
}

void gpio_set(led_t led)
{
  SIO_GPIO_OUT_SET = (1 << led);
}

void gpio_clear(led_t led)
{
  SIO_GPIO_OUT_CLR = (1 << led);
}

void gpio_toggle(led_t led)
{
  SIO_GPIO_OUT_XOR = (1 << led);
}

void gpio_init(led_t led)
{
  unsigned int r, f;

  /* Reset - GPIO */
  r = RESET_APPLY;
  r &= ~(RESET_IO_BANK0_MASK | RESET_IO_PADS_BANK0_MASK);
  RESET_APPLY = r;

  /* Set SIO alternate function (F5) */
  f = 0;
  f |= (SIO_GPIO_FSEL_F5);
  GPIOx_CTRL(led) = f;

  /* Clear pin state */
  gpio_oe_clear(led);
  gpio_clear(led);

  /* Set pin - initial state */
  gpio_oe_set(led);
  gpio_set(led);
}


