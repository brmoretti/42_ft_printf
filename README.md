# 42_ft_printf
<p align="center">
  <img src="https://game.42sp.org.br/static/assets/achievements/ft_printfm.png" alt="Achievement Image"><br>
</p>

## Overview

This project, ft_printf, is a fundamental task at 42 School that requires students to implement a simplified version of the printf function in C. The goal is to understand the intricacies of formatting output in C and gain a deeper understanding of variable argument lists.

## Table of Contents

- [Getting Started](#getting-started)
- [Usage](#usage)
- [Project Structure](#project-structure)

## Getting Started

To get started with the ft_printf project, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/brmoretti/42_ft_printf.git
   cd 42_ft_printf
   ```
2. Navigate to the project directory:
    ```bash
    cd 42_ft_printf
    ```
3. Compile the project:
    ```
    make
    ```

## Usage

To use ft_printf in your C project, follow these steps:

1. Include the header file in your source code:
   ```c
   #include "ft_printf.h"
   ```
2. Use the ft_printf function to print formatted output, similar to the standard printf function:
   ```c
   int main(void)
   {
       ft_printf("Hello, %s!\n", "world");
       return (0);
   }
   ```
3. Compile your program with the ft_printf library:
   ```bash
   gcc your_program.c libftprintf.a -o your_program
   ```
4. Run your program:
   ```bash
   ./your_program
   ```

## Project Structure

The project is organized as follows:

- <b>libftprintf.a:</b> The compiled library containing the ft_printf implementation.
- <b>src/:</b> Contains the source code for the ft_printf function.
- <b>include/:</b> Contains the header file (ft_printf.h) for including in your projects.
- <b>Makefile:</b> Makefile for compiling the project.
Feel free to explore the source code and customize it according to your needs.
