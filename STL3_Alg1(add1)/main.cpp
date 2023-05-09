#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class VectorManipulator {
  protected: 
      vector<T> V;
  public:
      VectorManipulator(vector<T> v) {
          V = v;
      }
  
      void removeSecondZero() {
          auto first_zero = find(V.begin(), V.end(), T(0));
          if (first_zero == V.end()) { // нульових елементів не знайдено
              return;
          }
  
          auto second_zero = find(first_zero + 1, V.end(), T(0));
          if (second_zero == V.end()) { // знайдено менше двох нульових елементів
              return;
          }
  
          V.erase(second_zero);
      }

    void printVector() {
        for (auto& num : V) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> v1 = {1, 0, 3, 0, 5}; // вектор з двома нульовими елементами
    vector<int> v2 = {1, 0, 3, 5}; // вектор з менше ніж двома нульовими елементами
vector<float> v3 = {1.2f, 0.0f, 3.4f, 0.0f, 5.6f}; // вектор з двома нульовими елементами (типу float)
    vector<float> v4 = {1.2f, 0.0f, 3.4f, 5.6f}; // вектор з менше ніж двома нульовими елементами (типу float)

    VectorManipulator<int> vm1(v1);
    VectorManipulator<int> vm2(v2);
    VectorManipulator<float> vm3(v3);
    VectorManipulator<float> vm4(v4);

    vm1.removeSecondZero();
    vm2.removeSecondZero();
    vm3.removeSecondZero();
    vm4.removeSecondZero();

    cout << "v1: ";
    vm1.printVector(); // виводимо: 1 0 3 5

    cout << "v2: ";
    vm2.printVector(); // виводимо: 1 0 3 5

    cout << "v3: ";
    vm3.printVector(); // виводимо: 1.2 0 3.4 5.6

    cout << "v4: ";
    vm4.printVector(); // виводимо: 1.2 0 3.4 5.6
  
    return 0;
}
