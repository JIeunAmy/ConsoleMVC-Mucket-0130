#pragma once

#include <string>
#include <vector>

#include "../Model/Order.h"
#include "../Model/ProductionLine.h"
#include "../Model/Sample.h"

namespace Controller
{
    // 주문 접수 / 승인 / 거절을 담당
    class OrderController
    {
    public:
        OrderController(std::vector<Model::Order>& orders, std::vector<Model::Sample>& samples, Model::ProductionLine& line);

        int PlaceOrder(int sampleId, const std::string& customerName, int quantity);
        const std::vector<Model::Order>& List() const;
        bool Approve(int orderId);
        bool Reject(int orderId);

    private:
        Model::Order* FindById(int orderId);
        Model::Sample* FindSample(int sampleId);

        std::vector<Model::Order>& orders_;
        std::vector<Model::Sample>& samples_;
        Model::ProductionLine& line_;
    };
}
