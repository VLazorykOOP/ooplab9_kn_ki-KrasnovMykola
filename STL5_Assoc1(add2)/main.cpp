#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

template <typename T>
class Vector {
private:
    vector<T> elements;
public:
    Vector(vector<T> v) {
        elements = v;
    }

    bool includes() {
        int half_size = elements.size() / 2;
        set<T> first_half(elements.begin(), elements.begin() + half_size);
        set<T> second_half(elements.begin() + half_size, elements.end());
        for (auto x : second_half) {
            if (first_half.find(x) == first_half.end()) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    cout << "INT" << endl;
  
    vector<int> v1{1, 2, 3, 4, 1, 4, 3, 2};
    Vector<int> vec1(v1);
    cout << boolalpha << vec1.includes() << endl; // true

    vector<int> v2{1, 2, 3, 4, 5, 6, 7, 8};
    Vector<int> vec2(v2);
    cout << boolalpha << vec2.includes() << endl; // false

    cout << endl << "FLOAT" << endl;
  
    vector<float> v3{1.0, 2.0, 3.0, 4.0, 1.0, 4.0, 3.0, 2.0};
    Vector<float> vec3(v3);
    cout << boolalpha << vec3.includes() << endl; // true

    vector<float> v4{1.7, 2.9, 3.3, 4.5, 5.4, 6.6, 7.2, 8.2};
    Vector<float> vec4(v4);
    cout << boolalpha << vec4.includes() << endl; // false
    
    return 0;
}
