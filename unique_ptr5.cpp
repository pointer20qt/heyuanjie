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
		std::cout << "tool构造了" << std::endl;
	}
	~tool()
	{
		std::cout << "tool析构了" << std::endl;
	}
};
namespace he
{
	//资源计数
template<class T>
	class Ref
	{
		//当前资源数
		int r_count=0;
		//当前弱引用指针计数
		int w_count = 0;
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
		inline void increase_w()
		{
			w_count++;
		}
		inline void reduce()
		{
			r_count--;
			if (r_count == 0)
			{
				delete object;
				object = nullptr;
				if (w_count == 0)
				{
					delete this;
				}
			}
		}
		inline void reduce_w()
		{
			w_count--;
			if (w_count == 0&&r_count==0)
			{
				delete this;
			}
		}
		//获得对象
		T* get()
		{
			return object;
		}
		int getcount()
		{
			return r_count;
		}

	};
	template<class T> class Lweakptr;
	template<class T>class Lshareptr
	{
		friend class Lweakptr<T>;
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
		Lshareptr(Ref<T>* newref)
		{
			ref = newref;
			if (ref)
			{
				ref->increase();
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
				return (T*)nullptr;
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
		//判断当前智能指针是否和对象关联
		operator bool()
		{
			return ref != nullptr;
		}
	};
	template<class T> class Lweakptr
	{
		Ref<T>* ref = nullptr;
	public:
		Lweakptr() = default;
		Lweakptr(Lshareptr<T>& other) :ref(other.ref)
		{
			std::cout << "使用了shared构造了一个weak的拷贝赋值运算符" << std::endl;
			if (ref)
			{
				ref->increase_w();
			}
		}
		Lweakptr(const Lweakptr<T>& other) :ref(other.ref)
		{
			if (ref)
			{
				ref->increase_w();
			}
		}
		Lweakptr(Lweakptr<T>&& other) 
		{
			swap(ref,other.ref)
		}
		Lweakptr<T>& operator=(const Lweakptr<T>& other)
		{
			std::cout << "调用了weak的拷贝赋值运算符"<<std::endl
			if (ref)
			{
				ref->reduce_w();
			}
			ref = other.ref;
			if (ref)
			{
				ref->increase_w();
			}
			return *this;
		}
		Lweakptr<T>& operator=(Lweakptr<T>&& other)
		{
			std::cout << "调用了weak的移动赋值运算符" << std::endl;
			if (ref)
			{
				ref->reduce_w();
			}
			ref = other.ref;
			other.ref = nullptr;
			return *this;
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
		bool expired()
		{
			if (ref)
			{
				return ref->getcount()>0;
			}
			else
			{
				return false;
			}
		}
		Lshareptr<T> lock()
		{
			Lshareptr<T> tem(ref);
			return tem;
		}
		void swap(Lweakptr<T>& other)
		{
			swap(ref, other.ref);
		}
		void reset()
		{
			ref->increase_w();
			ref = nullptr;
		}
	};
}
struct node
{
	he::Lweakptr<node> pre;
	he::Lweakptr<node> next;
	~node()
	{
		std::cout << "node被析构了" << std::endl;
	}

};
int main()
{
	he::Lshareptr<node> n1(new node);
	he::Lshareptr<node> n2(new node);
	n1->next = n2;
	n2->pre = n1;
	std::cout << n1.use_count() << std::endl;
}