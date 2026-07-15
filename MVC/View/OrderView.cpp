#include "OrderView.h"

#include <iostream>

namespace View
{
    int OrderView::ShowMenuAndGetChoice()
    {
        std::cout << "\n--- 주문 ---\n";
        std::cout << "1. 주문 접수\n";
        std::cout << "2. 주문 승인\n";
        std::cout << "3. 주문 거절\n";
        std::cout << "0. 뒤로가기\n";
        std::cout << "선택: ";

        int choice = -1;
        std::cin >> choice;
        return choice;
    }

    void OrderView::ShowList(const std::vector<Model::Order>& orders)
    {
        std::cout << "\n[주문 목록] 총 " << orders.size() << "건\n";
        for (const auto& order : orders)
        {
            std::cout << "- #" << order.id << " " << order.customerName
                       << " (시료 #" << order.sampleId << ", 수량 " << order.quantity
                       << ", " << Model::ToString(order.status) << ")\n";
        }
    }

    void OrderView::ShowMessage(const std::string& message)
    {
        std::cout << message << "\n";
    }
}
