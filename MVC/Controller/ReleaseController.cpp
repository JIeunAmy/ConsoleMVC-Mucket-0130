#include "ReleaseController.h"

namespace Controller
{
    ReleaseController::ReleaseController(std::vector<Model::Order>& orders)
        : orders_(orders)
    {
    }

    const std::vector<Model::Order>& ReleaseController::List() const
    {
        return orders_;
    }

    bool ReleaseController::Release(int orderId)
    {
        for (auto& order : orders_)
        {
            if (order.id == orderId && order.status == Model::OrderStatus::Confirmed)
            {
                order.status = Model::OrderStatus::Release;
                return true;
            }
        }
        return false;
    }
}
