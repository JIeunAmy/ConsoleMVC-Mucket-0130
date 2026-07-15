#pragma once

#include <deque>

namespace Model
{
    // 생산 큐 (FIFO) - 재고 부족으로 생산이 필요한 주문을 대기시킨다.
    class ProductionLine
    {
    public:
        void Enqueue(int orderId);
        void Dequeue();
        bool Empty() const;
        int Front() const;
        const std::deque<int>& PendingOrderIds() const;

    private:
        std::deque<int> queue_;
    };
}
