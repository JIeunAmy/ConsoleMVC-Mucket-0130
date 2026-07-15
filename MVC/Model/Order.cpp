#include "Order.h"

namespace Model
{
    std::string ToString(OrderStatus status)
    {
        switch (status)
        {
        case OrderStatus::Reserved:  return "RESERVED";
        case OrderStatus::Rejected:  return "REJECTED";
        case OrderStatus::Producing: return "PRODUCING";
        case OrderStatus::Confirmed: return "CONFIRMED";
        case OrderStatus::Release:   return "RELEASE";
        }
        return "UNKNOWN";
    }
}
