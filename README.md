# CPP-Module-02

### Ad-hoc polymorphism, operator overloading and Orthodox Canonical class form.

------------------------------------------------------------------------------------------

We are going to discover a new and awesome number
type: fixed-point numbers! 

Fixed-point numbers offer a valuable balance between performance, accuracy, range and
precision. 

That explains why fixed-point numbers are particularly applicable to computer
graphics, sound processing or scientific programming, just to name a few.

As C++ lacks fixed-point numbers, you’re going to add them.

![image](https://github.com/izzypt/CPP-Module-02/assets/73948790/c10c073f-6d99-4733-bbba-a43553736055)

### Understanding floats and it's representation

- https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html
- https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html

### Fixed point Numbers

- https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html

- Fixed point is a simple yet very powerful way to represent fractional numbers in computer. 

- By reusing all integer arithmetic circuits of a computer, fixed point arithmetic is orders of magnitude faster than floating point arithmetic. 

- This is the reason why it is being used in many game and DSP applications. On the other hand, it lacks the range and precision that floating point number representation offers. You, as a programmer or circuit designer, must do the tradeoff.


# Orthodox Canonical Form

In C++, the Orthodox Canonical Form refers to a set of guidelines that define how to properly implement certain features of a class to ensure consistency and maintainability. 

The Orthodox Canonical Form consists of three essential parts that should be implemented for a class: 
- **The default constructor**
- **The copy constructor**
  - When you pass an object by value as a function argument instead of by reference, the copy constructor is invoked to create a copy of the object.
  - This is because passing by value requires creating a new instance of the object, and the copy constructor is responsible for performing the copy.  
- **The copy assignment operator**
  - The copy assignment operator is a special member function that is used to assign the values of one object to another object of the same class.
  - Its purpose is to define how objects of a class should be assigned or copied from one another.

    The copy assignment operator is invoked when you use the assignment operator (`=`) to assign one object to another. For example:
    
    ```cpp
    MyClass obj1;
    MyClass obj2;
    obj2 = obj1;  // Copy assignment operator is called
    ```
    
Here is an example of implementing the Orthodox Canonical Form for a simple class called `MyClass`:

```cpp
class MyClass {
private:
    int data;

public:
    // Default constructor
    MyClass() : data(0) {}

    // Copy constructor
    MyClass(const MyClass& other) : data(other.data) {}

    // Copy assignment operator
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    // Other member functions and data members...
};
```

In the example above, `MyClass` is a basic class with an `int` data member called `data`. It follows the Orthodox Canonical Form by implementing the default constructor, the copy constructor, and the copy assignment operator.

- **The default constructor initializes the `data` member to a default value (in this case, 0)**.
  - Responsible for initializing an object of the class when no arguments are provided during its instantiation.
  - It creates a new instance of the class with default values for its member variables.
  - In the example code provided earlier, the default constructor of MyClass initializes the data member to 0.  
- **The copy constructor initializes a new instance of `MyClass` by copying the `data` value from another instance.**
  - Used to create a new object by making a copy of an existing object of the same class.
  - It is invoked when an object is being initialized or passed by value.
  - The copy constructor takes an object reference as a parameter and performs a member-wise copy of the data from the source object to the newly created object.
  - In the example code, the copy constructor of MyClass copies the data value from the other object to initialize a new instance. 
- **The copy assignment operator assigns the `data` value from another instance to the current instance, checking for self-assignment before making the assignment.**
  - The copy assignment operator is used to assign the value of one object to another object of the same class.
  - It is invoked when an object is being assigned the value of another object using the assignment operator (=).
  - The copy assignment operator ensures that the assignment is performed correctly and handles self-assignment checks to avoid issues.
  - In the example code, the copy assignment operator of MyClass assigns the data value from the other object to the current object (*this). 

By implementing these three functions, you ensure that instances of `MyClass` can be constructed, copied, and assigned in a consistent and predictable manner. This allows for proper object construction and manipulation, and also enables the use of standard C++ features like containers and algorithms with your class.

# Operator Overloading

![image](https://github.com/izzypt/CPP-Module-02/assets/73948790/5f42d970-4323-491f-88d1-29bd94ad2eab)


# Copy assignment operator

![image](https://github.com/izzypt/CPP-Module-02/assets/73948790/f5ec205e-8653-4a23-bc47-c637fc698652)



 The default copy assignment operator provided by the compiler performs a member-wise assignment, copying each member of the source object to the corresponding member of the target object. In other words, *the compiler creates a copy assignment operator for us if we haven't done it* 
 
 However, in certain cases, you may need to provide a custom implementation of the copy assignment operator to ensure proper copying behavior or to perform additional actions.
    
  Here are a few situations where a custom copy assignment operator might be useful:
  
  1. Deep copying: If your class contains dynamically allocated memory or resources, a shallow copy performed by the default copy assignment operator may lead to issues. In such cases, you can define a custom copy assignment operator to perform a deep copy, creating new copies of the dynamically allocated resources.
  
  2. Resource management: If your class manages external resources such as file handles, network connections, or locks, a custom copy assignment operator can help properly transfer ownership or handle resource duplication.
  
  3. Preventing unwanted copying: In some cases, you may want to disable or restrict the copying of objects of your class. By declaring the copy assignment operator as private and not providing a definition, you can prevent objects from being assigned to one another.
  
  Here's an example of a custom copy assignment operator that performs a deep copy:
    
  ```cpp
  class MyClass {
  private:
      int* data;
  
  public:
      // Constructor
      MyClass(int value) {
          data = new int(value);
      }
  
      // Destructor
      ~MyClass() {
          delete data;
      }
  
      // Copy assignment operator
      MyClass& operator=(const MyClass& other) {
          if (this != &other) {
              delete data;
              data = new int(*other.data);
          }
          return *this;
      }
  };
  ```
    
  In the above example, the copy assignment operator explicitly deletes the existing `data` and creates a new copy of the `data` from the source object. 
  
  This ensures that each object has its own separate copy of the dynamically allocated `data` and prevents issues when one object is modified.
  
  It's important to note that when you define a custom copy assignment operator, it is often necessary to also define a custom copy constructor and destructor to properly manage resources and prevent issues like double deletion or resource leaks.
  
  Overall, the copy assignment operator allows you to control how objects of your class are assigned and copied, ensuring proper behavior and resource management.

# Shallow Copy vs Deep Copy

### Shallow Copy:
   
- A shallow copy is a copy that simply duplicates the memory address of the source object's data to the target object.
- This means that both the source and target objects will point to the same memory location.
- In other words, the copy only copies the memory addresses, not the data itself. If the original object is modified, the shallow copy will also be affected since they share the same data.

  ```cpp
  #include <iostream>
  
  class ShallowCopyExample {
  public:
      int* data;
  
      ShallowCopyExample(int value) {
          data = new int(value);
      }
  
      // Shallow copy constructor
      ShallowCopyExample(const ShallowCopyExample& other) : data(other.data) {}
  
      ~ShallowCopyExample() {
          delete data;
      }
  };
  
  int main() {
      ShallowCopyExample original(42);
      ShallowCopyExample shallowCopy(original);
  
      std::cout << *original.data << std::endl;       // Output: 42
      std::cout << *shallowCopy.data << std::endl;   // Output: 42
  
      // Modify the data through the shallow copy
      *shallowCopy.data = 100;
  
      std::cout << *original.data << std::endl;       // Output: 100 (changed)
      std::cout << *shallowCopy.data << std::endl;   // Output: 100 (changed)
  
      return 0;
  }
  ```

### Deep Copy:
- A deep copy, on the other hand, involves creating a completely new copy of the source object's data in a separate memory location.
- This means that the target object has its own distinct memory and is independent of the source object.
- Modifying the data in the target object will not affect the original object or any other deep copies.

  ```cpp
  #include <iostream>
  
  class DeepCopyExample {
  public:
      int* data;
  
      DeepCopyExample(int value) {
          data = new int(value);
      }
  
      // Deep copy constructor
      DeepCopyExample(const DeepCopyExample& other) : data(new int(*other.data)) {}
  
      ~DeepCopyExample() {
          delete data;
      }
  };
  
  int main() {
      DeepCopyExample original(42);
      DeepCopyExample deepCopy(original);
  
      std::cout << *original.data << std::endl;       // Output: 42
      std::cout << *deepCopy.data << std::endl;      // Output: 42
  
      // Modify the data through the deep copy
      *deepCopy.data = 100;
  
      std::cout << *original.data << std::endl;       // Output: 42 (unchanged)
      std::cout << *deepCopy.data << std::endl;      // Output: 100 (changed)
  
      return 0;
  }
  ```

In summary, a shallow copy simply copies the memory address, resulting in multiple pointers pointing to the same data, while a deep copy creates a completely independent copy of the data.


# Float vs Integer

- Bits representing an integer are interpreted literally as a binary number, while bits in a floating point number have a more complicated interpretation. 

### Accuracy vs. Precision

- "Accuracy" refers to how close a measurement is to the true value,
- "Precision" has to do with how much information you have about a quantity, how uniquely you have it pinned down.
  - **Integer arithmetic enjoys the property of complete accuracy.**
    - if I have the integer "2", it is exactly 2
    - Whatever operations I do with integers, provided there is no overflow, I will always get a number that matches the correct answer bit-for-bit. 
  - **Integers lack precision.**
    - Dividing both 5 and 4 by 2, for instance, will both yield 2.
    - Integers are unable to keep track of the fractional part, so some information is lost in the process.
  - **Floating point numbers are the exact opposite of integers with respect to accuracy and precision.**
    - They have good precision, since they never deliberately discard information representing your numbers.
   
### Fixed Point Number Representation

- A fixed-point number representation is a way of representing and performing calculations with decimal numbers using a fixed number of digits for the fractional part. 

- Unlike floating-point numbers, which have a fixed number of bits for the exponent and the mantissa (fractional part), fixed-point numbers have a fixed number of bits for the fractional part only, while the integer part is represented using the remaining bits.

- In languages like C++, fixed-point number representations are typically implemented using integers, where a fixed number of bits (usually determined by the programmer) are allocated for the fractional part. The remaining bits represent the integer part. The position of the fixed-point (the binary point) is usually predefined and does not change during calculations.

- Fixed-point numbers are useful in situations where precise decimal arithmetic is required but using floating-point numbers is either unnecessary or too expensive in terms of computational resources. They are commonly used in embedded systems, signal processing applications, financial calculations, and other scenarios that involve fixed decimal precision.

- The advantage of fixed-point numbers is that they can be more efficient in terms of memory usage and computational speed compared to floating-point numbers. Fixed-point arithmetic operations can be implemented using regular integer arithmetic, which is typically faster than floating-point arithmetic. However, a trade-off is that fixed-point numbers have a limited range and precision, which must be considered when designing algorithms or performing calculations.

# A reminder on bitwise operators :

Since we will need to manipulate bits in order to build our fixed point number data type, let's have a gentle reminder on the bitwise operators :

The ```&``` operator (bitwise AND): 
  - Takes two numbers as operands and does AND on every bit of two numbers. The result of AND is 1 only if both bits are

The ```|``` operator (bitwise OR):
  - Takes two numbers as operands and does OR on every bit of two numbers. The result of OR is 1 if any of the two bits is 1. 

The ```^``` (bitwise XOR):
  - Takes two numbers as operands and does XOR on every bit of two numbers. The result of XOR is 1 if the two bits are different. 

The ```<<``` (left shift):
  - Takes two numbers, the left shifts the bits of the first operand, and the second operand decides the number of places to shift. 

The ```>>``` (right shift)
  - Takes two numbers, right shifts the bits of the first operand, and the second operand decides the number of places to shift. 

The ```~``` (bitwise NOT)
  - Takes one number and inverts all bits of it.

![image](https://github.com/izzypt/CPP-Module-02/assets/73948790/1304211e-612f-48fe-b548-dbdeab951508)


Shifting an integer to the right by 1 bit position is equivalent to dividing the number by 2. 

In general, mathematically, given a fixed binary point position, shifting the bit pattern of a number to the right by 1 bit always divide the number by 2. Similarly, shifting a number to the left by 1 bit multiplies the number by 2.

# Fixed Point Number Representation

The shifting process above is the key to understand fixed point number representation. 

To represent a real number in computers (or any hardware in general), ***we can define a fixed point number type simply by implicitly fixing the binary point to be at some position of a numeral***. We will then simply adhere to this implicit convention when we represent numbers.

To define a fixed point type conceptually, all we need are two parameters:

- width of the number representation
- binary point position within the number

We will use the notation ```fixed<w,b>``` for the rest of this article, where ```w``` denotes the number of bits used as a whole (the Width of a number), and ```b``` denotes the position of binary point counting from the least significant bit (counting from 0).

For example, fixed<8,3> denotes a 8-bit fixed point number, of which 3 right most bits are fractional. Therefore, the bit pattern:
```
0	0	0	1	0	1	1	0
```
represents a real number:
```
00010.1102
= 1 * 21 + 1 * 2-1 + 1 * 2-1

= 2 + 0.5 + 0.25

= 2.75
```
Note that on a computer, a bit patter can represents anything. Therefore the same bit pattern, if we "cast" it to another type, such as a fixed<8,5> type, will represents the number:
```
000.101102
= 1 * 2-1 + 1 * 2-3 + 1 * 2-4

= 0.5 + 0.125 + 0.0625

= 0.6875
```
If we treat this bit patter as integer, it represents the number:
```
101102
= 1 * 24 + 1 * 22 + 1 * 21

= 16 + 4 + 2

= 22
```
