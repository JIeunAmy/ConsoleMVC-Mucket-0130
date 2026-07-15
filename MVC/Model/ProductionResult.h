#pragma once

namespace Model
{
    struct ProductionResult
    {
        int orderId = 0;
        int actualQuantity = 0; // 실 생산량 = ceil(부족분 / 수율)
        double totalTime = 0.0; // 총 생산 시간 = 평균 생산시간 * 실 생산량
    };
}
