# CPP-Module-02
Ad-hoc polymorphism, operator overloading and Orthodox Canonical class form

![image](https://github.com/izzypt/CPP-Module-02/assets/73948790/c10c073f-6d99-4733-bbba-a43553736055)


### Understanding floats and it's representation

- https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html
- https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html

### Fixed point Numbers

- https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html


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
