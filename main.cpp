#include "build/checkout.h"
#include "build/PaymentModes.h"
#include "build/PaymentRegistry.h"
#include "build/PaymentProcessors.h"
#include "build/PaymentRegistration.h"
#include <memory>
#include <iostream>
#include <string>

int main() {
    registerProcessors();

    double amount = 150.75;
    checkout(PaymentMode::PayPal, amount);
    checkout(PaymentMode::GooglePay, amount);
    checkout(PaymentMode::CreditCard, amount);
    checkout(PaymentMode::Unknown, amount);

    return 0;
}
