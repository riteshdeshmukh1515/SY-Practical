#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    // Default Constructor
    Complex() {
        real = 0;
        imag = 0;
    }

    // Parameterized Constructor
    Complex(float r, float i) {
        real = r;
        imag = i;
    }

    // Function to display complex number
    void display() {
        if(imag>=0)
        {
        cout << real << " + " << imag << "i" << endl;
        }
        else{
             cout << real << imag << "i" << endl;
        }
    }

    // Function to input complex number
    void input() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }

    // Overloading the + operator for addition
    Complex operator+(Complex other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overloading the - operator for subtraction (friend function)
    friend Complex operator-(Complex c1, Complex c2) {
        return Complex(c1.real - c2.real, c1.imag - c2.imag);
    }

    // Overloading the * operator for multiplication
    Complex operator*(Complex other) {
        return Complex(real * other.real - imag * other.imag, 
                       real * other.imag + imag * other.real);
    }

    // Overloading the / operator for division
    Complex operator/(Complex other) {
        float denominator = other.real * other.real + other.imag * other.imag; // |other|^2
        return Complex((real * other.real + imag * other.imag) / denominator,
                       (imag * other.real - real * other.imag) / denominator);
    }
};

int main() {
    Complex c1, c2, c3; // Using only c1, c2, and c3
    int choice;

    // Input the two complex numbers from the user
    cout << "Enter the first complex number:" << endl;
    c1.input();

    cout << "Enter the second complex number:" << endl;
    c2.input();

    // Infinite loop for performing operations
    while (true) {
        // Display menu for user
        cout << "\nChoose an operation:" << endl;
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Addition
                c3 = c1 + c2; // Use overloaded + operator
                cout << "Addition: ";
                c3.display();
                break;
            case 2:
                // Subtraction using friend function
                c3 = c1 - c2; // Use overloaded - operator
                cout << "Subtraction: ";
                c3.display();
                break;
            case 3:
                // Multiplication
                c3 = c1 * c2; // Use overloaded * operator
                cout << "Multiplication: ";
                c3.display();
                break;
            case 4:
                // Division
                c3 = c1 / c2; // Use overloaded / operator
                cout << "Division: ";
                c3.display();
                break;
            case 5:
                // Exit the program
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
