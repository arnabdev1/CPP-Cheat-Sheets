
# 📘 Java Generics — Comprehensive Notes

---

## 🧭 Table of Contents
- [1. Introduction to Generics](#1-introduction-to-generics)
- [2. Motivation and Benefits](#2-motivation-and-benefits)
- [3. Generic Classes and Interfaces](#3-generic-classes-and-interfaces)
- [4. Generic Methods](#4-generic-methods)
- [5. Bounded Generics](#5-bounded-generics)
- [6. Raw Types and Backward Compatibility](#6-raw-types-and-backward-compatibility)
- [7. Wildcards](#7-wildcards)
- [8. Type Erasure and Restrictions](#8-type-erasure-and-restrictions)
- [9. Generic Matrix Example](#9-generic-matrix-example)
- [10. Summary Table](#10-summary-table)

---

## 1. Introduction to Generics

**Generics** is the capability to parameterize types. This allows you to define classes, interfaces, and methods with **type parameters**, which are replaced by concrete types during compilation.  

For example, you can define a generic `Stack<E>` class that works with any type `E`. Later, you can instantiate it as `Stack<String>` or `Stack<Integer>` depending on your need.

```java
class GenericStack<E> {
    private java.util.ArrayList<E> list = new java.util.ArrayList<>();

    public int getSize() {
        return list.size();
    }

    public E peek() {
        return list.get(getSize() - 1);
    }

    public void push(E o) {
        list.add(o);
    }

    public E pop() {
        E o = list.get(getSize() - 1);
        list.remove(getSize() - 1);
        return o;
    }

    public boolean isEmpty() {
        return list.isEmpty();
    }
}
```

⸻

2. Motivation and Benefits

Before Java 1.5, classes like ArrayList operated on Object types. This caused:
	•	Lack of type safety: Any object could be added to a list.
	•	Need for manual casting: Retrieval required explicit type casts.
	•	Runtime errors: Type mismatches were caught only at runtime.

Example before generics:
```java
ArrayList list = new ArrayList();
list.add("Java");
list.add(123);  // allowed, but unsafe
String s = (String) list.get(0); // must cast manually
```
With generics, type checking happens at compile time:
```java
ArrayList<String> list = new ArrayList<>();
list.add("Java");
// list.add(123); // Compile-time error
String s = list.get(0); // No cast needed
```
✅ Key Advantages:
	•	Compile-time type checking → more reliable code
	•	Eliminates casting → cleaner syntax
	•	Increases reusability and readability

⸻

3. Generic Classes and Interfaces

A generic class is declared with one or more type parameters inside angle brackets (<>):
```java
public class Box<T> {
    private T value;

    public void set(T value) {
        this.value = value;
    }

    public T get() {
        return value;
    }
}
```
Usage:
```java
Box<Integer> intBox = new Box<>();
intBox.set(10);
System.out.println(intBox.get()); // 10

Box<String> strBox = new Box<>();
strBox.set("Hello");
System.out.println(strBox.get()); // Hello
```
You can also use multiple type parameters:
```java
class Pair<K, V> {
    private K key;
    private V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }
}
```
Interfaces can also be generic:
```java
interface Container<T> {
    void add(T item);
    T get();
}
```

⸻

4. Generic Methods

A generic method introduces its type parameter in its method signature.
```java
public static <E> void printArray(E[] list) {
    for (E element : list) {
        System.out.print(element + " ");
    }
    System.out.println();
}
```
	•	<E> before the return type declares the type parameter.
	•	The type parameter can be used for parameters, return types, and inside the method.

Usage:
```java
String[] words = {"Java", "C++", "Python"};
Integer[] nums = {1, 2, 3, 4};

printArray(words);
printArray(nums);
```
✅ Generic methods are useful when:
	•	The method logic is independent of the data type.
	•	You don’t want to make the entire class generic.

⸻

5. Bounded Generics

Sometimes, you want to restrict the types that can be used with generics. This is done using bounds.
```java
public static <E extends Number> double sum(E[] list) {
    double total = 0;
    for (E element : list) {
        total += element.doubleValue();
    }
    return total;
}
```
	•	E extends Number means E must be Number or its subclass (e.g., Integer, Double).

Usage:
```java
Integer[] intArr = {1, 2, 3};
Double[] dblArr = {2.5, 3.5, 4.0};

System.out.println(sum(intArr)); // 6.0
System.out.println(sum(dblArr)); // 10.0
```
You can also have multiple bounds:
```java
class MyClass<T extends Number & Comparable<T>> { }
```

⸻

6. Raw Types and Backward Compatibility

Raw types are generic classes used without specifying type parameters.
```java
ArrayList list = new ArrayList();  // raw type
list.add("Hello");
list.add(100);
```
They exist for backward compatibility with pre-generic code but are unsafe because type checking is bypassed.

Using raw types leads to unchecked warnings and potential runtime errors.

Safe version:
```java
ArrayList<String> list = new ArrayList<>();
list.add("Hello");
// list.add(100); // Compile error
```

⸻

7. Wildcards

Wildcards allow flexibility when working with generic methods or collections of unknown types.

<img width="1698" height="384" alt="image" src="https://github.com/user-attachments/assets/a10971fa-d48b-4208-9ca6-15aa4a82debb" />


Unbounded Wildcard
```java
public static void printList(List<?> list) {
    for (Object elem : list) {
        System.out.println(elem);
    }
}
```
Upper Bounded Wildcard
```java
public static double sumList(List<? extends Number> list) {
    double total = 0;
    for (Number n : list) total += n.doubleValue();
    return total;
}
```
Lower Bounded Wildcard
```java
public static void addNumbers(List<? super Integer> list) {
    list.add(10);
    list.add(20);
}
```
👉 PECS rule:
	•	Producer Extends → if a structure produces data, use extends.
	•	Consumer Super → if it consumes data, use super.

⸻

8. Type Erasure and Restrictions

Java implements generics through type erasure:
	•	All generic type information is removed at compile time.
	•	The compiler uses the generic information to generate type-safe bytecode, but at runtime, the JVM only sees raw types.

For example:
```java
ArrayList<String> list = new ArrayList<>();
list.add("Texas");
String state = list.get(0);
```
Internally becomes:
```java
ArrayList list = new ArrayList();
list.add("Texas");
String state = (String) list.get(0);
```
🔒 Restrictions due to Erasure
	1.	❌ Cannot create an instance of a type parameter
```java
E obj = new E(); // Error
```

	2.	❌ Cannot create arrays of generic types
```java
E[] arr = new E[10]; // Error
```

	3.	❌ Type parameters not allowed in static context
```java
static E value; // Error
```

	4.	❌ Exception classes cannot be generic.

⸻

9. Generic Matrix Example

You can design a generic matrix class that works with different number types like Integer and Rational.
```java
public abstract class GenericMatrix<E extends Number> {
    protected abstract E add(E o1, E o2);
    protected abstract E multiply(E o1, E o2);
    protected abstract E zero();

    public E[][] addMatrix(E[][] m1, E[][] m2) {
        // Implementation for matrix addition
    }

    public E[][] multiplyMatrix(E[][] m1, E[][] m2) {
        // Implementation for matrix multiplication
    }
}
```
Then create concrete implementations:
	•	IntegerMatrix for integer arithmetic
	•	RationalMatrix for custom rational number arithmetic

⸻

10. Summary Table

Concept	Description	Example
Generic Class	Class parameterized with a type	class Box<T>
Generic Method	Method with its own type parameter	<T> void print(T[])
Bounded Generics	Restrict type parameters using extends	<E extends Number>
Raw Types	Generic classes without specifying type — unsafe	ArrayList list = new ArrayList();
Wildcards	Flexible unknown type parameter ?, ? extends, ? super	List<? extends Number>
Type Erasure	Generic info removed at compile time	Runtime uses raw types
Restrictions	No new E(), no E[], no static E, no generic exceptions	Compiler errors


⸻

📌 Key Takeaways
	•	Generics bring compile-time safety and remove the need for manual casting.
	•	Wildcards and bounded types add flexibility for more complex generic designs.
	•	Type erasure enables backward compatibility but imposes some limitations.
	•	Mastery of generics is essential for building type-safe, reusable, and flexible Java applications.

