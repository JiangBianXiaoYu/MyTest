#include <stdio.h>

// 交换数组中两个元素的位置
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 分区函数，将数组分为左右两个部分，左边的元素小于等于 pivot，右边的元素大于 pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // 选取最后一个元素作为 pivot
    int i = low - 1;  // 初始化较小元素的索引

    for (int j = low; j <= high - 1; j++) {
        // 如果当前元素小于等于 pivot，则将它与较小元素的下一个元素交换位置
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // 最后将 pivot 元素交换到正确的位置上
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// 快速排序函数
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // 对数组进行分区，并获取分区索引
        int pi = partition(arr, low, high);

        // 递归地对分区左边和右边的子数组进行排序
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 打印数组
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: \n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
