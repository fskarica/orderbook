#include <iostream>
#include "../include/orderbook.hpp"

void OrderBook::process(const Order& o) {
    if (o.orderType == Order::OrderType::Limit) {
        handleLimit(o);
    }
    else if (o.orderType == Order::OrderType::Market) {
        handleMarket(o);
    }
    else if (o.orderType == Order::OrderType::Cancel) {
        handleCancel(o);
    }
    else if (o.orderType == Order::OrderType::Modify) {
        handleModify(o);
    }
}

void OrderBook::handleLimit(const Order& o) {
    if (o.tif == Order::TimeInForce::GTC) {

    }
    else if (o.tif == Order::TimeInForce::IOC) {
        
    }
    else if (o.tif == Order::TimeInForce::FOK) {
        
    }
}

void OrderBook::handleMarket(const Order& o) {
    if (o.tif == Order::TimeInForce::GTC) {

    }
    else if (o.tif == Order::TimeInForce::IOC) {
        
    }
    else if (o.tif == Order::TimeInForce::FOK) {
    }
}

void OrderBook::handleCancel(const Order& o) {
    if (!ordersById_.count(o.id)) return;
    ordersById_.erase(o.id);
}

void OrderBook::handleModify(const Order& o) {
    if (!ordersById_.count(o.id)) return;
    handleCancel(o);

    Order temp = o;
    temp.orderType = temp.orderTypeNew;
    if (temp.orderType == Order::OrderType::Limit) handleLimit(temp);
    else if (temp.orderType == Order::OrderType::Market) handleMarket(temp);
}

void OrderBook::matchAgainstOppositeSide(const Order& incoming) {

}

void OrderBook::addRestingOrder(const Order& o) {

}

void OrderBook::removeOrderById(Order::OrderId id) {

}