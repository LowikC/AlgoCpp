#include "gtest/gtest.h"
#include <thread>
#include <iostream>
#include <mutex>

void increment(int& count, std::mutex* m) {
    m->lock();
    count += 1;
    m->unlock();
}

TEST(ThreadTest, StartTwoThreads) {
    int i = 0;
    std::mutex mutex_i;
    std::thread t1(&increment, std::ref(i), &mutex_i);
    std::thread t2(&increment, std::ref(i), &mutex_i);

    t1.join();
    t2.join();

    ASSERT_EQ(i, 2);
}


TEST(ThreadTest, StartSeveralThreads) {
    int counter = 0;
    std::mutex mutex_count;
    std::vector<std::thread> threads;
    const int n_threads = 20;
    for (int i = 0; i < n_threads; i++) {
        threads.push_back(std::thread(&increment, std::ref(counter), &mutex_count));
    }

    for (int i = 0; i < n_threads; i++) {
        threads[i].join();
    }

    ASSERT_EQ(counter, n_threads);
}