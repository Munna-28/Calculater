
# C++ Calculator

This project is a simple command-line calculator written in C++. It supports basic arithmetic operations such as addition, subtraction, multiplication, and division. The calculator processes expressions provided as a single input string and handles operator precedence.

## Features

- **Supports basic arithmetic operations**:
  - Addition (`+`)
  - Subtraction (`-`)
  - Multiplication (`*`)
  - Division (`/`)
- **Handles operator precedence**:
  - Multiplication and division are performed before addition and subtraction.
- **Handles both integer and decimal inputs**.
- **Performs left-to-right evaluation**.

## How it works

1. The input expression is parsed character by character.
2. Two stacks are used:
   - One for numbers (operands).
   - One for operators.
3. Numbers are pushed onto the values stack, and operators are pushed onto the operator stack based on precedence.
4. The calculator processes operators in the correct order and applies them to the operands.

### Example

For an input like:

```
3 + 5 * 2 - 8 / 4
```

The calculator evaluates it as:

```
3 + (5 * 2) - (8 / 4)
```

Resulting in:

```
Result: 9
```

## Getting Started

### Prerequisites

- A C++ compiler (e.g., `g++`, `clang`)
- A terminal/command prompt to run the program

### Compilation

To compile the program, run the following command:

```bash
g++ calculator.cpp -o calculator
```

### Running the Program

After compiling, run the program by executing:

```bash
./calculator
```

### Input Format

You can input any arithmetic expression with spaces between numbers and operators. The calculator supports:

- **Addition**: `+`
- **Subtraction**: `-`
- **Multiplication**: `*`
- **Division**: `/`

Example input:

```
3 + 5 * 2 - 8 / 4
```

### Handling Errors

- **Division by zero**: If you attempt to divide by zero, the program will output an error and stop the evaluation.
  
Example:

```
3 + 5 / 0
```

Output:

```
Error: Division by zero
```


