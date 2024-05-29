# Simple Calculator

This is a simple calculator application implemented using C++ and the Qt framework. The calculator can perform four basic arithmetic operations.

## Features

- Addition
- Subtraction
- Multiplication
- Division
- Memory Functions: Memory Add (M+), Memory Clear (MC), and Memory Recall (MR)
- Clear Display Function
- Change Sign of the Current Number

## Installation and Setup

### Prerequisites

- Qt framework (Qt 5 or Qt 6)
- C++ compiler (e.g., GCC, Clang, MSVC)

### Building the Project

1. Clone the repository:
    ```sh
    git clone https://github.com/EmergencyCab/CalculatorPro.git
    cd CalculatorPro
    ```

2. Open the project in Qt Creator or build it using the command line:
    ```sh
    qmake
    make
    ```

3. Run the application:
    ```sh
    ./CalculatorPro
    ```

## How to Use

- Use the numeric buttons (0-9) to input numbers.
- Click on the appropriate arithmetic operation button (`+`, `-`, `*`, `/`) to perform calculations.
- Use the memory buttons (M+, MC, MR) to add to memory, clear memory, and recall memory values.
- Click the `AC` button to clear the display.
- Click the `+/-` button to change the sign of the current display value.
- Click the `=` button to calculate the result of the arithmetic operation.

## Code Overview

### Functions

- **NumPressed()**: Handles the input of numeric buttons.
- **MathButtonPressed()**: Handles the input of arithmetic operation buttons.
- **EqualButtonPressed()**: Calculates and displays the result.
- **ChangeNumberSign()**: Changes the sign of the current number.
- **Clear()**: Clears the display.
- **MemAdd()**: Adds the current display value to memory.
- **MemClear()**: Clears the memory value.
- **MemGet()**: Recalls the memory value to the display.

## Contributing

Feel free to fork this repository and contribute by submitting pull requests. Suggestions and improvements are welcome!

## Acknowledgments

- This project uses the Qt framework for the GUI.


