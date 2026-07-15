#include "ProductionLineView.h"

#include <iostream>

namespace View
{
    void ProductionLineView::ShowPendingQueue(const std::deque<int>& orderIds)
    {
        std::cout << "\n[생산 대기 큐] 총 " << orderIds.size() << "건 (FIFO)\n";
        for (int orderId : orderIds)
        {
            std::cout << "- 주문 #" << orderId << "\n";
        }
    }

    void ProductionLineView::ShowProductionResult(const std::optional<Model::ProductionResult>& result)
    {
        if (result.has_value())
        {
            std::cout << "생산 완료: 주문 #" << result->orderId
                       << ", 실 생산량 " << result->actualQuantity
                       << ", 총 생산 시간 " << result->totalTime << "\n";
        }
        else
        {
            std::cout << "생산 대기 중인 주문이 없습니다.\n";
        }
    }
}
