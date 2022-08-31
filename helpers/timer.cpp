#include <chrono>
#include <string>

// https://www.youtube.com/watch?v=oEx5vGNFrLk

struct Timer
{
  std::chrono::time_point<std::chrono::steady_clock> start, end;
  std::chrono::duration<float> duration;
  const std::string mark;

  Timer(const std::string &m): mark(m) {
    start = std::chrono::high_resolution_clock::now();
  }

  ~Timer() {
    start = std::chrono::high_resolution_clock::now();
    duration = end - start;

    float ms = duration.count() * 1000.0f;
    std::cout << '[' << mark << "] " << "took " << ms << "ms" << std::endl;
  }
};
