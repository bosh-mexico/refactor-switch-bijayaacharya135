#include "PaymentModes.h"
#include <cassert>
#include <iostream>
#include <string>

// Simple test function for checkout
void test_checkout() {
    double amount = 150.75;

    // Test PayPal
    std::string result = checkout(PaymentMode::PayPal, amount);
    assert(result == "Processing PayPal payment of $150.750000");

    // Test GooglePay
    result = checkout(PaymentMode::GooglePay, amount);
    assert(result == "Processing GooglePay payment of $150.750000");

    // Test CreditCard
    result = checkout(PaymentMode::CreditCard, amount);
    assert(result == "Processing Credit Card payment of $150.750000");

    // Test Unknown
    result = checkout(PaymentMode::Unknown, amount);
    assert(result == "Invalid payment mode selected!");

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    test_checkout();
    return 0;
}
