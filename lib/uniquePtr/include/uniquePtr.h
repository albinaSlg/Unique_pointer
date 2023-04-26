#pragma once

template<typename T>
class UniquePtr
{
public:
	/**
	* Constructs a UniquePtr which owns ptr, initializing the stored pointer with ptr
	* @name Constructor
	* @arg T* pointer to the object
	* @return Nonee
	*/
	explicit UniquePtr(T* ptr);
	/**
	* If ptr_ == nullptr there are no effects. Otherwise, the owned object is destroyed
	* @name Destructor
	* @arg None
	* @return None
	*/
	~UniquePtr();
	UniquePtr(const UniquePtr& other) = delete;
	UniquePtr& operator=(const UniquePtr& other) = delete;
	/**
	* Constructs a unique_ptr by transferring ownership from other to *this and stores the null pointer in other
	* @name Move constructor
	* @arg const UniquePtr&& another class instance 
	* @return UniquePtr& this class instance
	*/
	UniquePtr(UniquePtr&& other);
	/**
	* Transfers ownership from other to *this
	* @name Move assignment operator
	* @arg const UniquePtr&& another class instance 
	* @return UniquePtr& this class instance
	*/
	UniquePtr& operator=(UniquePtr&& other) noexcept;
	/**
	* Provide access to the object owned by *this
	* @name operator*
	* @arg None
	* @return T& object reference, i.e. *get()
	*/

	T& operator*();
	/**
	* Provide access to the object owned by *this
	* @name operator->
	* @arg None
	* @return T* pointer to the object owned by *this, i.e. get()
	*/
	T* operator->() noexcept;
	/**
	* Checks whether *this owns an object, i.e. whether get() != nullptr
	* @name operator bool
	* @arg None
	* @return true if *this owns an object, false otherwise.
	*/
	explicit operator bool() const noexcept;
	/**
	* Return pointer and clean class field
	* @name release
	* @arg None
	* @return T* pointer to the released object
	*/

	[[nodiscard]]T* release() noexcept;
	/**
	* Replaces the managed object
	* @name reset
	* @arg T* pointer to the other object
	* @return None	
	*/
	void reset(T* other) noexcept;
	/**
	* Swaps the managed objects
	* @name swap
	* @arg UniquePtr& other another class instance 
	* @return None
	*/
	void swap(UniquePtr& other) noexcept;
	/**
	* Returns a pointer to the managed object or nullptr if no object is owned.
	* @name get
	* @arg None
	* @return T* pointer to the object
	*/
	T* get() const noexcept;

private:
	T* ptr_ = nullptr;
};

template<typename T>
class UniquePtr<T[]>
{
public:
	/**
	* Constructs a UniquePtr which owns ptr, initializing the stored pointer with ptr
	* @name Constructor
	* @arg T* pointer to the object
	* @return None
	*/
	explicit UniquePtr(T* ptr);
	/**
	* If ptr_ == nullptr there are no effects. Otherwise, the owned object is destroyed
	* @name Destructor
	* @arg None
	* @return None
	*/
	~UniquePtr();
	UniquePtr(const UniquePtr& other) = delete;
	UniquePtr<T[]>& operator=(const UniquePtr<T[]>& other) = delete;
	/**
	* Constructs a unique_ptr by transferring ownership from other to *this and stores the null pointer in other
	* @name Move constructor
	* @arg const UniquePtr<T[]>&& another class instance
	* @return UniquePtr<T[]>& this class instance
	*/
	UniquePtr(UniquePtr<T[]>&& other);
	/**
	* Transfers ownership from other to *this
	* @name Move assignment operator
	* @arg const UniquePtr<T[]>&& another class instance 
	* @return UniquePtr<T[]>& this class instance
	*/
	UniquePtr<T[]>& operator=(UniquePtr<T[]>&& other) noexcept;

	/**
	* Returns a reference to the element managed by *this at specified location pos. No bounds checking is performed.
	* @name operator[]
	* @arg None
	* @return T& object's element reference
	*/
	T& operator[](const int index);
	/**
	* Provide access to the object owned by *this
	* @name operator*
	* @arg None
	* @return T& object reference, i.e. *get()
	*/
	T& operator*();
	/**
	* Provide access to the object owned by *this
	* @name operator->
	* @arg None
	* @return T* pointer to the object owned by *this, i.e. get()
	*/
	T* operator->() noexcept;
	/**
	* Checks whether *this owns an object, i.e. whether get() != nullptr
	* @name operator bool
	* @arg None
	* @return true if *this owns an object, false otherwise.
	*/
	explicit operator bool() const noexcept;

	/**
	* Return pointer and clean class field
	* @name release
	* @arg None
	* @return T* pointer to the released object
	*/
	T* release() noexcept;
	/**
	* Replaces the managed object
	* @name resetD
	* @arg T* pointer to the other object
	* @return None	
	*/
	void reset(T* other) noexcept;
	/**
	* Swaps the managed objects
	* @name swap
	* @arg UniquePtr<T[]>& other another class instance 
	* @return None
	*/
	void swap(UniquePtr<T[]>& other) noexcept;

	/**
	* Returns a pointer to the managed object or nullptr if no object is owned.
	* @name get
	* @arg None
	* @return T* pointer to the object
	*/
	T* get() const noexcept;

private:
	T* ptr_ = nullptr;
};

#include "uniquePtr.inl"