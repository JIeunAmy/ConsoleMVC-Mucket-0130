#include "ProductionLine.h"

namespace Model
{
    void ProductionLine::Enqueue(int orderId)
    {
        queue_.push_back(orderId);
    }

    void ProductionLine::Dequeue()
    {
        if (!queue_.empty())
        {
            queue_.pop_front();
        }
    }

    bool ProductionLine::Empty() const
    {
        return queue_.empty();
    }

    int ProductionLine::Front() const
    {
        return queue_.empty() ? -1 : queue_.front();
    }

    const std::deque<int>& ProductionLine::PendingOrderIds() const
    {
        return queue_;
    }
}
