# CPP-Module-02
Ad-hoc polymorphism, operator overloading and Orthodox Canonical class form

![image](https://github.com/izzypt/CPP-Module-02/assets/73948790/c10c073f-6d99-4733-bbba-a43553736055)

### Understanding floats and it's representation

- https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html
- https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html

### Fixed point Numbers

- https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html



# Orthodox Canonical Form

In C++, the Orthodox Canonical Form refers to a set of guidelines that define how to properly implement certain features of a class to ensure consistency and maintainability. 

The Orthodox Canonical Form consists of three essential parts that should be implemented for a class: 
- The default constructor
- The copy constructor
- The copy assignment operator

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
