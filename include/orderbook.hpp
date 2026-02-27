#pragma once

/*
Limit order  -> Enters the book if it cannot be matched immediately at the given price
Market order -> Matches immediately with the best available price
Cancel       -> Removes an existing order by its ID
Modify       -> Changes an existing order (cancel + new)

GTC -> Good Till Cancel
IOC -> Immediate Or Cancel
FOK -> Fill Or Kill
*/

class OrderBook {
public:
    enum class OrderType { Limit, Market, Cancel, Modify };
    enum class TimeInForce { GTC, IOC, FOK };
    enum class Side { Buy, Sell };

private:

}