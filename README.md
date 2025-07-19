# Medusa

Medusa is a C-based challenge project that demonstrates runtime code decryption and dynamic execution. It includes a simple flag validation mechanism, with the main logic obfuscated using XOR encryption and executed from memory at runtime.

## Files

- **main.c**  
  The main entry point. Prompts the user for input, decrypts an embedded validation function at runtime, and executes it from memory.

- **validate.c**  
  A reference implementation of the flag validation logic in plain C.

- **validate-self-contained.c**  
  A self-contained version of the validator, storing the flag as a local array.

- **xor.py**  
  A Python script for XOR-encrypting/decrypting byte arrays, used to generate the encrypted validator code.

## How It Works

1. The validator code is XOR-encrypted and embedded in `main.c`.
2. At runtime, `main.c` allocates executable memory, copies the encrypted code, and decrypts it using the `xor_decrypt` function with the key `0x1337`.
3. The decrypted code is cast to a function pointer and called with the user's input.
4. If the input matches the flag (`pwning-since-1337`), the user is allowed to proceed.

## Building

To build the project, run:

```sh
gcc -m32 -fno-stack-protector -z execstack -no-pie -fno-pic main.c -o medusa
```

## Blog Post(s)

- [Part 0x01](https://iamavu.com/posts/05-making-medusa-my-first-crackme-part-0x01/)