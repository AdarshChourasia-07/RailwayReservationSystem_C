# Railway Reservation System

The **Railway Reservation System** is a console-based application developed in the **C programming language** to simulate basic railway ticket reservation and management operations. The system provides an interactive menu-driven interface through which users can view available trains, book tickets, retrieve ticket information, search bookings, and cancel tickets or train bookings.

The application maintains two primary data entities: **Train** and **Passenger**. Train records contain information such as train number, source, destination, and First AC and Second AC fares, while passenger records contain passenger details including name, gender, train number, travel class, address, age, mobile number, and ticket number.

## Key Features

* **View Available Trains** – Displays train numbers, source and destination stations, and ticket fares.
* **Book Railway Tickets** – Collects passenger information, validates the train number, travel class, age, and mobile number, and generates a unique ticket number.
* **View Ticket Details** – Retrieves and displays complete passenger and ticket information using the ticket number.
* **Search Tickets by Mobile Number** – Finds all tickets associated with a passenger's mobile number.
* **View All Bookings** – Displays all stored passenger and reservation records.
* **View Train Bookings** – Displays bookings associated with a particular train.
* **Cancel Ticket** – Removes a reservation using its ticket number.
* **Cancel Train Bookings** – Removes bookings associated with a particular train.
* **Input Validation** – Validates train numbers, mobile numbers, passenger age, gender, and travel class.
* **Console User Interface** – Uses cursor positioning, colors, screen clearing, and keyboard input to provide an interactive terminal-based interface.

## Data Storage

The project uses **binary file handling in C** to persist train and booking information. Train information is stored in `alltrains.dat`, while passenger booking information is stored in `allbookings.dat`. The application reads and writes C structures directly to these files using functions such as `fread()` and `fwrite()`.

## Project Architecture

The application is divided into logical components:

* `main.c` – Contains the main program flow and menu-driven operations.
* `rlyres.c` – Implements railway reservation functionality such as train management, passenger registration, ticket booking, ticket search, and cancellation.
* `rlyres.h` – Contains the `Train` and `Passenger` structure definitions and function declarations.
* `conio2.h` / `conio.c` – Provide additional console I/O functionality such as colors, cursor positioning, screen clearing, and keyboard handling.
* `alltrains.dat` – Binary data file containing train information.
* `allbookings.dat` – Binary data file containing reservation records.

## Technology Used

**Programming Language:** C
**Programming Concepts:** Structures, Functions, Pointers, Arrays, File Handling, Dynamic Memory Allocation, String Handling, Input Validation
**Storage:** Binary files (`.dat`)
**Interface:** Command-line / Console-based UI
**Development Environment:** Designed around the MinGW/Dev-C++ style `conio2` implementation.

## Application Flow

When the application starts, it initializes the train data and displays the main menu. The user can select an operation from the available options. For ticket booking, passenger information is collected and validated before the system checks seat availability and generates the next ticket number. The booking is then appended to the booking data file.
Overall, the project demonstrates how fundamental **C programming concepts can be combined to build a functional record-management and reservation application**, including persistent storage, structured data management, validation, searching, and deletion operations.
