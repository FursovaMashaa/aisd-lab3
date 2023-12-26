#pragma once
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <stdexcept>

using namespace std;
namespace sorts {
    struct stats {
        size_t comparison_count = 0;
        size_t copy_count = 0;
    };

    void quick_sort(vector<int>& list, int left, int right, stats& s) {
        if (left > right) { return; }
        int pivot_point = list[(left + right) / 2];
        int i = left;
        int j = right;
        while (i <= j) {
            while (list[i] < pivot_point) { 
                i++; s.comparison_count++; 
            }
            while (list[j] > pivot_point) { 
                j--; s.comparison_count++; 
            }
            if (i <= j) {
                int t = list[i];
                list[i] = list[j];
                list[j] = t;
                s.copy_count++;
                i++;
                j--;
            }

        }
        quick_sort(list, left, j, s);
        quick_sort(list, i, right, s);
    }
};