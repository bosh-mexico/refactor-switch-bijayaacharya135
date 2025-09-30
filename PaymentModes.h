#pragma once
#include <string>

// Enum for Payment Modes
enum class PaymentMode {
    PayPal,
    GooglePay,
    CreditCard,
    Unknown
};
std::string checkout(PaymentMode mode, double amount);
