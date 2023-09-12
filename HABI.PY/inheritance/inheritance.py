"""A python program to show inheritance"""

class Person(object):

    def __init__(self, name, id):
        self.name = name
        self.id = id
#a method that prints details of a worker from this class
    def show(self):
        print(self.name, self.id)

#an instance of the parent class is created and its details are printed out
worker = Person("Memory", 277)
worker.show()

#Expected Output 
#Memory 227
print(dir(Person))


"""A child class of the class Person"""

class Worker(Person):

    def print(self):
        print("Worker class called ")

Worker_info = Worker("Habie", 477)

Worker_info.show() #calling the parent function with the show method

Worker_info.print() #calling the child
