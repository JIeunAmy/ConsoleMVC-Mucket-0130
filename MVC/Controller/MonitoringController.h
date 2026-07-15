#pragma once

#include <vector>

#include "../Model/MonitoringTypes.h"
#include "../Model/Order.h"
#include "../Model/Sample.h"

namespace Controller
{
    // 상태별 주문 수 및 시료별 재고 현황 확인을 담당
    class MonitoringController
    {
    public:
        MonitoringController(const std::vector<Model::Order>& orders, const std::vector<Model::Sample>& samples);

        Model::OrderStatusSummary SummarizeOrders() const;

        // TODO: 재고 대비 주문량을 반영한 여유 / 부족 / 고갈 판정 (현재는 재고량만으로 단순 판정)
        std::vector<Model::StockStatus> SummarizeStock() const;

    private:
        const std::vector<Model::Order>& orders_;
        const std::vector<Model::Sample>& samples_;
    };
}
