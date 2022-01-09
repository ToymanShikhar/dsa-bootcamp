// Expected Time Complexity: O(N)
// Expected Auxilliary Space: O(1)

void binSort(int A[], int N) {
    int i = 0;
    int j = N - 1;

    while (i <= j) {
        if (A[i] == 1) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            j--;
        } else {
            i++;
        }
    }
}