print("Hello, World!") 
for i in range(5):  
    print(f"Iteration {i}")
def greet(name):
    return f"Hello, {name}!"
print(greet("Alice"))
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def introduce(self):
        return f"My name is {self.name} and I am {self.age} years old." 
person = Person("Bob", 30)
print(person.introduce())