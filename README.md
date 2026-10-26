# Mechanic Workshop Management — Data Structures in C

A command-line academic project in **C** exploring customer records, a FIFO service queue, and a stack-like attendance history.

## Features represented in the code
- Create, view, edit, and remove customer records
- Store a customer name, phone number, and vehicle license plate
- Assign incremental internal customer IDs
- Add customers to a service queue and process the next customer
- View previous service events from a history stack
- Enter a scheduled appointment date (prototype functionality)

## Data structures
- **Array of records:** customer storage in `cliente.c`
- **Circular-array queue:** service order in `fila.c`
- **Array-backed stack:** service history in `historico.c`

## Build
Requires a C compiler such as GCC or Clang. From the repository root:

```bash
gcc -std=c11 -Wall -Wextra projeto_est_dados/main.c projeto_est_dados/cliente.c projeto_est_dados/fila.c projeto_est_dados/historico.c -o oficina
```

Run `./oficina` on Linux/macOS, or `oficina.exe` if compiled as a Windows executable.

## Example workflow
1. Register a customer.
2. Look up the customer by the generated ID.
3. Schedule an attendance date or process the next customer in the queue.
4. Inspect the history of processed customers.

## Known limitations and review items
- The appointment date field is declared as `char data[4]`, which is too short for the prompted `dd/mm` format and should be fixed before using that feature.
- Customer records are kept in memory rather than saved between runs.
- Queue and history are fixed-capacity; edge cases require further testing.
- Historical records refer back to current customer records, so deleting customers can affect history display.
- This is a learning exercise, not production workshop software.

## Project layout
```text
projeto_est_dados/
  main.c         CLI and menu
  cliente.c/.h   Customer operations
  fila.c/.h      FIFO queue
  historico.c/.h Attendance history
```

## Skills demonstrated
C, structs, headers, modular compilation, arrays, queues, stacks, and input handling.
