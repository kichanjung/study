//#pragma once
//
//#include<iostream>
//
//
//template<class T>
//class AutoPtr
//{
//public:
//	T* m_ptr = nullptr;
//public:
//	AutoPtr(T *ptr =nullptr): m_ptr(ptr)
//	{}
//	~AutoPtr()
//	{
//		delete m_ptr;
//	}
//	AutoPtr(AutoPtr& a)
//	{
//		std::cout << "AutoPtr copy constructor" << std::endl;
//
//		m_ptr = new T;
//		*m_ptr = *a.m_ptr;
//
//		//m_ptr = a.m_ptr;
//		//a.m_ptr = nullptr;
//	}
//	AutoPtr& operator = (const AutoPtr& a)
//	{
//		if (&a == this)
//			return *this;
//
//		delete m_ptr;
//
//		m_ptr = new T;
//		*m_ptr = *a.m_ptr;
//
//		//m_ptr = a.m_ptr;
//		//a.m_ptr = nullptr;
//		//return *this;
//
//	}
//
//	AutoPtr(AutoPtr&& a) : m_ptr(a.m_ptr)
//	{
//		a.m_ptr = nullptr;
//		std::cout << "AutoPtr move constructor" << std::endl;
//	}
//
//	AutoPtr& operator=(AutoPtr&& a)
//	{
//		std::cout << "AutoPtr move constructor" << std::endl;
//		if (&a == this)
//			return *this;
//
//		m_ptr = a.m_ptr;
//		a.m_ptr = nullptr;
//		return *this;
//	}
//	T& operator*() const { return *m_ptr; }
//	T* operator->() const { return m_ptr; }
//	bool isNull() const { return m_ptr == nullptr; }
//};
//
//
