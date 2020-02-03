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










int main() {
    cout << "Hello, World!" << endl;

    return 0;
}
