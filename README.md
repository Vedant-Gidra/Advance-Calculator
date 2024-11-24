
# Advanced Calculator Program

## Introduction  
This program is a comprehensive calculator written in **C++**. It provides functionality for basic arithmetic operations, complex number calculations, matrix operations, and mathematical expression evaluation. The program is designed with modularity and extensibility in mind, allowing users to choose from a variety of calculation options.

---

## Features  

1. **Basic Calculator**  
   - Performs addition, subtraction, multiplication, division, and power calculations for two numbers.  

2. **Complex Number Calculator**  
   - Handles addition, subtraction, multiplication, and division of complex numbers.

3. **Matrix Calculator**  
   - Supports operations such as:
     - Matrix addition  
     - Matrix subtraction  
     - Matrix multiplication  
     - Scalar multiplication  

4. **Expression Evaluator**  
   - Evaluates mathematical expressions involving addition (`+`), subtraction (`-`), and parentheses (`()`).

---

## How to Use  

1. Compile the program using the following command:  
   ```bash
   g++ -o calculator calculator.cpp
   ```

2. Run the program:  
   ```bash
   ./calculator
   ```

3. Follow the prompts to select the type of calculation you want to perform.

---

## Example Usage  

### Basic Calculator  
```plaintext
Enter Expression (like 5+2): 
5 + 2
Result: 7
```

### Complex Number Calculator  
```plaintext
Enter Expression
Enter real part: 3
Enter imaginary part: 4
Enter Operator: +
Enter real part: 1
Enter imaginary part: 2
Result: 4 + 6i
```

### Matrix Calculator  
```plaintext
1. Matrix Addition
2. Matrix Subtraction
3. Matrix Multiplication
4. Matrix Scalar Multiplication
Enter your choice: 1
For matrix 1
Enter the number of Rows and Columns respectively.
2 2
Enter the Matrix
1 2
3 4
For matrix 2
Enter the number of Rows and Columns respectively.
2 2
Enter the Matrix
5 6
7 8
Result:
6 8
10 12
```

### Expression Evaluator  
```plaintext
Enter the expression...Please Note: Expression containing + - and () are solved
(5 + (3 - 2)) - 4
Result: 2
```

---

## Future Enhancements  
Currently, the focus is on building logic and algorithms rather than full-fledged development features. Potential future enhancements:

- Extending the expression evaluator to support multiplication (`*`) and division (`/`).
- Adding graphical representations for matrix operations.
- Integration with File Systems: Enable exporting and importing complex expressions and matrices for reuse.
