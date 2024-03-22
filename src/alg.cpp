// Copyright 2021 NNTU-CS
int binSearch(int* arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > value) {
            right = mid - 1;
        } else {
            if (arr[mid] < value) {
                left = mid + 1;
            } else {
                count++;
                int left = mid - 1;
                int right = mid + 1;
                while ((left >= 0) && (arr[left] == value)) {
                    count++;
                    left--;
                }
                while ((right < len) && (arr[right] == value)) {
                    count++;
                    right++;
                }
                return count;
            }
        }
    return count;
    }
    return 0;
}
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = (i + 1); j < len; j++) {
            if ((arr[i] + arr[j]) == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (arr[right] > value) {
        right = right - 1;
    }
    for (int i = 0; i < right; i++) {
        for (int j = right; j > i; j--) {
            int sum = arr[i] + arr[j];
            if (sum == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int second = value - arr[i];
        count += binSearch(&arr[i + 1], len - i - 1, second);
    }
    return count;
}
