#pragma once

#include <string>

namespace Model
{
    struct Sample
    {
        int id = 0;
        std::string name;
        double avgProductionTime = 0.0; // 평균 생산시간
        double yieldRate = 1.0;         // 수율 (0.0 ~ 1.0)
        int stock = 0;                  // 재고 수량
    };
}
