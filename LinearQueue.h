#ifndef LINEARQUEUE_H
#define LINEARQUEUE_H

#include <vector>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Point.h"

// ===== Šablonski razred LinearQueue =====
template<typename T>
class LinearQueue {
private:
    std::vector<T> values;

public:
    int size() const {
        return values.size();
    }

    T element() const {
        if (values.empty()) throw std::out_of_range("Vrsta je prazna.");
        return values.front();
    }

    void add(const T& val) {
        values.push_back(val);
    }

    bool remove() {
        if (values.empty()) return false;
        values.erase(values.begin());
        return true;
    }

    std::string toString() const {
        std::stringstream ss;
        for (const auto& val : values) {
            ss << val << " ";
        }
        return ss.str();
    }

    T getMax() const {
        if (values.empty()) throw std::out_of_range("Vrsta je prazna.");
        T maxVal = values[0];
        for (const auto& val : values) {
            if (val > maxVal) maxVal = val;
        }
        return maxVal;
    }
};

// ===== Specializacija getMax za Point =====
template<>
Point LinearQueue<Point>::getMax() const {
    if (values.empty()) throw std::out_of_range("Vrsta je prazna.");

    auto distance = [](const Point& p) {
        std::stringstream ss;
        int x, y;
        ss << p;
        char c; // za oklepaje
        ss >> c >> x >> c >> y >> c;
        return std::sqrt(x * x + y * y);
        };

    Point maxPoint = values[0];
    double maxDist = distance(maxPoint);

    for (const auto& p : values) {
        double dist = distance(p);
        if (dist > maxDist) {
            maxPoint = p;
            maxDist = dist;
        }
    }

    return maxPoint;
}

// ===== Šablona funkcije fillDefault =====
template<typename T>
void fillDefault(LinearQueue<T>& q, int n) {
    for (int i = 0; i < n; ++i) {
        q.add(T());
    }
}
// ===== Specializacija fillDefault za int =====
template<>
void fillDefault<int>(LinearQueue<int>& q, int n) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    for (int i = 0; i < n; ++i) {
        q.add(std::rand() % 100); // nakljuène vrednosti od 0 do 99
    }
}
#endif // LINEARQUEUE_H
