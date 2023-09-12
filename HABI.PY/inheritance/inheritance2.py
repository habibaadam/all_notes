"""Another python program to show inheritance """

class Person(object):

#Initializing a super class or a base class
    def __init__(self, name, id):
        self.name = name
        self.id = id
#defining a method that returns the name attributes
    def getname(self):
        return self.name

#defining a method which always returns False
    def isWorker(self):
        return False

#defining a child or a subclass inheriting from the parent class
class Worker(Person):

#Here, the isWorker method has been overrided to return True
    def isWorker(self):
        return True

#creating an instance of the class Person and printing it out
employee = Person("Nerd", 229)
print(employee.getname(), employee.isWorker())

#creating an instance of the child class Worker and printing it out
employee = Worker("Nerd2", 889)  # An Object of Worker
print(employee.getname(), employee.isWorker())

#Expected Output
#Nerd False
#Nerd2 True
