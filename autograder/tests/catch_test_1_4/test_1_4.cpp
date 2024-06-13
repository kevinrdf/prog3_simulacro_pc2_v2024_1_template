//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "remove_duplicates.h"
using namespace std;

struct Person {
  int id{};
  string name;
};

static void test_1_4() {
  int n = 0;
  cin >> n;
  vector<Person> vec(n);
  for(auto& item: vec) {
    cin >> item.id >> item.name;
  }
  auto it = remove_duplicates_if(vec.begin(), vec.end(), [](const Person& a, const Person& b) { return a.id == b.id; });
  vec.erase(it, vec.end());
  for(const auto& item: vec) {
    if (item.id != 0) {  // Assuming 0 is not a valid ID, to filter out the default initialized values
      cout << item.id << " " << item.name << std::endl;
    }
  }
  cout << endl;
}

TEST_CASE("Question #1.4") {
    execute_test("test_1_4.in", test_1_4);
}