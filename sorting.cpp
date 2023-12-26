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

    void insertionSort(vector<int>& list, stats& s) {
        for (int i = 1; i < list.size(); i++) {
            int key = list[i];
            int j = i - 1;

            while (j >= 0 && list[j] > key) {
                list[j + 1] = list[j];
                j--;
                s.comparison_count++;
                s.copy_count++;
            }

            list[j + 1] = key;
            s.copy_count++;
        }
    }


    void quickSort(vector<int>& list, int left, int right, stats& s) {
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
        quickSort(list, left, j, s);
        quickSort(list, i, right, s);
    }

    void merge_sort(vector<int>& list, stats& s) {
        if (list.size() <= 1) {
            return;
        }

        vector<int> left(list.begin(), list.begin() + list.size() / 2);
        vector<int> right(list.begin() + list.size() / 2, list.end());

        merge_sort(left, s);
        merge_sort(right, s);

        vector<int> merged(list.size());
        int i = 0, j = 0;
        while (i < left.size() && j < right.size()) {
            s.comparison_count++;
            if (left[i] < right[j]) {
                merged[i + j] = left[i];
                i++;
            }
            else {
                merged[i + j] = right[j];
                j++;
            }
        }
        while (i < left.size()) {
            merged[i + j] = left[i];
            i++;
        }
        while (j < right.size()) {
            merged[i + j] = right[j];
            j++;
        }

        for (int k = 0; k < list.size(); k++) {
            list[k] = merged[k];
            s.copy_count++;
        }
    }

};