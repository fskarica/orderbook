#pragma once
#include "order.hpp"
#include <map>
#include <queue>

class OrderBook {
public:
    void process(const Order& o);

private:
    void handleLimit(const Order& o);
    void handleMarket(const Order& o);
    void handleCancel(const Order& o);
    void handleModify(const Order& o);

    void matchAgainstOppositeSide(const Order& incoming);
    void addRestingOrder(const Order& o);
    void removeOrderById(Order::OrderId id);

    std::map<Order::OrderId, Order> ordersById_;
    std::map<Order::Price, std::deque<Order::OrderId>, std::greater<Order::Price>> bids_;
    std::map<Order::Price, std::deque<Order::OrderId>> asks_;
};