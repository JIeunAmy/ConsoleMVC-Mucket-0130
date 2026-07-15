#include "ReleaseView.h"

#include <iostream>

namespace View
{
    void ReleaseView::ShowConfirmedList(const std::vector<Model::Order>& orders)
    {
        std::cout << "\n[출고 대기 (CONFIRMED) 목록]\n";
        for (const auto& order : orders)
        {
            if (order.status == Model::OrderStatus::Confirmed)
            {
                std::cout << "- #" << order.id << " " << order.customerName
                           << " (수량 " << order.quantity << ")\n";
            }
        }
    }

    void ReleaseView::ShowMessage(const std::string& message)
    {
        std::cout << message << "\n";
    }
}
