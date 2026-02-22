//= () [] -> ->*的重载必须做成成员函数
//+-*/%^&|~重载函数：const T operatorX(constT&I,constT&r)const;
//! && || < <= ==……:bool operatorX(constT&I,constT&r)const;
class T {
  public:
	T(int m): i(m) {}
	const T operator+=(int n) {
		i += n;
		return *this;
	}
//前置++：
	const T&operator++() {
		*this += 1;
		return *this;
	}
	//后置++
	const T operator++(int) {//参数不会被用到，只是为了重载两个++，所以光写个类型就行，不用写参数名，这是专属于++的默认规定，前置没有int参数，后置有。
		//C++ 标准委员会规定，必须通过增加一个无用的 int 参数来人工制造出“签名差异”，从而让重载机制能够识别它们。
		//编译器（Compiler）： 负责执行这套逻辑。当你写 x++ 时，编译器会自动在底层将其转换成 x.operator++(0) 的调用，即自动传进一个整数0
		T old(*this);
		++(*this);
		return old;
	}
	T&operator[](int index) {
		return some_data[index];   //别忘了在外面定义时有类名::
	}
  private:
	int i;
	T *some_data;

};


