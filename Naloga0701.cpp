#include <iostream>
#include "LinearQueue.h"
#include "Point.h"

int main() {
    try {
        std::cout << "--- INT ---" << std::endl;
        LinearQueue<int> intQueue;
        fillDefault(intQueue, 5);
        std::cout << "Vsebina: " << intQueue.toString() << std::endl;
        std::cout << "Prvi element: " << intQueue.element() << std::endl;
        std::cout << "Max: " << intQueue.getMax() << std::endl;
        intQueue.remove();
        std::cout << "Po odstranitvi: " << intQueue.toString() << std::endl;

        std::cout << "\n--- POINT ---" << std::endl;
        LinearQueue<Point> pointQueue;
        fillDefault(pointQueue, 3); // uporabi privzeti konstruktor
        pointQueue.add(Point(10, 10)); // eksplicitno dodana toèka
        std::cout << "Vsebina: " << pointQueue.toString() << std::endl;
        std::cout << "Max (najbolj oddaljena): " << pointQueue.getMax() << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Izjema: " << e.what() << std::endl;
    }

    return 0;
}

