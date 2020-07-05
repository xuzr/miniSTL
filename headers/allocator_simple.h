#pragma once
#include<new>
#include<cstddef>
#include<cstdlib>
#include<climits>
#include<iostream>
using namespace std;
namespace xuzr
{
template
<typename T>
inline T* _allocate(ptrdiff_t size, T*)//ptrdiff_t保存两个指针相减的结果
{

    set_new_handler(0);//设置内存分配 new/ new[]调用失败后的处理函数，0为设置为默认
    T * tmp= (T *)(::operator new(static_cast<std::size_t>(sizeof(T)*size))); //operator new 调用全局运算符new 只分配空间，不调用初始化函数 关键字 new的第一步
    if(tmp==0)
    {
        cerr << "out of memory" << endl;
        exit(1);
    }
    return tmp;
}

template
<typename T>
inline void _deallocate(T* buffer)
{
    ::operator delete(buffer);
}

template
<typename T1,typename T2>
inline void _construct(T1 *p, const T2 &value)
{
    new (p) T1(value);//placement new
}

template
<typename T>
inline void _destory(T* ptr)
{
    ptr->~T();
}

template
<typename T>
class allocator
{
public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

    //rebind allocator of type U
    template <typename U>
    struct rebind{
        typedef allocator<U> other;
    };

    pointer allocate(size_type n, const void* hint=0)
    {
        return _allocate((difference_type)n, (pointer)0);
    }

    void deallocate(pointer p, size_type n)
    {
        _deallocate(p);
    }

    void construct(pointer p, const T& value)
    {
        _construct(p, value);
    }

    void destory(pointer p)
    {
        _destory(p);
    }

    pointer address(reference x)
    {
        return (pointer)&x;
    }
    const_pointer const_adress(const_reference x)
    {
        return (const_pointer)&x;
    }

    size_type max_size() const
    {
        return size_type(UINT_MAX / sizeof(T));
    }
};
}