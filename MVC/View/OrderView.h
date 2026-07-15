#pragma once

#include <string>
#include <vector>

#include "../Model/Order.h"

namespace View
{
    // 주문 화면 - 접수 / 승인 / 거절
    class OrderView
    {
    public:
        static int ShowMenuAndGetChoice();
        static void ShowList(const std::vector<Model::Order>& orders);
        static void ShowMessage(const std::string& message);
    };
}
