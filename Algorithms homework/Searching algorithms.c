
/*
//linearSearch
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}
int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    int result = linearSearch(arr, n, x);
    if (result == -1)
        printf("Element is not present in the array\n");
    else
        printf("Element is present at index %d\n", result);
    return 0;
}
*/




/*
//binary Search
int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 40;

    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        printf("Element is not present in the array\n");
    else
        printf("Element is present at index %d\n", result);
    return 0;
}
*/


/*
//Exponential Search
int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
int exponentialSearch(int arr[], int n, int x) {
    if (arr[0] == x)
        return 0;
    int i = 1;
    while (i < n && arr[i] <= x)
        i *= 2;
    return binarySearch(arr, i / 2, (i < n) ? i : n - 1, x);
}
int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 1;
    int result = exponentialSearch(arr, n, x);
    if (result == -1)
        printf("Element is not present in the array\n");
    else
        printf("Element is present at index %d\n", result);
    return 0;
}
*/



/*
//Interpolation search

int interpolationSearch(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]);
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main() {
    int arr[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 50;

    int result = interpolationSearch(arr, n, x);
    if (result == -1)
        printf("Element is not present in the array\n");
    else
        printf("Element is present at index %d\n", result);
    return 0;
}
*/

