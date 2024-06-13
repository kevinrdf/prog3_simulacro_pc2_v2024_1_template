//
// Created by rudri on 9/12/2020.
//
#include <iostream>
#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
#include "catch.hpp"
#include "redirect_io.h"
#include "find_max_triple_product.h"
using namespace std;

static void question_2_1(){
    vector<long long int> vec;
    int n;
    while (cin >> n) vec.push_back(n);
    auto result = find_max_triple_product(vec);
    cout << result << endl;
}

static void question_2_2(){
    list<long double> lst;
    long double n;
    while (cin >> n) lst.push_back(n);
    auto result = find_max_triple_product(lst);
    cout << fixed << setprecision(2) << result << endl;
}


TEST_CASE("Question #2.1") {
    execute_test("test_2_1.in", question_2_1);
}

TEST_CASE("Question #2.2") {
    execute_test("test_2_2.in", question_2_2);
}