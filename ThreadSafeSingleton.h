std::mutex myMutex;
class SingletonThreads {
public:
	static SingletonThreads &getInstance();
private:
	SingletonThreads(SingletonThreads const &) = delete; // copy constructor
	SingletonThreads& operator=(SingletonThreads const&) = delete; //Assignment operator
	
	SingletonThreads() { };
	~SingletonThreads() {};

};
//SingletonThreads* SingletonThreads::instance = nullptr;
//Thread safe using the block scope static varialble
SingletonThreads &SingletonThreads::getInstance() {
	static SingletonThreads instance;
	return instance;
}
//Threas safe using the locking machinisim
class SingletonLockMechanism {
public:
	static SingletonLockMechanism* getIntace();
private:
	SingletonLockMechanism(SingletonLockMechanism const &) = delete; // copy constructor
	SingletonLockMechanism& operator=(SingletonLockMechanism const&) = delete; //Assignment operator

	SingletonLockMechanism() { };
	~SingletonLockMechanism();
	static SingletonLockMechanism* instance;

};
SingletonLockMechanism* SingletonLockMechanism::instance = NULL;
SingletonLockMechanism::~SingletonLockMechanism() {
	delete instance;
	instance = NULL;
}
SingletonLockMechanism* SingletonLockMechanism::getIntace() {
	std::lock_guard<std::mutex> myLock(myMutex);
	if (!instance) {
		instance = new SingletonLockMechanism();
	}
	return instance;
}
//Thead safe using atomic lock //conditional variables
