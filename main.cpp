#include "checkout.h"
#include "PaymentMode.h"
#include "PaymentRegistry.h"
#include "PaymentProcessors.h"
#include <memory>

void registerProcessors() {
    PaymentRegistry::instance().registerProcessor(PaymentMode::PayPal, std::make_unique<PayPalProcessor>());
    PaymentRegistry::instance().registerProcessor(PaymentMode::GooglePay, std::make_unique<GooglePayProcessor>());
    PaymentRegistry::instance().registerProcessor(PaymentMode::CreditCard, std::make_unique<CreditCardProcessor>());
}

int main() {
    registerProcessors(); // SRP: registration is handled separately

    double amount = 150.75;
    checkout(PaymentMode::PayPal, amount);
    checkout(PaymentMode::GooglePay, amount);
    checkout(PaymentMode::CreditCard, amount);
    checkout(PaymentMode::Unknown, amount);

    return 0;
}
