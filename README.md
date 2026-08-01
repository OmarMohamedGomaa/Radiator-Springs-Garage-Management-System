# Car Management System

A C++ console-based application for managing racing cars and support vehicles. The system allows a sheriff or administrator to check in cars, retire them, view the garage, tune vehicle performance, and generate a report.

## Features

- Check in new cars
- Retire cars from the system
- Display all currently stored cars
- Tune up a car's speed and capacity
- Generate a report of the garage state
- Validate user inputs so numeric values must be positive

## Project Structure

- `cars.h` / `cars.cpp` – base car class and shared behavior
- `racer.h` / `racer.cpp` – racer-specific class
- `support.h` / `support.cpp` – support-vehicle-specific class
- `garage.h` / `garage.cpp` – garage container and storage logic
- `program.cpp` – main menu and program flow
- `program.h` – declarations used by the main program
- `cars.json` – saved data file used by the application

## Build Instructions

Compile the project from the project folder using:

```bash
g++ -std=c++17 -Wall -Wextra -o program.exe *.cpp
```

Run the program with:

```bash
./program.exe
```

## Notes

- The program uses simple console input and output.
- Numeric values such as car number, age, speed, and capacity are validated to ensure they are positive integers.
- The garage data is stored in `cars.json` for persistence.
