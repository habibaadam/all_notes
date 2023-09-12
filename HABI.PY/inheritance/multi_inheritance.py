"""A python example displaying multiple inheritances"""

class Person1(object):

    def __init__(self):
        self.name1 = "Habie1"
        print("Name1")

class Person2(object):

    def __init__(self):
        self.name2 = "Habie2"
        print("Name2")

class Baby(Person1, Person2):
    def __init__(self):

        Person1.__init__(self)
        Person2.__init__(self)

        print("child")

    def print(self):
        print(self.name1, self.name2)

babyme = Baby()
babyme.print()
