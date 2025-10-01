#pragma once
#include "IPaymentProcessor.h"
#include "PaymentModes.h"
#include <map>
#include <memory>

void registerProcessors() {
    PaymentRegistry::instance().registerProcessor(
        PaymentMode::PayPal, std::make_unique<PayPalProcessor>());
    PaymentRegistry::instance().registerProcessor(
        PaymentMode::GooglePay, std::make_unique<GooglePayProcessor>());
    PaymentRegistry::instance().registerProcessor(
        PaymentMode::CreditCard, std::make_unique<CreditCardProcessor>());
}
class PaymentRegistry {
public:
    static PaymentRegistry& instance() {
        static PaymentRegistry registry;
        return registry;
    }

    void registerProcessor(PaymentMode mode, std::unique_ptr<IPaymentProcessor> processor) {
        processors[mode] = std::move(processor);
    }

    const IPaymentProcessor* getProcessor(PaymentMode mode) const {
        auto it = processors.find(mode);
        if (it != processors.end()) return it->second.get();
        return nullptr;
    }

private:
    std::map<PaymentMode, std::unique_ptr<IPaymentProcessor>> processors;
};
