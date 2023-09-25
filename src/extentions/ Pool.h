#ifndef POOL_H
#define POOL_H

#include <vector>

template <typename T>
class Pool 
{
public:
    Pool(int count);
    T* GetFreeElement();
    bool HasFreeElement() const;

private:
    std::vector<T> pool;
};

template <typename T>
Pool<T>::Pool(int count) 
{
    pool.reserve(count);
    for (int i = 0; i < count; ++i) 
    {
        pool.push_back(T());
    }
}

template <typename T>
T* Pool<T>::GetFreeElement() 
{
    for (auto& item : pool) {
        if (!item.IsActive()) {
            item.SetActive(true);
            return &item;
        }
    }
    return nullptr;
}

template <typename T>
bool Pool<T>::HasFreeElement() const 
{
    for (const auto& item : pool) 
    {
        if (!item.IsActive()) 
        {
            return true;
        }
    }
    return false;
}

#endif  // POOL_H
