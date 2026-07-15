#pragma once

#include <deque>
#include <optional>
#include <vector>

#include "../Model/Order.h"
#include "../Model/ProductionLine.h"
#include "../Model/ProductionResult.h"
#include "../Model/Sample.h"

namespace Controller
{
    // 생산 큐(FIFO) 진행 및 생산 완료 처리를 담당
    class ProductionController
    {
    public:
        ProductionController(std::vector<Model::Order>& orders, std::vector<Model::Sample>& samples, Model::ProductionLine& line);

        const std::deque<int>& PendingOrderIds() const;
        std::optional<Model::ProductionResult> ProcessNext();

    private:
        Model::Order* FindOrder(int orderId);
        Model::Sample* FindSample(int sampleId);

        std::vector<Model::Order>& orders_;
        std::vector<Model::Sample>& samples_;
        Model::ProductionLine& line_;
    };
}
