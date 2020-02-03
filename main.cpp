#include <iostream>

using namespace std;

//n个元素累加
int SumI(int A[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += A[i];
    }
    return sum;
}

int sum(int A[], int n) {
    return (n < 1) ? 0 : sum(A, n - 1) + A[n - 1];
}

//二分递归
int sum(int A[], int lo, int hi) {
    if (lo == hi)return A[lo];
    int mi = (lo + hi) >> 1;
    return sum(A, lo, mi) + sum(A, mi + 1, hi);
}


void reverse(int *A, int lo, int hi) {
    if (lo < hi) {
        swap(A[lo], A[hi]);
        reverse(A, lo + 1, hi - 1);
    }
}
//TODO
//实现max2
/*
 * Max2:迭代2
 * */
void max2(int A[], int lo, int hi, int &x1, int &x2) {
    if (A[x1 = lo] < A[x2 = lo + 1])swap(x1, x2);
    for (int i = lo + 2; i < hi; i++) {
        if (A[x2] < A[i])
            if (A[x1] < A[x2 = i])
                swap(x1, x2);
    }
}

//TODO
/*
 * max3:递归+分治
 * */
void max3(int A[], int lo, int hi, int &x1, int &x2) {
    if (lo + 2 == hi) {
        max2(A, lo, hi, x1, x2);
        return;
    }//T(2) =1
    if (lo + 3 == hi) {
        max2(A, lo, hi, x1, x2);
        return;
    }//T(3)<=3
    int mi = (lo + hi) / 2;//divide
    int x1L, x2L;
    max3(A, lo, mi, x1L, x2L);
    int x1R, x2R;
    max3(A, mi, hi, x1R, x2R);
    if (A[x1L] > A[x1R]) {
        x1 = x1L;
        x2 = (A[x2L] > A[x1R]) ? x2L : x1R;
    } else {
        x1 = x1R;
        x2 = (A[x1L] > A[x2R]) ? x1L : x2R;
    }
}




int main() {
    cout << "Hello, World!" << endl;

    return 0;
}
