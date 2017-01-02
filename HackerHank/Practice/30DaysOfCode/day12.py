class Person:
	def __init__(self, firstName, lastName, idNumber):
		self.firstName = firstName
		self.lastName = lastName
		self.idNumber = idNumber
	def printPerson(self):
		print "Name:", self.lastName + ",", self.firstName
		print "ID:", self.idNumber

class Student(Person):
    def __init__(self, firstName, lastName, idNumber, scores):
        Person.firstName = firstName
        Person.lastName = lastName
        Person.idNumber = idNumber
        self.scores = scores

    def calculate(self):
        average = sum(self.scores) / float(len(self.scores))
        if average < 40:
            return "T"
        elif average < 55:
            return "D"
        elif average < 70:
            return "P"
        elif average < 80:
            return "A"
        elif average < 90:
            return "E"
        elif average <= 100:
            return 'O'

