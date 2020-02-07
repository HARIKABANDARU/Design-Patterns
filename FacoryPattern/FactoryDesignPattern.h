#pragma once
#include<iostream>
using namespace std;
enum billType { DomesticPlan, CommercialPlan, InsistutionalPlan };
class Plan {
public:
	virtual void CalculateBills(int units, int rate) {
		cout << "The cost of the bill is " << (units*rate) << "\n";
	}
	//double rate;
	virtual int  getRate()const = 0;
	//With out a virtaul distructor we can not call the derived call destructor
	virtual ~Plan() {};

};
class Domestic :public Plan {
public:
	virtual int getRate() const {
		return 4;
	}
	virtual ~Domestic() {};
};

class Insistutional :public Plan {
public:
	virtual int getRate() const {
		return 10;
	}
	virtual ~Insistutional() {};
};
class Commercial :public Plan {
public:
	virtual int getRate() const {
		return 15;
	}
	virtual ~Commercial() {};
};
class PlanFactory {
public:
	static unique_ptr<Plan> createPlanBill(billType bill) {
		if (bill == DomesticPlan) {
			return make_unique<Domestic>();
		}
		else if (bill == CommercialPlan) {
			return make_unique<Commercial>();
		}
		else if (bill == InsistutionalPlan) {
			return make_unique<Insistutional>();
		}
	}
};
