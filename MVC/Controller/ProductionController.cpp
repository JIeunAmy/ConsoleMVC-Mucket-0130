#include "ProductionController.h"

#include <cmath>

namespace Controller
{
    ProductionController::ProductionController(std::vector<Model::Order>& orders, std::vector<Model::Sample>& samples, Model::ProductionLine& line)
        : orders_(orders)
        , samples_(samples)
        , line_(line)
    {
    }

    const std::deque<int>& ProductionController::PendingOrderIds() const
    {
        return line_.PendingOrderIds();
    }

    std::optional<Model::ProductionResult> ProductionController::ProcessNext()
    {
        if (line_.Empty())
        {
            return std::nullopt;
        }

        Model::Order* order = FindOrder(line_.Front());
        Model::Sample* sample = order ? FindSample(order->sampleId) : nullptr;
        if (order == nullptr || sample == nullptr)
        {
            line_.Dequeue();
            return std::nullopt;
        }

        int shortage = order->quantity - sample->stock;
        int actualQuantity = static_cast<int>(std::ceil(shortage / sample->yieldRate));
        double totalTime = sample->avgProductionTime * actualQuantity;

        sample->stock += actualQuantity - order->quantity;
        order->status = Model::OrderStatus::Confirmed;
        line_.Dequeue();

        return Model::ProductionResult{ order->id, actualQuantity, totalTime };
    }

    Model::Order* ProductionController::FindOrder(int orderId)
    {
        for (auto& order : orders_)
        {
            if (order.id == orderId)
            {
                return &order;
            }
        }
        return nullptr;
    }

    Model::Sample* ProductionController::FindSample(int sampleId)
    {
        for (auto& sample : samples_)
        {
            if (sample.id == sampleId)
            {
                return &sample;
            }
        }
        return nullptr;
    }
}
