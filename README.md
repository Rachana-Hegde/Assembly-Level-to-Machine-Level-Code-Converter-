
# Assembly Level to Machine Level Code Converter 

A simple C-based **Assembler and Disassembler** that converts **Assembly Language** to **Machine Code** and vice versa. It supports a basic instruction set with mnemonics and their respective binary opcodes.

## 🚀 Features
- ✅ Convert Assembly Language to Machine Code (`Assemble`)
- ✅ Convert Machine Code back to Assembly Language (`Disassemble`)
- ✅ Supports basic mnemonics: `HALT`, `LOAD`, `STORE`, `ADD`, `SUB`, `MUL`, `DIV`
- ✅ Reads input from a file and writes the converted output to a new file

## 📂 Supported Mnemonics and Opcodes
| Mnemonic | Opcode |
|----------|--------|
| HALT     | 000    |
| LOAD     | 001    |
| STORE    | 100    |
| ADD      | 011    |
| SUB      | 010    |
| MUL      | 101    |
| DIV      | 110    |

## 🛠️ Installation & Compilation
### **Using GCC**
```sh
gcc -std=c90 sscd.c -o sscd
./sscd
```
### **Using Turbo C++ or Other Compilers**
- Open the `.c` file in the compiler.
- Compile and run without enabling **C99/C11 mode**.

## 📜 Usage
### **1️⃣ Running the Program**
Run the program and select an operation:
```sh
./sscd
```
```
Select an operation:
1. Assemble (Assembly to Machine Code)
2. Disassemble (Machine Code to Assembly)
3. Exit
Enter your choice: 
```

### **2️⃣ Assembling (Assembly → Machine Code)**
Create an **assembly input file** (`input.txt`):
```
LOAD 5
ADD 3
STORE 10
HALT
```
Run the assembler:
```
Enter input file name: input.txt
```
✅ **Output file (`machine_output.txt`)**:
```
001 00000005
011 00000003
100 00000010
000 00000000
```

### **3️⃣ Disassembling (Machine Code → Assembly)**
Create a **machine code file** (`input.txt`):
```
001 00000005
011 00000003
100 00000010
000 00000000
```
Run the disassembler:
```
Enter input file name: input.txt
```
✅ **Output file (`assembly_output.txt`)**:
```
LOAD 5
ADD 3
STORE 10
HALT
```

## 📝 Notes
- Input files should be formatted correctly, following the **mnemonic-operand** or **opcode-operand** structure.
- HALT does not require an operand (`HALT` → `000 00000000`).
- Invalid mnemonics or opcodes will generate an **error message**.

## 🛠️ Future Enhancements
- Support for more instructions
- Error handling improvements
- GUI version for easier usability

## 📬 Contact  

For any inquiries or feedback, feel free to reach out:    
🔗 **GitHub**: Rachana-Hegde

