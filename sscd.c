#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifdef _WIN32
#define snprintf _snprintf  // Fix for MinGW in Dev-C++
#endif

#define MAX_LINE 50
#define MAX_MNEMONICS 7

// Supported mnemonics and their respective opcodes
const char *mnemonics[MAX_MNEMONICS] = {"HALT", "LOAD", "STORE", "ADD", "SUB", "MUL", "DIV"};
const char *opcodes[MAX_MNEMONICS] = {"000", "001", "100", "011", "010", "101", "110"};

// Function to trim whitespace from a string
void trim(char *str) {
    int i, start = 0, end = strlen(str) - 1;
    while (isspace(str[start])) start++;
    while (end > start && isspace(str[end])) end--;
    for (i = start; i <= end; i++) str[i - start] = str[i];
    str[i - start] = '\0';
}

// Get opcode from mnemonic
const char* get_opcode(const char *mnemonic) {
    int i; // Move declaration outside loop
    for (i = 0; i < MAX_MNEMONICS; i++) {
        if (strcmp(mnemonics[i], mnemonic) == 0) {
            return opcodes[i];
        }
    }
    return NULL;
}

// Get mnemonic from opcode
const char* get_mnemonic(const char *opcode) {
    int i; // Move declaration outside loop
    for (i = 0; i < MAX_MNEMONICS; i++) {
        if (strcmp(opcodes[i], opcode) == 0) {
            return mnemonics[i];
        }
    }
    return NULL;
}

// Assembler: Convert Assembly to Machine Code
void assemble(const char *input_file, const char *output_file) {
    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");

    if (!in || !out) {
        printf("Error: Unable to open file.\n");
        if (in) fclose(in);
        if (out) fclose(out);
        return;
    }

    char line[MAX_LINE];
    int line_num = 0;

    while (fgets(line, MAX_LINE, in)) {
        line_num++;
        trim(line);
        if (strlen(line) == 0) continue;

        char mnemonic[MAX_LINE];
        int operand = 0;

        int scanned = sscanf(line, "%s %d", mnemonic, &operand);
        if (scanned < 1) {
            printf("Error: Invalid line format at line %d.\n", line_num);
            continue;
        }

        const char *opcode = get_opcode(mnemonic);
        if (!opcode) {
            printf("Error: Invalid mnemonic '%s' at line %d.\n", mnemonic, line_num);
            continue;
        }

        if (strcmp(mnemonic, "HALT") == 0) operand = 0;

        fprintf(out, "%s %08d\n", opcode, operand);
    }

    fclose(in);
    fclose(out);
    printf("Assembly to Machine Code conversion complete.\n");
}

// Disassembler: Convert Machine Code to Assembly
void disassemble(const char *input_file, const char *output_file) {
    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");

    if (!in || !out) {
        printf("Error: Unable to open file.\n");
        if (in) fclose(in);
        if (out) fclose(out);
        return;
    }

    char line[MAX_LINE];
    int line_num = 0;

    while (fgets(line, MAX_LINE, in)) {
        line_num++;
        trim(line);
        if (strlen(line) == 0) continue;

        char opcode[4], operand_str[9];
        int operand = 0;

        int scanned = sscanf(line, "%s %s", opcode, operand_str);
        if (scanned < 2) {
            printf("Error: Invalid machine code format at line %d.\n", line_num);
            continue;
        }

        const char *mnemonic = get_mnemonic(opcode);
        if (!mnemonic) {
            printf("Error: Invalid opcode '%s' at line %d.\n", opcode, line_num);
            continue;
        }

        operand = atoi(operand_str);
        fprintf(out, "%s %d\n", mnemonic, operand);
    }

    fclose(in);
    fclose(out);
    printf("Machine Code to Assembly conversion complete.\n");
}

// Main function for user interaction
int main() {
    int choice;
    char input_file[MAX_LINE];
    char output_file[MAX_LINE];

    while (1) {
        printf("\nSelect an operation:\n");
        printf("1. Assemble (Assembly to Machine Code)\n");
        printf("2. Disassemble (Machine Code to Assembly)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');  // Clear input buffer
            continue;
        }

        if (choice == 3) {
            printf("Exiting...\n");
            break;
        }

        printf("Enter input file name: ");
        scanf("%s", input_file);

        if (choice == 1) {
            snprintf(output_file, sizeof(output_file), "machine_output.txt");
            assemble(input_file, output_file);
        } else if (choice == 2) {
            snprintf(output_file, sizeof(output_file), "assembly_output.txt");
            disassemble(input_file, output_file);
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

