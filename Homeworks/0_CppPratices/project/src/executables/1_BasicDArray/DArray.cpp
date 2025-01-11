// implementation of class DArray
#include "DArray.h"
#include <iostream>
#include <cstdlib>

// 默认构造函数
DArray::DArray() {
    Init();
}

// 使用指定大小和默认值初始化数组
DArray::DArray(int nSize, double dValue) {
    // 先初始化数组相关成员
    Init();
    // 设置数组大小
    SetSize(nSize);
    // 为每个元素赋默认值
    for (int i = 0; i < nSize; ++i) {
        SetAt(i, dValue);
    }
}

// 拷贝构造函数
DArray::DArray(const DArray& arr) {
    // 先初始化自身数组
    Init();
    // 设置大小与被拷贝数组相同
    SetSize(arr.GetSize());
    // 逐个元素拷贝
    for (int i = 0; i < arr.GetSize(); ++i) {
        SetAt(i, arr.GetAt(i));
    }
}

// 析构函数
DArray::~DArray() {
    Free();
}

// 显示数组元素
void DArray::Print() const {
    for (int i = 0; i < GetSize(); ++i) {
        std::cout << GetAt(i) << " ";
    }
    std::cout << std::endl;
}

// 初始化数组（分配内存等操作）
void DArray::Init() {
    m_pData = nullptr;
    m_nSize = 0;
}

// 释放数组内存
void DArray::Free() {
    if (m_pData != nullptr) {
        delete[] m_pData;
        m_pData = nullptr;
    }
    m_nSize = 0;
}

// 获取数组大小
int DArray::GetSize() const {
    return m_nSize;
}

// 设置数组大小
void DArray::SetSize(int nSize) {
    if (nSize < 0) {
        return;
    }
    // 如果大小改变，需要重新分配内存
    if (nSize != m_nSize) {
        double* pNewData = new double[nSize];
        int nCopySize = (nSize < m_nSize) ? nSize : m_nSize;
        for (int i = 0; i < nCopySize; ++i) {
            pNewData[i] = m_pData[i];
        }
        // 释放旧内存
        Free();
        m_pData = pNewData;
        m_nSize = nSize;
    }
}

// 获取指定索引处的元素
const double& DArray::GetAt(int nIndex) const {
    if (nIndex >= 0 && nIndex < m_nSize) {
        return m_pData[nIndex];
    }
    // 这里可以考虑抛出异常或者按需求返回合适的错误表示
    static double ERROR;
    return ERROR;
}

// 设置指定索引处元素的值
void DArray::SetAt(int nIndex, double dValue) {
    if (nIndex >= 0 && nIndex < m_nSize) {
        m_pData[nIndex] = dValue;
    }
}

// 重载 [] 操作符
const double& DArray::operator[](int nIndex) const {
    return GetAt(nIndex);
}

// 在数组末尾添加新元素
void DArray::PushBack(double dValue) {
    int newSize = m_nSize + 1;
    SetSize(newSize);
    SetAt(newSize - 1, dValue);
}

// 删除指定索引处的元素
void DArray::DeleteAt(int nIndex) {
    if (nIndex < 0 || nIndex >= m_nSize) {
        return;
    }
    for (int i = nIndex; i < m_nSize - 1; ++i) {
        m_pData[i] = m_pData[i + 1];
    }
    SetSize(m_nSize - 1);
}

// 在指定索引处插入新元素
void DArray::InsertAt(int nIndex, double dValue) {
    if (nIndex < 0 || nIndex > m_nSize) {
        return;
    }
    int newSize = m_nSize + 1;
    SetSize(newSize);
    for (int i = m_nSize - 1; i > nIndex; --i) {
        m_pData[i] = m_pData[i - 1];
    }
    m_pData[nIndex] = dValue;
}

// 重载赋值操作符
DArray& DArray::operator=(const DArray& arr) {
    if (this != &arr) {
        // 先释放自身原有的内存
        Free();
        // 重新分配内存并拷贝元素
        SetSize(arr.GetSize());
        for (int i = 0; i < arr.GetSize(); ++i) {
            SetAt(i, arr.GetAt(i));
        }
    }
    return *this;
}