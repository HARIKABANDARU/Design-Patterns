/* Any class can be turned to singleton using this templatised singleton class*/
template<class T>
class SingletonDPTemp {
public:
	static T* getInstance();
private:
	SingletonDPTemp() {};
	SingletonDPTemp(SingletonDPTemp const&) = delete; //copy constructor
	SingletonDPTemp& operator=(SingletonDPTemp const&) = delete; //assignemnt operator
	static T* instance;
	~SingletonDPTemp();
};
template<class T>
SingletonDPTemp<T>::~SingletonDPTemp() {
	delete instance;
	instance = NULL;
}
template<class T>
T* SingletonDPTemp<T>::instance = NULL;
template<class T>
T* SingletonDPTemp<T>::getInstance() {
	if (!instance)
		instance = new T;
	return instance;
}
