#include <iostream>
#include <vector>
#include <unordered_set>

#include <chrono>
// #include "chrono_io"

std::vector<int> eratosthenes(int n) {
  std::vector<int> v, res;
  v.reserve(n);

  // init
  for (int i = 0; i < n; i++)
    v[i] = i + 1; // from 1

  int m;
  res.push_back(1);

  for (int i = 1; i < n; i++) { // from second number
    m = v[i];

    if (m != 0) {
      res.push_back(m);
      for (int j = i; j < n; j += m) {
        v[j] = 0;
      }
    }
  }

  return res;
}

std::vector <int> primes_via_vector(int n) {
  std::vector <int> primes = {1};

  bool is_prime;

  for (int i = 2; i <= n; i++) {
    is_prime = true;

    for (int j = 1; j < primes.size(); j++) { // from 2
      if ((i) % primes[j] == 0) {
        is_prime = false;
      }
    }

    if (is_prime) {
      primes.push_back(i);
    }
  }

  return primes;
}

void print(std::vector<int> &&v) {
  for (auto &&el: v)
    std::cout << el << ' ';

  std::cout << std::endl;
}

int main() {
  auto start_empty = std::chrono::steady_clock::now();
  auto end_empty = std::chrono::steady_clock::now();

  std::cout << "EMPTY (Just timers): " << (end_empty - start_empty).count() / 1000.0 << "ms????? ticks??" << std::endl;

  int n = 10000;

  auto start_eratosthenes = std::chrono::steady_clock::now();
  print(eratosthenes(n));
  auto end_eratosthenes = std::chrono::steady_clock::now();
  std::cout << "Eratosthenes: " << (end_eratosthenes - start_eratosthenes).count()/1000.0 << "ms????? ticks??" << std::endl;
  std::cout << "--------------------------" << std::endl;


  auto start_via_vector = std::chrono::steady_clock::now();
  print(primes_via_vector(n));
  auto end_via_vector = std::chrono::steady_clock::now();
  std::cout << "Via vector: " << (end_via_vector - start_via_vector).count()/1000.0 << "ms????? ticks??" << std::endl;
}
