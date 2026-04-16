#include <iostream>

int main() {
    int num1, num2;
    
  
    while (std::cin >> num1 >> num2) {
        // 두 수의 합 출력
        int sum = num1 + num2;
        std::cout << sum << "\n";
    }

  

    return 0;
}
