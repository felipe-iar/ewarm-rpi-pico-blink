# Raspberry PI Pico example project - Blink LED

This [IAR Embedded Workbench][url-iar-ewarm] project blinks the board's user LED.

## Debugger wiring connections
The table below considers the ARM20 connector.

| __ARM20 header__ | __Board pad__ |
| -                | -             |
| 1                | 3V3           |
| 4                | GND           |
| 7                | SWDIO         |
| 9                | SWCLK         |

>:warning: More information at: [developer.arm.com - Article KA001776][url-arm-cnx]

The debug probe used was the [IAR I-jet probe][url-iar-ijet] although other compatible probes can be used. If that's the case, change the probe in the project's __Options__ > __Debugger__ > __Setup__ > __Driver__, as well as any other wiring requirements, accordingly.

<!-- Links -->
[url-iar-ewarm]:https://iar.com/ewarm
[url-iar-ijet]: https://iar.com/ijet

[url-arm-cnx]:  https://developer.arm.com/documentation/ka001776/latest

