#include "gtest/gtest.h"
#include <vector>
#include <algorithm>

TEST(SortingUTest, increasingSort) {
    std::vector<int> array = { 0, 4, 6, 1, 2, 3, 5 };
    std::sort(array.begin(), array.end());
    
    for (size_t i = 0; i < array.size()-1; i++) {
        ASSERT_TRUE(array[i] <= array[i + 1]);
    }
}

TEST(SortingUTest, decreasingSort) {
    std::vector<int> array = { 0, 4, 6, 1, 2, 3, 5 };
    std::sort(array.begin(), array.end(), [](int a, int b) {return a > b; });

    for (size_t i = 0; i < array.size() - 1; i++) {
        ASSERT_TRUE(array[i] >= array[i + 1]);
    }
}

TEST(SortingUTest, stableSort) {
    typedef std::pair < std::string, std::string > MusicTrack;

    std::vector<MusicTrack> array = {
        MusicTrack("R", "Rock"),
        MusicTrack("A", "Jazz"),
        MusicTrack("Z", "Jazz"),
        MusicTrack("Z", "Rock"),
        MusicTrack("B", "Pop"),
        MusicTrack("F", "Rock"),
        MusicTrack("C", "Jazz"),
        MusicTrack("A", "Pop"),
        MusicTrack("G", "Rock"),
        MusicTrack("T", "Rock")
    };

    std::stable_sort(array.begin(), array.end(), [](const MusicTrack& p1, const MusicTrack& p2) {return p1.first < p2.first; });
    std::stable_sort(array.begin(), array.end(), [](const MusicTrack& p1, const MusicTrack& p2) {return p1.second < p2.second; });
    
    for (size_t i = 0; i < array.size() - 1; i++) {
        ASSERT_TRUE(array[i].second <= array[i + 1].second);
        if (array[i].second == array[i + 1].second) {
            ASSERT_TRUE(array[i].first <= array[i + 1].first);
        }
    }
}