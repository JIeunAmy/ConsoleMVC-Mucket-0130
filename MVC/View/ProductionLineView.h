#pragma once

#include <deque>
#include <optional>

#include "../Model/ProductionResult.h"

namespace View
{
    // 생산 라인 화면 - 대기 주문(생산 큐) 및 생산 현황 표시
    class ProductionLineView
    {
    public:
        static void ShowPendingQueue(const std::deque<int>& orderIds);
        static void ShowProductionResult(const std::optional<Model::ProductionResult>& result);
    };
}
