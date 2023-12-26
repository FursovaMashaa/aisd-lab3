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

    stats one_rand_insertion(int size, int seed) {
        stats s;
        vector<int> t;
        mt19937 generator(seed);
        uniform_int_distribution<> distribution(0, 10000);
        for (int i = 0; i < size; i++) { t.push_back(distribution(generator)); }
        insertionSort(t, s);
        return s;
    }

    void cycle_rand_insertion() {
        int len[] = { 1000,3000,5000,10000,25000,50000,100000 };
        ofstream fout;
        fout.open("C:\\Users\\furso\\Desktop\\aisd-lab3\\insertionSort_rand.txt");
        for (int i = 0; i < 7; i++) {
            stats s;
            for (int j = 0; j < 100; j++) {
                stats t;
                t = one_rand_insertion(len[i], j * 10 + i);
                s.comparison_count += t.comparison_count;
                s.copy_count += t.copy_count;
            }
            s.comparison_count /= 100;
            s.copy_count /= 100;
            if (fout.is_open()) { fout << len[i] << " " << s.comparison_count << " " << s.copy_count << endl; }
        }
        fout.close();
    }
    stats one_ord_insertion(int size) {
        stats s;
        vector<int> t;
        for (int i = 0; i < size; i++) { t.push_back(i); }
        insertionSort(t, s);
        return s;
    }

    void cycle_ord_insertion() {
        int len[] = { 1000,3000,5000,10000,25000,50000,100000 };
        ofstream fout;
        fout.open("C:\\Users\\furso\\Desktop\\aisd-lab3\\insertionSort_order.txt");
        for (int i = 0; i < 7; i++) {
            stats s;
            for (int j = 0; j < 100; j++) {
                stats t;
                t = one_ord_insertion(len[i]);
                s.comparison_count += t.comparison_count;
                s.copy_count += t.copy_count;
            }
            s.comparison_count /= 100;
            s.copy_count /= 100;
            if (fout.is_open()) { fout << len[i] << " " << s.comparison_count << " " << s.copy_count << endl; }
        }
        fout.close();
    }

    stats one_revers_insertion(int size) {
        stats s;
        vector<int> t;
        for (int i = size; i > 0; i--) { 
            t.push_back(i); 
        }
        insertionSort(t, s);
        return s;
    }

    void cycle_revers_insertion() {
        int len[] = { 1000,3000,5000,10000,25000,50000,100000 };
        ofstream fout;
        fout.open("C:\\Users\\furso\\Desktop\\aisd-lab3\\insertionSort_revers.txt");
        for (int i = 0; i < 7; i++) {
            stats s;
            for (int j = 0; j < 100; j++) {
                stats t;
                t = one_revers_insertion(len[i]);
                s.comparison_count += t.comparison_count;
                s.copy_count += t.copy_count;
            }
            s.comparison_count /= 100;
            s.copy_count /= 100;
            if (fout.is_open()) { fout << len[i] << " " << s.comparison_count << " " << s.copy_count << endl; }
        }
        fout.close();
    }




    stats one_rand_quick(int size, int seed) {
        stats s;
        vector<int> t;
        mt19937 generator(seed);
        uniform_int_distribution<> distribution(0, 10000);
        for (int i = 0; i < size; i++) { t.push_back(distribution(generator)); }
        quickSort(t, 0, t.size() - 1, s);
        return s;
    }

    void cycle_rand_quick() {
        int len[] = { 1000,3000,5000,10000,25000,50000,100000 };
        ofstream fout;
        fout.open("C:\\Users\\furso\\Desktop\\aisd-lab3\\quickSort_rand.txt");
        for (int i = 0; i < 7; i++) {
            stats s;
            for (int j = 0; j < 100; j++) {
                stats t;
                t = one_rand_quick(len[i], j * 10 + i);
                s.comparison_count += t.comparison_count;
                s.copy_count += t.copy_count;
            }
            s.comparison_count /= 100;
            s.copy_count /= 100;
            if (fout.is_open()) { fout << len[i] << " " << s.comparison_count << " " << s.copy_count << endl; }
        }
        fout.close();
    }
    stats one_ord_quick(int size) {
        stats s;
        vector<int> t;
        for (int i = 0; i < size; i++) { t.push_back(i); }
        quickSort(t, 0, t.size() - 1, s);
        return s;
    }

    void cycle_ord_quick() {
        int len[] = { 1000,3000,5000,10000,25000,50000,100000 };
        ofstream fout;
        fout.open("C:\\Users\\furso\\Desktop\\aisd-lab3\\quickSort_order.txt");
        for (int i = 0; i < 7; i++) {
            stats s;
            for (int j = 0; j < 100; j++) {
                stats t;
                t = one_ord_quick(len[i]);
                s.comparison_count += t.comparison_count;
                s.copy_count += t.copy_count;
            }
            s.comparison_count /= 100;
            s.copy_count /= 100;
            if (fout.is_open()) { fout << len[i] << " " << s.comparison_count << " " << s.copy_count << endl; }
        }
        fout.close();
    }

    stats one_revers_quick(int size) {
        stats s;
        vector<int> t;
        for (int i = size; i > 0; i--) {
            t.push_back(i);
        }
        quickSort(t, 0, t.size() - 1, s);
        return s;
    }

    void cycle_revers_quick() {
        int len[] = { 1000,3000,5000,10000,25000,50000,100000 };
        ofstream fout;
        fout.open("C:\\Users\\furso\\Desktop\\aisd-lab3\\quickSort_revers.txt");
        for (int i = 0; i < 7; i++) {
            stats s;
            for (int j = 0; j < 100; j++) {
                stats t;
                t = one_revers_quick(len[i]);
                s.comparison_count += t.comparison_count;
                s.copy_count += t.copy_count;
            }
            s.comparison_count /= 100;
            s.copy_count /= 100;
            if (fout.is_open()) { fout << len[i] << " " << s.comparison_count << " " << s.copy_count << endl; }
        }
        fout.close();
    }



};