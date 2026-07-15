#pragma once

#include <vector>

#include "../Model/Order.h"

namespace Controller
{
    // CONFIRMED 상태 주문에 대한 출고 처리를 담당
    class ReleaseController
    {
    public:
        explicit ReleaseController(std::vector<Model::Order>& orders);

        const std::vector<Model::Order>& List() const;
        bool Release(int orderId);

    private:
        std::vector<Model::Order>& orders_;
    };
}
