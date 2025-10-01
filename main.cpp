#include "refactor-switch-bijayaacharya135/checkout.h"
#include "refactor-switch-bijayaacharya135/PaymentModes.h"
#include "refactor-switch-bijayaacharya135/PaymentRegistry.h"
#include "refactor-switch-bijayaacharya135/PaymentProcessors.h"
#include "refactor-switch-bijayaacharya135/PaymentRegistration.h"
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
