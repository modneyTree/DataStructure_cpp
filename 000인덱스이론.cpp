#include <iostream>
#include <vector>
using namespace std;

// 1. 투 포인터 (Two-Pointer) 예제
void twoPointerExample() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int target = 9;
    int left = 0, right = arr.size() - 1;
    bool found = false;
    
    cout << "=== Two-Pointer Example ===" << endl;
    while (left < right) {
        int current_sum = arr[left] + arr[right];
        if (current_sum == target) {
            cout << "정답: " << arr[left] << ", " << arr[right] << endl;
            found = true;
            break;
        } else if (current_sum < target) {
            left++;
        } else {
            right--;
        }
    }
    if (!found)
        cout << "정답을 찾지 못함." << endl;
    cout << endl;
}

// 2. 슬라이딩 윈도우 (Sliding Window) 예제
void slidingWindowExample() {
    vector<int> arr = {1, 3, 2, 5, 1, 1, 2, 3};
    int k = 3;  // 윈도우 크기
    int n = arr.size();
    
    cout << "=== Sliding Window Example ===" << endl;
    if (n < k) {
        cout << "배열의 크기가 윈도우 크기보다 작습니다." << endl;
        return;
    }

    int window_sum = 0;
    for (int i = 0; i < k; i++) {
        window_sum += arr[i];
    }
    int max_sum = window_sum;

    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];
        if (window_sum > max_sum)
            max_sum = window_sum;
    }
    cout << "최대 부분합: " << max_sum << endl;
    cout << endl;
}

// 3. 이진 탐색 (Binary Search) 예제
void binarySearchExample() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 5;
    int start = 0, end = arr.size() - 1;
    bool found = false;
    
    cout << "=== Binary Search Example ===" << endl;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == target) {
            cout << "찾은 인덱스: " << mid << endl;
            found = true;
            break;
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    if (!found)
        cout << "찾지 못함" << endl;
    cout << endl;
}

int main() {
    twoPointerExample();
    slidingWindowExample();
    binarySearchExample();
    
    return 0;
}
