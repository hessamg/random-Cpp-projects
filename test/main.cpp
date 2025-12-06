#include <bits/stdc++.h>
#include <bits/types/timer_t.h>

class Timer {
public:
  Timer(const char *name) : m_name(name), m_stopped(false) {}
  void stop() {
    auto endTime = std::chrono::high_resolution_clock::now();

    auto start =
        std::chrono::time_point_cast<std::chrono::microseconds>(m_startTime)
            .time_since_epoch()
            .count();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTime)
                   .time_since_epoch()
                   .count();

    std::cout << m_name << ": " << end - start << " ms\n";

    m_stopped = true;
  }
  ~Timer() {
    if (!m_stopped)
      stop();
  }

private:
  const char *m_name;
  std::chrono::time_point<std::chrono::high_resolution_clock> m_startTime;
  bool m_stopped;
};

int main() {
  std::cout << "hello world" << std::endl;
  std::cin.get();
  return 0;
}
