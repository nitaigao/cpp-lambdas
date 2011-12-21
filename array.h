#include <functional>
#include <vector>

template<class T>
class Array {
  
  std::vector<T> data_;
  
public:
  
  Array() { };
  
  Array(std::initializer_list<T> data)
    : data_(data) { }
    
public:
  
  T operator[](T index) {
    return data_[index];
  }
    
public:
  
  void pushBack(const T& obj) {
    data_.push_back(obj);
  }
  
  void popBack() {
    data_.pop_back();
  }
  
  void each(const std::function<void(const T&)>& func) {
    for (T& o : data_) {
      func(o);
    }
  };
  
  template<class V>
  Array<V> map(const std::function<V(const T&)>& func) {
    Array<V> results;
    for (T& o : data_) {
      V result = func(o);
      results.pushBack(result);
    }
    return results;
  }
  
  template<class V>
  V reduce(V m, const std::function<V(V&, const T&)>& func) {
    for (T& o : data_) {
      func(m, o);
    }
    return m;
  };
  
};