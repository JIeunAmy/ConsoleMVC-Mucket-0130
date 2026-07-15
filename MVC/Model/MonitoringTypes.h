#pragma once

#include <string>
#include <vector>

namespace Model
{
    // 상태별 주문 수 (REJECTED는 정상 흐름 밖이므로 집계에서 제외)
    struct OrderStatusSummary
    {
        int reserved = 0;
        int producing = 0;
        int confirmed = 0;
        int release = 0;
    };

    enum class StockLevel
    {
        Sufficient, // 여유
        Shortage,   // 부족
        Depleted    // 고갈
    };

    struct StockStatus
    {
        int sampleId = 0;
        std::string name;
        int stock = 0;
        StockLevel level = StockLevel::Sufficient;
    };
}
