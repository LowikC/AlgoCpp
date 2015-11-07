#include <gtest/gtest.h>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

TEST(HashMapUTest, hashString) {
    std::unordered_map<std::string, int> name_to_count = {
        { "Bidule", 4 },
        { "Truc", 3 } 
    };

    name_to_count["Lowik"] = 1;
    name_to_count["Truc"] = 2;
    name_to_count["Lowik"] += 3;

    auto found_Cecile = name_to_count.find("Cecile");
    ASSERT_TRUE(found_Cecile == name_to_count.end());

    auto found_Lowik = name_to_count.find("Lowik");
    ASSERT_TRUE(found_Lowik != name_to_count.end());
    ASSERT_EQ(found_Lowik->second, 4);

    ASSERT_EQ(name_to_count["Lowik"], 4);
    ASSERT_EQ(name_to_count["Truc"], 2);
}


TEST(HashSetUTest, setString) {
    std::unordered_set<std::string> names = { "Bidule", "Truc" };

    names.insert("Lowik");

    names.erase("Bidule");

    auto found_Cecile = names.find("Cecile");
    ASSERT_TRUE(found_Cecile == names.end());

    auto found_Lowik = names.find("Lowik");
    ASSERT_TRUE(found_Lowik != names.end());

    ASSERT_TRUE(names.find("Bidule") == names.end());
}


template <typename T>
void unordered_set_intersection(const std::unordered_set<T>& s1, const std::unordered_set<T>& s2, std::unordered_set<T>& out) {
    for (auto e : s1) {
        if (s2.find(e) != s2.end()) {
            out.insert(e);
        }
    }
}

TEST(HashSetUTest, setStringOperations) {
    std::unordered_set<std::string> names1 = { "Bidule", "Truc" };
    std::unordered_set<std::string> names2 = { "Bidule", "Lowik" };
    std::unordered_set<std::string> intersection;
    unordered_set_intersection(names1, names2, intersection);

    ASSERT_EQ(intersection.size(), 1);
    ASSERT_TRUE(intersection.find("Bidule") != intersection.end());
}
