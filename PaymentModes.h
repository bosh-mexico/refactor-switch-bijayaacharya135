#pragma once
#include <string>

// Enum for Payment Modes
enum class PaymentMode {
    PayPal,
    GooglePay,
    CreditCard,
    Unknown
};

// Processes payment and returns a confirmation message
std::string checkout(PaymentMode mode, double amount);
