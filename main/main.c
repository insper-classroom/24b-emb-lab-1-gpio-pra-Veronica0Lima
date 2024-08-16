/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int A = 18;
const int B = 19;
const int C = 20;
const int D = 21;

const int BTN = 22;

int main()
{
  stdio_init_all();

    gpio_init(A);
    gpio_set_dir(A, GPIO_OUT);

    gpio_init(B);
    gpio_set_dir(B, GPIO_OUT);

    gpio_init(C);
    gpio_set_dir(C, GPIO_OUT);

    gpio_init(D);
    gpio_set_dir(D, GPIO_OUT);

    gpio_init(BTN);
    gpio_set_dir(BTN, GPIO_IN);
    gpio_pull_up(BTN);

  while (true)
  {
    if (!gpio_get(BTN))
    {
     for(int i = 0; i < 512; i++){
        gpio_put(A, 1);
        sleep_ms(10);
        gpio_put(A, 0);

        gpio_put(B, 1);
        sleep_ms(10);
        gpio_put(B, 0);

        gpio_put(C, 1);
        sleep_ms(10);
        gpio_put(C, 0);

        gpio_put(D, 1);
        sleep_ms(10);
        gpio_put(D, 0);
     }   
       
    }
  }
}
