#pragma once

#include <vector>

#include "../Model/MonitoringTypes.h"

namespace View
{
    // 모니터링 화면 - 상태별 주문 수 및 시료별 재고 현황 표시
    class MonitoringView
    {
    public:
        static void ShowOrderSummary(const Model::OrderStatusSummary& summary);
        static void ShowStockStatus(const std::vector<Model::StockStatus>& list);
    };
}
