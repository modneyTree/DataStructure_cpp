좋아! 😊  
코딩테스트에서 자주 등장하는 **`vector`의 중복 제거**에 대해  
**가장 실용적인 방식만** 골라서 **깔끔하게 정리**해줄게!

---

# ✅ 코딩테스트용 `vector` 중복 제거 완벽 정리

---

## ✅ 1. **정렬된 결과가 필요할 때**

### 🔹 방법: `sort + unique + erase`

```cpp
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
```

### 📌 특징:
- 중복 제거 + 정렬까지 한 번에 처리됨
- 시간복잡도: `O(N log N)`
- ✨ **가장 많이 쓰이는 기본형**

---

## ✅ 2. **정렬 상관없이 빠르게 중복 제거할 때**

### 🔹 방법: `unordered_set`

```cpp
unordered_set<int> s(v.begin(), v.end());
vector<int> result(s.begin(), s.end());
```

### 📌 특징:
- 순서 보장 ❌ (정렬되지 않음)
- 중복 제거는 매우 빠름 (`O(N)` 평균)
- 정렬이 불필요한 경우 최적

---

## ✅ 3. **입력 순서 유지하면서 중복 제거할 때**

### 🔹 방법: `unordered_set + loop`

```cpp
unordered_set<int> seen;
vector<int> result;

for (int x : v) {
    if (seen.count(x) == 0) {
        seen.insert(x);
        result.push_back(x);
    }
}
```

### 📌 특징:
- 중복 제거하면서 **입력 순서 그대로 유지**
- 필요 시 가장 정확한 방법 (단, 코드 길어짐)

---

# 🎯 정리표

| 상황 | 추천 방법 | 특징 |
|------|-----------|------|
| **정렬 + 중복 제거** | `sort + unique + erase` | 가장 자주 쓰임 / 깔끔 |
| **빠른 제거 (순서 무시)** | `unordered_set` | O(N), 간단 |
| **순서 유지 + 중복 제거** | `unordered_set + for` | 신중한 상황에서 사용 |

---

# ✨ 실전 팁

- 외워두기 좋은 기본형 👇

```cpp
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
```

- `pair`, `string` 등도 가능 (`sort`와 `==` 연산 가능하면 OK)

---

필요하면 `pair` 중복 제거, 사용자 정의 타입 처리법, 정렬 기준 커스터마이징까지도 알려줄게!  
어떤 방향으로 더 확장할까? 😄