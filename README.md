### Hamming Code 8-to-4 Algorithm

This project implements the Hamming Code 8-to-4 algorithm for error detection and correction, capable of handling one mistake. The program provides an interactive interface to encode, decode, and simulate errors in a given input number.

### Usage

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/siyovush-hamidov/hamming-code-8-4/
   ```

2. **Build the Program:**
   ```bash
   cmake -S . -B build
   cd build
   make
   ```

3. **Run the Program:**
   ```bash
   ./hamming_code
   ```

### Interactive Interface

When you run the program, you will see the following menu:

```
ENTER THE OPTION:
0. ENTER A DECIMAL NUMBER TO WORK WITH
1. ENCODE
2. DECODE
3. MAKE A MISTAKE
4. EXIT
```

### Normal Workflow:
1. **Option 0**: Enter a decimal number to work with.
2. **Option 1**: Encode the number.
3. **Option 3**: Optionally, simulate an error to test error detection.
4. **Option 0** or **Option 4**: Repeat or exit the program.

For decoding without errors, use **Option 2**.

### Additional Information

For a detailed explanation of the Hamming Code theory and its usage, refer to [this link](https://www.ece.unb.ca/tervo/ee4253/hamming.shtml).

### Contributions

Contributions are welcome! Feel free to submit pull requests under the MIT license.
