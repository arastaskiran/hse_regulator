## SUMMARY
-----

This project was developed using Arduino nano to process dangerous proximity inputs and transfer them to predefined outputs.

It is not for general use, it was developed to solve a specific problem.

## PIN LAYOUT
---------

                      +-----+
         +------------| USB |------------+
         |            +-----+            |
    B5   | [ ]D13/SCK        MISO/D12[ ] |   B4
         | [ ]3.3V           MOSI/D11[ ]~|   B3
         | [ ]V.ref     ___    SS/D10[ ]~|   B2
    C0   | [ ]A0       / N \       D9[ ]~|   B1
    C1   | [ ]A1      /  A  \      D8[ ] |   B0
    C2   | [ ]A2      \  N  /      D7[ ] |   D7
    C3   | [ ]A3       \_0_/       D6[ ]~|   D6
    C4   | [ ]A4/SDA               D5[ ]~|   D5
    C5   | [ ]A5/SCL               D4[ ] |   D4
         | [ ]A6              INT1/D3[ ]~|   D3
         | [ ]A7              INT0/D2[ ] |   D2
         | [ ]5V                  GND[ ] |     
    C6   | [ ]RST                 RST[ ] |   C6
         | [ ]GND   5V MOSI GND   RX1[ ] |   D0
         | [ ]Vin   [ ] [ ] [ ]   TX1[ ] |   D1
         |          [ ] [ ] [ ]          |
         |          MISO SCK RST         |
         | NANO-V3                       |
         +-------------------------------+

## USAGE
---------

> SETUP

```c++
#include <hse_lib.h>
void setup()
{
  // Input Configuration
  HSELib::setPreAlarmInput(2);
  HSELib::setCraneDangerInput(3);
  HSELib::setCraneWarningInput(4);
  HSELib::setSenWarningInput(5);
  // Output Configuration
  HSELib::setBuzzerOutput(6);
  HSELib::setDangerStateOutput(7, true);
  HSELib::setNormalStateOutput(8, true);
  HSELib::setWarningStateOutput(9, true);
  // Blink duration
  HSELib::setToggleDuration(500);
}
```

> RUNTIME

```c++
void loop()
{
  HSELib::update();
  
  //If you want to extend the software other than standard use
  
  if (HSELib::isNormalStateChanged())
  {
      //bla bla
  }

  if (HSELib::isWarningStateChanged())
  {
      //bla bla
  }

  if (HSELib::isDangerStateChanged())
  {
      //bla bla
  }

  if (HSELib::isBuzzerStateChanged())
  {
      //bla bla
  }
}
```

## FOLDER STRUCTURE
-----------

For example, see a structure of the following two libraries `Foo` and `Bar`:

```
|--lib
|  |
|  |--Bar
|  |  |--docs
|  |  |--examples
|  |  |--src
|  |     |- Bar.c
|  |     |- Bar.h
|  |  |- library.json (optional, custom build options, etc) 
|  |
|  |--Foo
|  |  |- Foo.c
|  |  |- Foo.h
|  |
|  |- README
|
|--src
|  |- main.c
|
|-- README --> THIS FILE
```
and a contents of `src/main.cpp`:
```
#include <Foo.h>
#include <Bar.h>

int main (void)
{
  ...
}

```

## Documentation
--------

> TODO: The documentation has not been written yet, I am sharing the signatures for now

* ### Methods
    * void setPreAlarmInput(int io, int mode)
    * void setCraneDangerInput(int io, int mode)
    * void setCraneWarningInput(int io, int mode)
    * void setSenWarningInput(int io, int mode)
    * void setBuzzerOutput(int io, bool blink)
    * void setDangerStateOutput(int io, bool blink)
    * void setNormalStateOutput(int io, bool blink)
    * void setWarningStateOutput(int io, bool blink)
    * void setToggleDuration(int duration)
    * int getInputNumeric
    * bool getNormalState
    * bool getWarningState
    * bool getDangerState
    * bool getBuzzerState
    * bool getToggleVal
    * void update

* ### Events
    * isNormalStateChanged
    * isWarningStateChanged
    * isDangerStateChanged
    * isBuzzerStateChanged
    


## TRUTH TABLE
-----------------------


| PreAlarm | CraneDanger | CraneWarning | SenWarning | Green | Yellow | Red | Buzzer |
|----------|-------------|--------------|------------|-------|--------|-----|--------|
|          |             |              |            |       |        |     |        |
|        0 |           0 |            0 |          0 |     1 |      0 |   0 |      0 |
|        0 |           0 |            0 |          1 |     1 |      0 |   0 |      0 |
|        0 |           0 |            1 |          0 |     1 |      0 |   0 |      0 |
|        0 |           0 |            1 |          1 |     0 |      0 |   1 |      1 |
|        0 |           1 |            0 |          0 |     0 |      0 |   1 |      1 |
|        0 |           1 |            0 |          1 |     0 |      0 |   1 |      1 |
|        0 |           1 |            1 |          0 |     0 |      0 |   1 |      1 |
|        0 |           1 |            1 |          1 |     0 |      0 |   1 |      1 |
|        1 |           0 |            0 |          0 |     0 |      1 |   0 |      0 |
|        1 |           0 |            0 |          1 |     0 |      1 |   0 |      1 |
|        1 |           0 |            1 |          0 |     1 |      0 |   0 |      0 |
|        1 |           0 |            1 |          1 |     0 |      0 |   1 |      1 |
|        1 |           1 |            0 |          0 |     0 |      0 |   1 |      1 |
|        1 |           1 |            0 |          1 |     0 |      0 |   1 |      1 |
|        1 |           1 |            1 |          0 |     0 |      0 |   1 |      1 |
|        1 |           1 |            1 |          1 |     0 |      0 |   1 |      1 |
--------------------------------------------------------------------------------------


