class SingletonDP {
public:
	static SingletonDP* getInstance();
private:
	SingletonDP() {};
	SingletonDP(SingletonDP const &) = delete; //Copy Constructor
	SingletonDP& operator=(SingletonDP const &) = delete; // Copy Assignemnt
	~SingletonDP(); // Destructor
	static SingletonDP* instance;
	
};
//SingletonDP* SingletonDP::instance = 0;
SingletonDP* SingletonDP::instance = NULL;
//A destructor to handle memory leakage problems
SingletonDP::~SingletonDP() {
//	cout << "DEstructor called";
	delete instance;
	instance = NULL;
}
//Object creation through lazy instialization
SingletonDP* SingletonDP::getInstance() {
	
	if (!instance) {
		instance = new SingletonDP;
		return instance;
	}
	else
		return instance;
}
