**Monty ByteCode file Interpreter**

* Contains special opcodes: swap, add, mul, sub, div, pop, pint, nop, pstr, pall, pchar

**Contents**:

* monty_calculator.c --- holds the mathematical operations
* monty.h --- holds the function prototypes for the interpreter
* bytecode_interpreter.c --- main bulk of the program
* bf(folder) --- contains the bf files
* bytecodes(folder) --- contains the bytecode files

**Compilation Process**

```
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

**Authors**

Colin Earle

Benjamin Paul Opiyo
