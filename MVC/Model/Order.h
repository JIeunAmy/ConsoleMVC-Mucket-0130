#pragma once

#include <string>

namespace Model
{
    enum class OrderStatus
    {
        Reserved,  // 주문 접수
        Rejected,  // 주문 거절
        Producing, // 재고 부족으로 생산 중
        Confirmed, // 승인 완료 및 출고 대기 중
        Release    // 출고 완료
    };

    std::string ToString(OrderStatus status);

    struct Order
    {
        int id = 0;
        int sampleId = 0;
        std::string customerName;
        int quantity = 0;
        OrderStatus status = OrderStatus::Reserved;
    };
}
