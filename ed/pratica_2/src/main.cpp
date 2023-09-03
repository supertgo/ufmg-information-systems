#include <iostream>
#include <string>
#include <sys/resource.h>
#include <sys/time.h>

#include "fat.h"
#include "fib.h"
#include "timeed.h"

int main(int argc, char *argv[]) {
  if (argc < 3)
    return 1;

  std::string algo = argv[1];
  std::string version = argv[2];
  unsigned long long int parameter = atoi(argv[3]);

  struct timespec clockStart, clockEnd;
  clock_gettime(CLOCK_REALTIME, &clockStart);

  struct rusage start, end;
  getrusage(RUSAGE_SELF, &start);

  if (algo == "-b") {
    if (version == "-i") {
      std::cout << fib_iterativo(parameter) << std::endl;
    } else if (version == "-r") {
      std::cout << fib_recursivo(parameter) << std::endl;
    } else {
      return 1;
    }
  } else if (algo == "-f") {
    if (version == "-i") {
      std::cout << fat_iterativo(parameter) << std::endl;
    } else if (version == "-r") {
      std::cout << fat_recursivo(parameter) << std::endl;
    } else {
      return 1;
    }
  }

  getrusage(RUSAGE_SELF, &end);
  clock_gettime(CLOCK_REALTIME, &clockEnd);
  std::cout << "Tempo de relógio: " << clock_time(&clockStart, &clockEnd)
            << " segundos" << std::endl;
  std::cout << "Tempo de usuário: " << user_time(&start, &end) << " segundos"
            << std::endl;
  std::cout << "Tempo de sistema: " << system_time(&start, &end) << " segundos"
            << std::endl;

  return 0;
}
