#include <iostream>
#include <vector>

template<class T>
struct Any {
	T Value;
	type Type = nullptr;
};

template <class T>
void Construct(Any<T>& A, const T& In) {//kick it.
	A = Any{In,decltype(In)};
	return;
}

template<class T>
struct Valiant {
	T Value;
	type Type = nullptr;
};
template <class T>
void Construct(Valiant<T>& V, const T& In) {//kick it.
	V = Valiant{In,decltype(In)};
	return;
}
//are you need sum function. for last result.
struct Function {
	Any Conjecter;//for conjecter function. mix the inner.
	//std::vector<Any> Lines;
	std::vector<Function> Lines;
	ValiantTuple Args;
	Valiant Ret;
};

auto Conjection(Function& In) {
	return F.Conjecter.Value(In);//is valid??
}

template<class L>
void SetConjecter(Function& In, const L& F){
	In.Conjecter.Value = F;
	in.Conjecter.Type = decllambda(F);
	return;
}

auto Sum(Function& In) {
	auto A;//forces late binding.
	auto B;
	for (auto& o : In.Lines) {
		A += o.Ret.Value;
	}

	for (auto& o : In.Lines) {
		B += o.Sum();
	}

	return B + A;//is valid??
}

void Call(const Function& In) {

	for (auto& L : In.Lines) {
		L.Ret=L.Conjecter.Values(L.Args);//call holy ceraf.
		L.Call();//too.
	}
	return;
}

//for UCS
template<class... T>
void Add(Function& F, auto L, const T&... Arg) const{//L is for Lambda.
	Any A{ L,decllamda(L) };//anotetion.
	ValiantTuple VT = MakeValiantTuple(Arg...);//made by other code. made by me.
	Valiant V{ auto(0),decltype(L) };

	F.Lines.push_back({ L,{},VT,V });
}
//for UCS
template<class... T>
void Add(Function& F, auto L,const std::vector<Function>& In, const T&... Arg) const {//L is for Lambda.
	Any A{ L,decllamda(L) };//anotetion.
	ValiantTuple VT = MakeValiantTuple(Arg...);//made by other code. made by me.
	Valiant V{ auto(0),decltype(L) };

	F.Lines.push_back({ L,In,VT,V });
}

Function MakeFunction(Any Con, std::vector<Function> Fs, const ValiantTuple& Arges, const Valiant& V) {
	Function F{ Con,Fs,Arges,V };

	return F;
}


//this is scrap.
int main() {
	//Any A;
	//A.Construct([](auto i) {return i * 2; });

	Function F;

	F.Add([](auto i) {return i * 2; }, 16);
	F.Add([](auto A, auto B) {return A * B; },2,4);
	F.SetConjector([](Function& In) {F.Call(); });//call Holy Ceraf.

	F.Conjection();//prejuer.
	auto X = F.Sum();

	std::cout << X << std::endl;//result.

	return 0;
}

