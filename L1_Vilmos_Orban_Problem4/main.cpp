#include <iostream>

int MAX_CAPACITY = 100;

void solveProblem4a() {
    std::cout << "--- Problem 4a ---" << std::endl;
    std::cout << "Enter numbers (0 to end sequence, -1 to end all):" << std::endl;

    int globalMax = 0;
    int currentNum;
    int sequenceCounter = 1;
    bool dataEntered = false;

    while (true) {
        int localMax = 0;
        bool inSequence = false;

        while (std::cin >> currentNum && currentNum != 0 && currentNum != -1) {
            inSequence = true;
            dataEntered = true;
            if (currentNum > localMax) {
                localMax = currentNum;
            }
            if (currentNum > globalMax) {
                globalMax = currentNum;
            }
        }
        if (inSequence) {
            std::cout << "Maximum of sequence " << sequenceCounter++ << ": " << localMax << std::endl;
        }
        if (currentNum == -1) break;
    }

    if (dataEntered) {
        std::cout << "Global maximum of all sequences: " << globalMax << std::endl;
    } else {
        std::cout << "No valid data was provided." << std::endl;
    }
}

void solveProblem4b() {
    std::cout << "\n--- Problem 4b ---" << std::endl;

    int n;
    int dataArray[MAX_CAPACITY];
    std::cout << "Enter the number of elements (max " << MAX_CAPACITY << "): ";
    std::cin >> n;

    if (n > MAX_CAPACITY) {
        std::cout << "Warning: Maximum size exceeded. Using " << MAX_CAPACITY << " instead." << std::endl;
        n = MAX_CAPACITY;
    }

    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> dataArray[i];
    }

    int minLimit, maxLimit;
    std::cout << "Enter the interval [min max]: ";
    std::cin >> minLimit >> maxLimit;

    int maxLen = 0;
    int currentLen = 0;
    int maxStartIdx = -1;
    int currentStartIdx = -1;

    for (int i = 0; i < n; ++i) {
        // Check if current element is within the interval
        if (dataArray[i] >= minLimit && dataArray[i] <= maxLimit) {
            if (currentLen == 0) {
                currentStartIdx = i;
            }
            currentLen++;

            if (currentLen > maxLen) {
                maxLen = currentLen;
                maxStartIdx = currentStartIdx;
            }
        } else {
            currentLen = 0;
        }
    }

    if (maxLen > 0) {
        std::cout << "The longest subsequence in the interval: ";
        for (int i = maxStartIdx; i < maxStartIdx + maxLen; ++i) {
            std::cout << dataArray[i] << " ";
        }
        std::cout << "\nLength: " << maxLen << std::endl;
    } else {
        std::cout << "No elements found within the specified interval." << std::endl;
    }
}

int main() {
    solveProblem4a();
    solveProblem4b();

    return 0;
}