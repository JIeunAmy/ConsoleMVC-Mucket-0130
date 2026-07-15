#include "OrderController.h"

namespace Controller
{
    OrderController::OrderController(std::vector<Model::Order>& orders, std::vector<Model::Sample>& samples, Model::ProductionLine& line)
        : orders_(orders)
        , samples_(samples)
        , line_(line)
    {
    }

    int OrderController::PlaceOrder(int sampleId, const std::string& customerName, int quantity)
    {
        Model::Order order;
        order.id = static_cast<int>(orders_.size()) + 1;
        order.sampleId = sampleId;
        order.customerName = customerName;
        order.quantity = quantity;
        order.status = Model::OrderStatus::Reserved;

        orders_.push_back(order);
        return order.id;
    }

    const std::vector<Model::Order>& OrderController::List() const
    {
        return orders_;
    }

    bool OrderController::Approve(int orderId)
    {
        Model::Order* order = FindById(orderId);
        Model::Sample* sample = order ? FindSample(order->sampleId) : nullptr;
        if (order == nullptr || sample == nullptr)
        {
            return false;
        }

        if (sample->stock >= order->quantity)
        {
            sample->stock -= order->quantity;
            order->status = Model::OrderStatus::Confirmed;
        }
        else
        {
            order->status = Model::OrderStatus::Producing;
            line_.Enqueue(order->id);
        }
        return true;
    }

    bool OrderController::Reject(int orderId)
    {
        Model::Order* order = FindById(orderId);
        if (order == nullptr)
        {
            return false;
        }

        order->status = Model::OrderStatus::Rejected;
        return true;
    }

    Model::Order* OrderController::FindById(int orderId)
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

    Model::Sample* OrderController::FindSample(int sampleId)
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
