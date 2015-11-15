#include "EPI_20.3.hpp"
#include <mutex>
#include <thread>
#include <condition_variable>

class Monitor {
public:
    Monitor() : odd_turn(false) {}

    void waitTurn(bool odd) {
        std::unique_lock<std::mutex> lk(m_turn);
        cv_turn.wait(lk, [this, odd] {return odd_turn == odd; });
    }

    void toggleTurn() {
        std::lock_guard<std::mutex> lg(m_turn);
        odd_turn = !odd_turn;
        cv_turn.notify_all();
    }

private:
    std::condition_variable cv_turn;
    std::mutex m_turn;
    bool odd_turn;

};

void printOdd(std::ostream& out, Monitor& m) {
    for (int i = 1; i < 100; i += 2) {
        m.waitTurn(true);
        out << i << ", ";
        m.toggleTurn();
    }
} 

void printEven(std::ostream& out, Monitor& m) {
    for (int i = 0; i < 100; i += 2) {
        m.waitTurn(false);
        out << i << ", ";
        m.toggleTurn();
    }
}

void printThreaded(std::ostream& out) {
    Monitor m;
    std::thread t1(printOdd, std::ref(out), std::ref(m));
    std::thread t2(printEven, std::ref(out), std::ref(m));

    t1.join();
    t2.join();

}