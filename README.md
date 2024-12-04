# 🧑‍💻 **Hamming Code 8-to-4 Algorithm** 📡

This project implements the **Hamming Code 8-to-4** algorithm for **error detection** and **correction**, capable of handling **one mistake**. The program provides an interactive interface to **encode**, **decode**, and **simulate errors** in a given input number.

---

## 📥 **Usage**

### 1️⃣ **Clone the Repository:**
   ```bash
   git clone https://github.com/siyovush-hamidov/hamming-code-8-4/
   ```

### 2️⃣ **Build the Program:**
   ```bash
   cmake -S . -B build
   cd build
   make
   ```

### 3️⃣ **Run the Program:**
   ```bash
   ./hamming_code
   ```

---

## 🖥️ **Interactive Interface**

When you run the program, you will see the following menu:

```
ENTER THE OPTION:
0. ENTER A DECIMAL NUMBER TO WORK WITH
1. ENCODE
2. DECODE
3. MAKE A MISTAKE
4. EXIT
```

---

## 🔄 **Normal Workflow:**

1. **Option 0**: Enter a **decimal number** to work with.  
2. **Option 1**: **Encode** the number using Hamming Code.  
3. **Option 3**: **Simulate an error** to test error detection.  
   - You need to indicate the **byte number** (from 1 to 8) and the **bit number** (from 1 to 8) to invert to simulate an error.  
   - **Even bits** can be altered but will not be recognized as errors (because **odd bits** are the parity bits).  
   - For the error to be detected, **alter odd bits** (1, 3, 5, 7).
4. **Option 0** or **Option 4**: Repeat or **exit** the program.

For **decoding without errors**, use **Option 2**.

---

## 📚 **Additional Information**

For a detailed explanation of the **Hamming Code theory** and its usage, refer to [this link](https://www.ece.unb.ca/tervo/ee4253/hamming.shtml).

---

## 🤝 **Contributions** 

Contributions are welcome! 🎉  
Feel free to submit **pull requests** under the **MIT license**.  

---

**Enjoy using the Hamming Code 8-to-4 algorithm!** 😎
