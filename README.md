# Vehicle Registry System in C++

## Project Description

The Vehicle Registry System is a simple C++ console-based project used to store and manage vehicle details. It allows users to add vehicles, view all registered vehicles, and search for a vehicle using its ID.

This project is created to understand the basic concepts of Object-Oriented Programming (OOP) in C++.

## Features

- Add a new vehicle
- View all registered vehicles
- Search for a vehicle by Vehicle ID
- Display the total number of vehicles
- Prevent duplicate Vehicle IDs
- Support different vehicle types:
  - Car
  - Electric Car
  - Sports Car
  - Sedan
  - SUV
  - Flying Car

## OOP Concepts Used

- **Class and Object:** Classes are used to represent vehicles and manage the registry.
- **Encapsulation:** Vehicle data members are declared private and accessed through getter and setter functions.
- **Static Member:** `totalVehicles` keeps track of vehicle objects.
- **Constructors:** Default and parameterized constructors initialize vehicle details.
- **Destructor:** Destructors are used to manage object cleanup.
- **Single Inheritance:** `Car` inherits from `Vehicle`.
- **Multilevel Inheritance:** `ElectricCar` inherits from `Car`, and `SportsCar` inherits from `ElectricCar`.
- **Multiple Inheritance:** `FlyingCar` inherits from both `Car` and `Aircraft`.
- **Hierarchical Inheritance:** Both `Sedan` and `SUV` inherit from `Car`.
- **Array:** An array stores registered vehicle objects through base-class pointers.

## Technologies Used

- C++
- Standard Input/Output Library (`iostream`)
- String Library (`string`)

## How to Run

1. Save the source code in a file named `main.cpp`.
2. Open the project in a C++ compiler or IDE, such as Code::Blocks or Visual Studio Code with a C++ compiler.
3. Compile the program.
4. Run the generated executable.
5. Use the menu to add, view, or search for vehicles.

### Compile using g++

```bash
g++ main.cpp -o VehicleRegistry
```

### Run

**Windows:**
```bash
VehicleRegistry.exe
```

**Linux/macOS:**
```bash
./VehicleRegistry
```

## Main Menu

1. Add Vehicle
2. View All Vehicles
3. Search Vehicle by ID
4. Show Total Vehicles
5. Exit

## Screenshots

Add your project screenshots below after running the program.

### Main Menu
<!-- Add main menu screenshot here -->

### Add Vehicle
<!-- Add add-vehicle screenshot here -->

### View Vehicles
<!-- Add view-vehicles screenshot here -->

### Search Vehicle
<!-- Add search-vehicle screenshot here -->

## Limitations

- The program stores up to 100 vehicles during a single run.
- Vehicle data is stored in memory and is not saved after the program exits.

## Conclusion

The Vehicle Registry System provides a basic way to manage vehicle details through a menu-driven C++ program. It demonstrates important OOP concepts, including encapsulation, constructors, static members, and different types of inheritance.

## Author

Student Project
