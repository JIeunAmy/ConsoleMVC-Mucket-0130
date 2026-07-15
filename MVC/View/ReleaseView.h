#pragma once

#include <string>
#include <vector>

#include "../Model/Order.h"

namespace View
{
    // 출고 처리 화면
    class ReleaseView
    {
    public:
        static void ShowConfirmedList(const std::vector<Model::Order>& orders);
        static void ShowMessage(const std::string& message);
    };
}
