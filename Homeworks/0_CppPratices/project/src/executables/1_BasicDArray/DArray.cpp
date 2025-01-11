// implementation of class DArray
#include "DArray.h"
#include <iostream>
#include <cstdlib>

// Ĭ�Ϲ��캯��
DArray::DArray() {
    Init();
}

// ʹ��ָ����С��Ĭ��ֵ��ʼ������
DArray::DArray(int nSize, double dValue) {
    // �ȳ�ʼ��������س�Ա
    Init();
    // ���������С
    SetSize(nSize);
    // Ϊÿ��Ԫ�ظ�Ĭ��ֵ
    for (int i = 0; i < nSize; ++i) {
        SetAt(i, dValue);
    }
}

// �������캯��
DArray::DArray(const DArray& arr) {
    // �ȳ�ʼ����������
    Init();
    // ���ô�С�뱻����������ͬ
    SetSize(arr.GetSize());
    // ���Ԫ�ؿ���
    for (int i = 0; i < arr.GetSize(); ++i) {
        SetAt(i, arr.GetAt(i));
    }
}

// ��������
DArray::~DArray() {
    Free();
}

// ��ʾ����Ԫ��
void DArray::Print() const {
    for (int i = 0; i < GetSize(); ++i) {
        std::cout << GetAt(i) << " ";
    }
    std::cout << std::endl;
}

// ��ʼ�����飨�����ڴ�Ȳ�����
void DArray::Init() {
    m_pData = nullptr;
    m_nSize = 0;
}

// �ͷ������ڴ�
void DArray::Free() {
    if (m_pData != nullptr) {
        delete[] m_pData;
        m_pData = nullptr;
    }
    m_nSize = 0;
}

// ��ȡ�����С
int DArray::GetSize() const {
    return m_nSize;
}

// ���������С
void DArray::SetSize(int nSize) {
    if (nSize < 0) {
        return;
    }
    // �����С�ı䣬��Ҫ���·����ڴ�
    if (nSize != m_nSize) {
        double* pNewData = new double[nSize];
        int nCopySize = (nSize < m_nSize) ? nSize : m_nSize;
        for (int i = 0; i < nCopySize; ++i) {
            pNewData[i] = m_pData[i];
        }
        // �ͷž��ڴ�
        Free();
        m_pData = pNewData;
        m_nSize = nSize;
    }
}

// ��ȡָ����������Ԫ��
const double& DArray::GetAt(int nIndex) const {
    if (nIndex >= 0 && nIndex < m_nSize) {
        return m_pData[nIndex];
    }
    // ������Կ����׳��쳣���߰����󷵻غ��ʵĴ����ʾ
    static double ERROR;
    return ERROR;
}

// ����ָ��������Ԫ�ص�ֵ
void DArray::SetAt(int nIndex, double dValue) {
    if (nIndex >= 0 && nIndex < m_nSize) {
        m_pData[nIndex] = dValue;
    }
}

// ���� [] ������
const double& DArray::operator[](int nIndex) const {
    return GetAt(nIndex);
}

// ������ĩβ�����Ԫ��
void DArray::PushBack(double dValue) {
    int newSize = m_nSize + 1;
    SetSize(newSize);
    SetAt(newSize - 1, dValue);
}

// ɾ��ָ����������Ԫ��
void DArray::DeleteAt(int nIndex) {
    if (nIndex < 0 || nIndex >= m_nSize) {
        return;
    }
    for (int i = nIndex; i < m_nSize - 1; ++i) {
        m_pData[i] = m_pData[i + 1];
    }
    SetSize(m_nSize - 1);
}

// ��ָ��������������Ԫ��
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

// ���ظ�ֵ������
DArray& DArray::operator=(const DArray& arr) {
    if (this != &arr) {
        // ���ͷ�����ԭ�е��ڴ�
        Free();
        // ���·����ڴ沢����Ԫ��
        SetSize(arr.GetSize());
        for (int i = 0; i < arr.GetSize(); ++i) {
            SetAt(i, arr.GetAt(i));
        }
    }
    return *this;
}