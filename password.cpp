// Add SHA-256 later

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

// define characters and check if password has them
// check for lowercase letters
bool hasLowercase(const std::string& password) {
    for (char c : password) {
        if (islower(c)) return true;
    }
    return false;
}

// check for uppercase letters
bool hasUppercase(const std::string& password) {
    for (char c : password) {
        if (isupper(c)) return true;
    }
    return false;
}

// check for digits
bool hasDigit(const std::string& password) {
    for (char c : password) {
        if (isdigit(c)) return true;
    }
    return false;
}

// check for special characters and define special characters
bool hasSpecialChar(const std::string& password) {
    std::string specialChars = "!@#$%^&*()_+[]{}|:;'\",.<>?/";
    for (char c : password) {
        if (specialChars.find(c) != std::string::npos) return true;
    }
    return false;
}

// check password strength
std::string checkStrength(const std::string& password) {
    int score = 0;

    if (password.length() >= 8) score++;
    if (hasLowercase(password)) score++;
    if (hasUppercase(password)) score++;
    if (hasDigit(password)) score++;
    if (hasSpecialChar(password)) score++;

    if (score <= 2) return "Weak";
    else if (score == 3 || score == 4) return "Moderate";
    else return "Strong";
}

// For when SHA-256 is added
string hashedPassword(const string& password) {
    //Placeholder for SHA-256
    return "hashed_" + password;
}

// Check common passwords
bool isCommonPassword(const string& password) {
    vector<string> common = {"password", "123456", "abc123"};
    for (const string& p : common) {
        if (password == p) return true;
    }
    return false;
}

// User feedback
int main() {
    std::string password;
    const int MAX_LENGTH = 20;
    const int MIN_LENGTH = 6;

    std::cout << "Enter your password (" << MIN_LENGTH << "-" << MAX_LENGTH << " characters): ";
    std::getline(std::cin, password);

    if (password.length() < MIN_LENGTH) {
        std::cout << "Password too short! Must be at least " << MIN_LENGTH << " characters." << std::endl;
        return 0;
    }
    if (password.length() > MAX_LENGTH) {
        std::cout << "Password too long! Must be at least " << MIN_LENGTH << " characters." << std::endl;
        return 0;
    }
    if (isCommonPassword(password)) {
        cout << "This password is too common!" << endl;
        return 0;
    }

    std::string strength = checkStrength(password);
    std::cout << "Password Strength: " << strength << std::endl;

    return 0;
}
