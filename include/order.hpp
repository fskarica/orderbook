#pragma once
#include <cstdint>

/*
Limit order  -> Enters the book if it cannot be matched immediately at the given price
Market order -> Matches immediately with the best available price
Cancel       -> Removes an existing order by its ID
Modify       -> Changes an existing order (cancel + new)

GTC -> Good Till Cancel
IOC -> Immediate Or Cancel
FOK -> Fill Or Kill
*/

struct Order {
    enum class OrderType { Limit, Market, Cancel, Modify };
    enum class TimeInForce { GTC, IOC, FOK };
    enum class Side { Buy, Sell };

    using Price = std::int32_t;
    using OrderId = std::uint32_t;
    using Quantity = std::uint32_t;

    OrderType orderType;
    TimeInForce tif;

    Side side;
    OrderId id;
    Price price;
    Quantity quantity;
};