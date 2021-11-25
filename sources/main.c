/*
  Copyright (c) 2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/

/*!
  \file    main.c
  \brief   Blink the LED in the Raspberry PI Pico board
  \version 20211125
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "gpio2040.h"

void main(void)
{
  led_t pico = LED;

  gpio_init(pico);

  while(1)
  {
    for (uint32_t i = 0; i < 2040000; i++);

    printf(".*.\n");

    gpio_toggle(pico);
  }
}
