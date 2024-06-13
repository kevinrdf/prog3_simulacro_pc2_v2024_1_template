//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "remove_duplicates.h"
#include <string>
using namespace std;

static void test_1_2() {
  int n = 0;
  cin >> n;
  vector<string> v1(n);
  for(auto& item: v1)
    cin >> item;
  auto it = remove_duplicates(v1.begin(), v1.end());
  v1.erase(it, v1.end());
  for(const auto& item: v1)
    cout << item << " ";
  cout << endl;
}

TEST_CASE("Question #1.2") {
    execute_test("test_1_2.in", test_1_2);
}