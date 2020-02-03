# Design-Patterns
Learning design patterns 
Singleton Design Pattern:
This pattern restricts the instantiation of a class to one object. This helps to have one place to log the errors, configuration settings of an application and also for taking care of expensive object creation like database connection.
This handles all the above stated things without loosing the object oriented principles.
This can be done either by eager initialization of an object or lazy initialization of object.
Singleton Vs Static: Singleton class follows the Object Oriented Principles while static class won’t follow the OOP.
Other differences:
•	Singleton class is created on heap while static class on stack
•	Singleton class can be disposed while static class cannot
•	Singleton class can have a constructor but static cannot
•	Singleton class can be cloned.
This demo also contain usage of singleton in multi-threaded environment.
