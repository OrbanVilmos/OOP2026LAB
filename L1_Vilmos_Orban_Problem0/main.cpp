#include <iostream>

const int MAX_CAPACITY = 100;

int calculateGcd(int a, int b) {
    while (b) {
        a %= b;
        int temp = a;
        a = b;
        b = temp;
    }
    return a;
}

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

bool checkCoprimeProperty(int x) {
    for (int k = 2; k < x; ++k) {
        if (calculateGcd(x, k) == 1) {
            if (!isPrime(k)) {
                return false;
            }
        }
    }
    return true;
}

void solveProblem0a() {
    std::cout << "--- Problem 0a ---" << std::endl;
    int n;
    std::cout << "Enter how many numbers to find (n): ";
    std::cin >> n;

    int foundCount = 0;
    int currentNumber = 3; // Numbers must be > 2

    std::cout << "First " << n << " numbers satisfying the property: " << std::endl;
    while (foundCount < n) {
        if (checkCoprimeProperty(currentNumber)) {
            std::cout << currentNumber << " ";
            foundCount++;
        }
        currentNumber++;
    }
    std::cout << "\n" << std::endl;
}


//  Helper for 0b: Checks if two numbers have the exact same set of digits

void extractDigits(int num, bool digitSet[10]) {
    // Initialize the set with false
    for (int i = 0; i < 10; ++i) {
        digitSet[i] = false;
    }

    if (num == 0) {
        digitSet[0] = true;
        return;
    }

    if (num < 0) {
        num *= -1;
    }

    while (num > 0) {
        digitSet[num % 10] = true;
        num /= 10;
    }
}

bool haveSameDigitSet(int a, int b) {
    bool setA[10];
    bool setB[10];

    extractDigits(a, setA);
    extractDigits(b, setB);

    // Compare the two sets
    for (int i = 0; i < 10; ++i) {
        if (setA[i] != setB[i]) {
            return false;
        }
    }
    return true;
}

void solveProblem0b() {
    std::cout << "--- Problem 0b ---" << std::endl;
    int n;
    int array[MAX_CAPACITY];

    std::cout << "Enter array size (max " << MAX_CAPACITY << "): ";
    std::cin >> n;

    if (n > MAX_CAPACITY) n = MAX_CAPACITY;

    std::cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    int maxLength = 0;
    int currentLength = 0;
    int bestEndIndex = -1;

    if (n > 0) {
        maxLength = 1;
        currentLength = 1;
        bestEndIndex = 0;
    }

    for (int i = 1; i < n; ++i) {
        if (haveSameDigitSet(array[i], array[i - 1])) {
            currentLength++;
        } else {
            currentLength = 1;
        }

        if (currentLength > maxLength) {
            maxLength = currentLength;
            bestEndIndex = i;
        }
    }

    if (maxLength > 0) {
        std::cout << "Longest sequence with same consecutive digits: ";
        for (int i = bestEndIndex - maxLength + 1; i <= bestEndIndex; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << "\nLength: " << maxLength << std::endl;
    }
}

int main() {
    solveProblem0a();
    solveProblem0b();
    return 0;
}