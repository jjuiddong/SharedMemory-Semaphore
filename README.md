# SharedMemory-Semaphore
IPC shared memory + semaphore + mutex with VS2019 C++
- Inter-Process Communication with shared memory circular queue
  - synchronize with semaphore, mutex

![](https://github.com/jjuiddong/SharedMemory-Semaphore/blob/main/Doc/diagram.jpg?raw=true)

- Shared Memory
  - If no one of the processes accesses the shared memory, it is automatically removed.
  - If either producer or consumer is accessing the shared memory, the memory remains the same.
- Semaphore
  - The semaphore count is managed by the OS, and if there is no process accessing the semaphore,
   count is initialized.
  - Producer counts up and consumer counts down.
  - If the consumer is accessing the semaphore, the count remains the same even if the producer terminates.
