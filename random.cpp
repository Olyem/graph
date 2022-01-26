#include <cstdlib>
#include <iostream>

void generate_random_number () {
  int n;
  while (true) {
    std::cout << "entrez une borne max (0 to quit) ";
    std::cin >> n;
    if (n == 0)
      break;
    int r = rand() % n;
    std::cout << "   le nombre généré inférieur ou égal à " << n-1
	      << " est " << r << std::endl;
  }
}

int main () {
  generate_random_number();
  return 0;
}
