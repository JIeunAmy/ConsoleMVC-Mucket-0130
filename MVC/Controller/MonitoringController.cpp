#include "MonitoringController.h"

namespace Controller
{
    MonitoringController::MonitoringController(const std::vector<Model::Order>& orders, const std::vector<Model::Sample>& samples)
        : orders_(orders)
        , samples_(samples)
    {
    }

    Model::OrderStatusSummary MonitoringController::SummarizeOrders() const
    {
        Model::OrderStatusSummary summary;
        for (const auto& order : orders_)
        {
            switch (order.status)
            {
            case Model::OrderStatus::Reserved:  summary.reserved++;  break;
            case Model::OrderStatus::Producing: summary.producing++; break;
            case Model::OrderStatus::Confirmed: summary.confirmed++; break;
            case Model::OrderStatus::Release:   summary.release++;   break;
            default: break; // REJECTED는 모니터링 대상에서 제외
            }
        }
        return summary;
    }

    std::vector<Model::StockStatus> MonitoringController::SummarizeStock() const
    {
        std::vector<Model::StockStatus> result;
        for (const auto& sample : samples_)
        {
            Model::StockStatus status;
            status.sampleId = sample.id;
            status.name = sample.name;
            status.stock = sample.stock;
            status.level = sample.stock == 0 ? Model::StockLevel::Depleted : Model::StockLevel::Sufficient;
            result.push_back(status);
        }
        return result;
    }
}
