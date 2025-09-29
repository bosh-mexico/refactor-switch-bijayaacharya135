#include <iostream>
#include <string>
#include <map>
using namespace std;

// Enum for Payment Modes
enum class PaymentMode {
    PayPal,
    GooglePay,
    CreditCard,
    Unknown
};

// Refactored: Use a map for messages to reduce cyclomatic complexity below 3
void checkout(PaymentMode mode, double amount) {
    static const map<PaymentMode, string> modeMessages = {
        {PaymentMode::PayPal,     "Processing PayPal payment of $"},
        {PaymentMode::GooglePay,  "Processing GooglePay payment of $"},
        {PaymentMode::CreditCard, "Processing Credit Card payment of $"}
    };

    auto it = modeMessages.find(mode);
    if (it != modeMessages.end()) {
        cout << it->second << amount << endl;
        // TODO: Integrate payment API here
    } else {
        cout << "Invalid payment mode selected!" << endl;
    }
}

int main() {
    double amount = 150.75;

    checkout(PaymentMode::PayPal, amount);
    checkout(PaymentMode::GooglePay, amount);
    checkout(PaymentMode::CreditCard, amount);
    checkout(PaymentMode::Unknown, amount);

    return 0;
}
