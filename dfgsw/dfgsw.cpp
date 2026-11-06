#include <iostream>
#include <string>
#include <exception>

// Custom exception class to handle empty string inputs
class EmptyStringException : public std::exception {
public:
    // Overriding the what() method to return a specific error message
    const char* what() const noexcept override {
        return "Error: Input string cannot be empty!";
    }
};

int main() {
    std::string userInput;

    std::cout << "Enter a string: ";
    // Use std::getline to properly capture strings containing spaces (like "Hello, World!")
    std::getline(std::cin, userInput);

    try {
        // Check if the entered string is empty
        if (userInput.empty()) {
            throw EmptyStringException();
        }

        // If not empty, display success message matching the sample output format
        std::cout << "String assigned successfully: " << userInput << std::endl;
    }
    catch (const EmptyStringException& e) {
        // Catch and handle the custom empty string exception
        std::cerr << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        // Catch-all block for any other standard exceptions
        std::cerr << "Standard exception: " << e.what() << std::endl;
    }

    return 0;
}
