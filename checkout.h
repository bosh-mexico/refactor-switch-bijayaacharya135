#pragma once
#include "IPaymentProcessor.h"
#include "PaymentRegistry.h"
#include "PaymentMode.h"
#include <iostream>
#include <string>

inline void checkout(PaymentMode mode, double amount) {
    const IPaymentProcessor* processor = PaymentRegistry::instance().getProcessor(mode);
    if (processor) {
        std::cout << processor->process(amount) << std::endl;
    } else {
        std::cout << "Invalid payment mode selected!" << std::endl;
    }
}
