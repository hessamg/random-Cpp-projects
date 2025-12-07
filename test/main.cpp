#include "Instrumentor.h"
#include <bits/stdc++.h>
#include <bits/types/timer_t.h>

void function() {
  InstrumentationTimer timer("function");
  for (int i = 0; i < 100; i++) {
    std::cout << "Function is running: " << i << std::endl;
  }
}

int main() {
  Instrumentor::Get().BeginSession("profile");
  function();
  std::cout << "hello world" << std::endl;
  std::cin.get();
  Instrumentor::Get().EndSession();
  return 0;
}
