//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "remove_duplicates.h"
using namespace std;

static void test_1_3() {
  int n = 0;
  cin >> n;
  vector<int> v1(n);
  for(auto& item: v1)
    cin >> item;
  auto it = remove_duplicates_if(v1.begin(), v1.end(), [](int a, int b) { return (a % 3 == 0) && (b % 3 == 0); });
  v1.erase(it, v1.end());
  for(const auto& item: v1)
    cout << item << " ";
  cout << endl;
}

TEST_CASE("Question #1.3") {
    execute_test("test_1_3.in", test_1_3);
}