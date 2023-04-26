#include <new>
#include <execution>

template<typename T>
UniquePtr<T>::UniquePtr(T* ptr) :
	ptr_(ptr)
{
}

template<typename T>
UniquePtr<T>::~UniquePtr()
{
	if (ptr_)
	{
		delete ptr_;
		ptr_ = nullptr;
	}
}

template<typename T>
UniquePtr<T>::UniquePtr(UniquePtr&& other) :
	ptr_(other.get())
{
	other.release();
}

template<typename T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr&& other) noexcept
{
	delete ptr_;

	ptr_ = other.release();

	return *this;
}

template<typename T>
UniquePtr<T>::operator bool() const noexcept
{
	if (ptr_)
		return true;
	else
		return false;
}

template<typename T>
T& UniquePtr<T>::operator*()
{
	if (!ptr_)
		throw std::runtime_error("Pointer is empty");
	return *ptr_;
}

template<typename T>
T* UniquePtr<T>::operator->() noexcept
{
	return ptr_;
}

template<typename T>
[[nodiscard]]T* UniquePtr<T>::release() noexcept
{
	T* ptr = ptr_;
	ptr_ = nullptr;
	return ptr;
}

template<typename T>
void UniquePtr<T>::reset(T* other) noexcept
{
	if (ptr_)
		delete ptr_;
	ptr_ = other;
}

template<typename T>
void UniquePtr<T>::swap(UniquePtr& other) noexcept
{
	T* temp = other.release();
	other.ptr_ = release();
	ptr_ = temp;
}

template<typename T>
T* UniquePtr<T>::get() const noexcept
{
	return ptr_;
}

template<typename T>
UniquePtr<T[]>::UniquePtr(T* ptr) :
	ptr_(ptr)
{
}

template<typename T>
UniquePtr<T[]>::~UniquePtr()
{
	if (ptr_)
	{
		delete ptr_;
		ptr_ = nullptr;
	}
}

template<typename T>
UniquePtr<T[]>::UniquePtr(UniquePtr&& other) :
	ptr_(other.get())
{
	other.release();
}

template<typename T>
T& UniquePtr<T[]>::operator[](const int index)
{
	return ptr_[index];
}

template<typename T>
UniquePtr<T[]>& UniquePtr<T[]>::operator=(UniquePtr<T[]>&& other) noexcept
{
	delete ptr_;

	ptr_ = other.release();

	return *this;
}

template<typename T>
UniquePtr<T[]>::operator bool() const noexcept
{
	if (ptr_)
		return true;
	else
		return false;
}

template<typename T>
T& UniquePtr<T[]>::operator*()
{
	if (!ptr_)
		throw std::runtime_error("Pointer is empty");
	return *ptr_;
}

template<typename T>
T* UniquePtr<T[]>::operator->() noexcept
{
	return ptr_;
}

template<typename T>
T* UniquePtr<T[]>::release() noexcept
{
	T* ptr = ptr_;
	ptr_ = nullptr;
	return ptr;
}

template<typename T>
void UniquePtr<T[]>::reset(T other[]) noexcept
{
	if (ptr_)
		delete[] ptr_;
	ptr_ = other;
}

template<typename T>
void UniquePtr<T[]>::swap(UniquePtr<T[]>& other) noexcept
{
	T* temp = other.release();
	other.ptr_ = release();
	ptr_ = temp;
}

template<typename T>
T* UniquePtr<T[]>::get() const noexcept
{
	return ptr_;
}