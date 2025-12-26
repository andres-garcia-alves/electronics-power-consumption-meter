# Electronics Power Consumption Meter

A power consumption meter based on Arduino Nano.  
This project is a **work-in-progress**.

&nbsp;

This project use the following electronic components:
-  1 x Double sided copper clad board (10x11cms)
-  1 x Arduino UNO / Nano v3
-  1 x INA219 module
-  1 x 3461BS-1 7-segment display (4 digit, common anode)
-  3 x LED diodes
- 11 x 470 ohm resistors
-  1 x On/Off Button (optional)
-  1 x Switch Button (power selector)
-  1 x Push Button (measure selector)
-  1 x 18650 Batery x2 holder / 1 x 9V Batery holder
-  1 x DC conector (optional, externar power 5-12V)
-  1 x USB Type-A conector pair (male/female)
-  1 x USB Type-B Mini conector pair (male/female)
-  1 x USB Type-B Micro conector pair (male/female)
-  2 x DC conector-pair (male/female)
-  1 x Bornier 4-pin
-  4 x Bornier 2-pin

&nbsp;

How to use:
- Conect this gadget between the device to measure and its power source.
- Pressing the push-button changes the measure tu display: voltage (V), consumption (mA), or total power (W).

Features:
- Input: 7-12V
- Measurements: 0-26V @3.2A (max), accuracy: ~1mA

Notes:
- Measure only one device at a time, all power connectors intenally uses a common bus.

&nbsp;

### Screenshots

| Breadboard                                      | Assembly                                        |
|-------------------------------------------------|-------------------------------------------------|
| ![](Resources/01-breadboard-03.jpg)             | ![](Resources/02-assembly.jpg)                  |

| Schematics Diagram (ver. A)                     | PCB Diagram (ver. A)                            |
|-------------------------------------------------|-------------------------------------------------|
| ![](Resources/03-schematics-diagram.png)        | ![](Resources/04-pcb-diagram.png)               |

| PCB Render 3D (ver. A)                          | PCB Render 3D (ver. A)                          |
|-------------------------------------------------|-------------------------------------------------|
| ![](Resources/05-pcb-render-3d-front-01.png)    | ![](Resources/06-pcb-render-3d-rear-01.png)     |

| PCB Render 3D (ver. B)                          | PCB Render 3D (ver. B)                          |
|-------------------------------------------------|-------------------------------------------------|
| ![](Resources/05-pcb-render-3d-front-02.png)    | ![](Resources/06-pcb-render-3d-rear-02.png)     |

| Case 3D Model                                   | Project Final                                   |
|-------------------------------------------------|-------------------------------------------------|
| ![](Resources/07-case-3d-model.jpg)             | ![](Resources/08-proyect-final.jpg)             |

See 'Rescources' sub-folder for more pictures & videos of the project.

&nbsp;

### Version History

v1.0 (2025.12.20) - Initial release.  
v1.1 (2025.12.21) - Adding schematics & PCB.  
v1.2 (2025.12.22) - Update schematics & PCB, adding firmware base code.  
v1.3 (2025.12.23) - Update schematics & PCB, update firmware.  
v1.4 (2025.12.25) - Adding PCB version 2 without baterry holder.  
v1.5 (2025.12.26) - Adding case 3D model, adding 'Stickers' folder.  

&nbsp;

This source code is licensed under GPL v3.0  
Please send me your feedback about this project: andres.garcia.alves@gmail.com
