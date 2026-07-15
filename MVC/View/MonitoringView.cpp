#include "MonitoringView.h"

#include <iostream>

namespace View
{
    namespace
    {
        const char* ToString(Model::StockLevel level)
        {
            switch (level)
            {
            case Model::StockLevel::Sufficient: return "여유";
            case Model::StockLevel::Shortage:   return "부족";
            case Model::StockLevel::Depleted:   return "고갈";
            }
            return "알 수 없음";
        }
    }

    void MonitoringView::ShowOrderSummary(const Model::OrderStatusSummary& summary)
    {
        std::cout << "\n[상태별 주문 수]\n";
        std::cout << "RESERVED : " << summary.reserved << "\n";
        std::cout << "PRODUCING: " << summary.producing << "\n";
        std::cout << "CONFIRMED: " << summary.confirmed << "\n";
        std::cout << "RELEASE  : " << summary.release << "\n";
    }

    void MonitoringView::ShowStockStatus(const std::vector<Model::StockStatus>& list)
    {
        std::cout << "\n[시료별 재고 현황]\n";
        for (const auto& status : list)
        {
            std::cout << "- #" << status.sampleId << " " << status.name
                       << " (재고 " << status.stock << ", " << ToString(status.level) << ")\n";
        }
    }
}
