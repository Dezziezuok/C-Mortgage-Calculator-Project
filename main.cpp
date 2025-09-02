#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double principal;
    double interestRate;
    double annualInterestRate;
    int loanTerm;

    // Get user input
    std::cout << "Enter the loan principal amount: $";
    std::cin >> principal;

    std::cout << "Enter the annual interest rate (e.g., 4.5 for 4.5%): ";
    std::cin >> annualInterestRate;

    std::cout << "Enter the loan term in years: ";
    std::cin >> loanTerm;

    // Convert annual rate to monthly and years to months
    interestRate = annualInterestRate / 100 / 12;
    int numberOfPayments = loanTerm * 12;

    // Calculate monthly payment using the formula
    double monthlyPayment;
    if (interestRate > 0) {
        monthlyPayment = principal * (interestRate * std::pow(1 + interestRate, numberOfPayments)) / (std::pow(1 + interestRate, numberOfPayments) - 1);
    } else {
        monthlyPayment = principal / numberOfPayments;
    }

    // Calculate total payment and total interest
    double totalPayment = monthlyPayment * numberOfPayments;
    double totalInterest = totalPayment - principal;

    // Display the results
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n--- Mortgage Summary ---" << std::endl;
    std::cout << "Principal Amount: $" << principal << std::endl;
    std::cout << "Annual Interest Rate: " << annualInterestRate << "%" << std::endl;
    std::cout << "Loan Term: " << loanTerm << " years" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "Monthly Payment: $" << monthlyPayment << std::endl;
    std::cout << "Total Payment: $" << totalPayment << std::endl;
    std::cout << "Total Interest Paid: $" << totalInterest << std::endl;

    return 0;
}