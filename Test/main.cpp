#include <iostream>
using namespace std;

class A
{
public:
	A()  {    cout<<"A"<<endl;    }
	~A() {    cout<<"~A"<<endl;   }
};

class B:public A
{
public:
	B(A &a):_a(a)
	{
		cout<<"B"<<endl;
	}
	~B()
	{
		cout<<"~B"<<endl;
	}
private:
	A _a;
};

int main(void)
{
	{
	A a;       //很简单，定义a的时候调用了一次构造函数
	B b(a);  
	}
	  //这里b里面的_a是通过成员初始化列表构造起来的
	//而且是通过copy constructor构造的是b的成员对象_a的，这里是编译器默认的，因此在构造好_a前，先调用基类构造函数
    //然后才是构造自身,顺序就是A()->_a->B()（局部）
    //因此这里有两个A,一个B

	
	//在return之前进行析构
    /************************************************************************/
    /*析构是按照定义对象的反顺序来的，而且同一个对象按照构造的反顺序来的，因此这里先
    析构b然后才是a，那么b的构造顺序是上面的A()->_a->B()（局部），反过来，就是B()（局部）->_a->A()
    因此得到的就是~B->~A->~A
    在b之后就是析构a
    最后结果就是
    ~B->~A->~A->~A*/
	system("pause");
	return 0;
	
}