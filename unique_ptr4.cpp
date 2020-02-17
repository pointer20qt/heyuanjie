#include<iostream>
#include<string>
#include<initializer_list>
#include<assert.h>
#include<vector>
#include<memory>
class tool
{
public:
	int value = 0;
	tool()
	{
		std::cout << "tool������" << std::endl;
	}
	~tool()
	{
		std::cout << "tool������" << std::endl;
	}
};
namespace he
{
	template<class T>
	class L_autoptr
	{
		T* obj = nullptr;
	public:
		L_autoptr(T* ptr) :obj(ptr)
		{
			obj = ptr;
		}
		L_autoptr() = default;
		~L_autoptr()
		{
			delete obj;
		}
		L_autoptr(L_autoptr<T>& ptr)
		{
			obj = ptr.obj;
			ptr.obj = nullptr;
		}
		L_autoptr& operator = (L_autoptr<T>& ptr)
		{
			delete obj;
			obj = ptr.obj;
			ptr.obj = nullptr;
			return *this;
		}
		void reset(T* newptr)
		{
			delete obj;
			obj = newptr;
		}
		T* release()
		{
			auto tem = obj;
			obj = nullptr;
			return tem;
		}
		T& operator*()
		{
			return *obj;
		}
		T* operator->()
		{
			return obj;
		}
		T* get()
		{
			return obj;
		}
	};
template<class T>
	class L_uniqueptr
	{
		T* obj = nullptr;
	public:
		L_uniqueptr(T* ptr) :obj(ptr)
		{
			obj = ptr;
		}
		L_uniqueptr(const T&) = delete;
		L_uniqueptr() = default;
		~L_uniqueptr()
		{
			delete obj;
		}
		L_uniqueptr(L_uniqueptr<T>&& ptr)
		{
			obj = ptr.obj;
			ptr.obj = nullptr;
		}
		L_uniqueptr& operator = (const L_uniqueptr<T>& ptr) = delete;
		L_uniqueptr& operator = (L_uniqueptr<T>&& ptr)
		{
			delete obj;
			obj = ptr.obj;
			ptr.obj = nullptr;
			return *this;
		}
		void reset(T* newptr)
		{
			delete obj;
			obj = newptr;
		}
		T* release()
		{
			auto tem = obj;
			obj = nullptr;
			return tem;
		}
		T& operator*()
		{
			return *obj;
		}
		T* operator->()
		{
			return obj;
		}
		T* get()
		{
			return obj;
		}
	};
	//��Դ����
template<class T>
	class Ref
	{
		//��ǰ��Դ��
		int r_count=0;
		T* object=nullptr;
	public:
		Ref(T* target) :object(target)
		{
			++r_count;
		}
		inline void increase()
		{
			r_count++;
		}
		inline void reduce()
		{
			r_count--;
			if (r_count == 0)
			{
				delete object;
				delete this;
			}
		}
		//��ö���
		T* get()
		{
			return object;
		}
		int getcount()
		{
			return r_count;
		}

	};
	template<class T>class Lshareptr
	{
		Ref<T>* ref=nullptr;
	public:
		Lshareptr() = default;
		~Lshareptr()
		{
			if (ref)
			{
				ref->reduce();
			}
		}
		Lshareptr(T* newp)
		{
			ref = new Ref<T>(newp);
		}
		Lshareptr(const Lshareptr& other)
		{
			ref = other.ref;
			if (ref)
			{
				ref->increase();
			}
		}
		Lshareptr(Lshareptr&& other)
		{
			swap(ref , other.ref);
		}
		Lshareptr& operator = (const Lshareptr& other)
		{ 
			if (ref)
			{
				ref->reduce();
			}
			ref = other.ref;
			if (ref)
			{
				ref->increase();
			}
			return *this;
		}
		Lshareptr& operator=(const Lshareptr&& other)
		{
			if (ref)
			{
				ref->reduce();
			}
			ref = other.ref;
			other.ref = nullptr;
			return *this;
		}
		void swap(Lshareptr& other)
		{
			swap(ref, other.ref);
		}
		void reset(T*target)
		{
			if (ref)
			{
				ref->reduce();
			}
			ref = new Ref<T>(target);
		}  
		void reset()
		{
			if (ref)
			{
				ref->reduce();
			}
			ref = nullptr;
		}
		T& operator* ()
		{
			if (ref)
			{
				return ref->get();
			}
			else
			{
				return *(T*)nullptr;
			}
		}
		T* operator->()
		{
			if (ref)
			{
				return ref->get();
			}
			else
			{
				return *(T*)nullptr;
			}
		}
		T* get()
		{
			if (ref)
			{
				return ref->get();
			}
			else
			{
				return (T*)nullptr;
			}
		}
		int use_count()
		{
			if (ref)
			{
				return ref->getcount();
			}
			else
			{
				return 0;
			}
		}
		bool unique()
		{
			if (ref)
			{
				return ref->getcount()==1;
			}
			else
			{
				return false;
			}
		}
		//�жϵ�ǰ����ָ���Ƿ�Ͷ������
		operator bool()
		{
			return ref != nullptr;
		}
	};
}

int main()
{
	he::Lshareptr<tool> p1(new tool);
	std::cout << "��ǰ���ü���" << p1.use_count() << std::endl;
	he::Lshareptr<tool> p2(p1);
	he::Lshareptr<tool> p3;
	p3 = p1;
	std::cout << "��ǰ���ü���" << p1.use_count() << std::endl;
	std::cout << "��ǰ���ü���" << p2.use_count() << std::endl;
	std::cout << "��ǰ���ü���" << p3.use_count() << std::endl;
	p2.reset();
	std::cout << "��ǰ���ü���" << p3.use_count() << std::endl;
}