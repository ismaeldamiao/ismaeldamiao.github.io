---
published: false
title: Best Practice about C++ class member variable accessor
classes: wide
categories:
  - Tools
tags:
  - C++
  - Programming
---


Three ways to implement accessors.

### Get and Set
```c++
class X
   {
   public:
      int    Age() const     { return aAge; }
      void   Age(int age)    { aAge= age; }
   private:
      int aAge;
   }
```
flaws：
* ugly. Get and Set are strewn throughout the code cluttering it up.
* doesn't treat attributes in their own way right.  An object will have an assignment operator. Why shouldn't age be an object and have its own assignment operator?

One benefit, that it shares with the One Method Name, is when used with messages the set method can transparently transform from native machine representations to network byte order.

### One Function Method
```c++
class X
   {
   public:
      int    Age() const     { return aAge; }
      void   Age(int age)    { aAge= age; }
   private:
      int aAge;
   }
```
Similar to Get/Set but cleaner. Use this approach when not using the Attributes as Objects approach. Use the feature of C++ to simplify the typing work. 


### Attributes as objects
```c++
class X
   {
   public:
      int              Age() const     { return aAge; }
      int&             rAge()          { return aAge; }

      const String&    Name() const    { return aName; }
      String&          rName()         { return aName; }
   private:
      int              aAge;
      String           aName;
   }
```
The above two attribute examples shows the strength and weakness of the Attributes as Objects approach.
When using an int type, which is not a real object, the int is set directly because rAge() returns a reference. The object can do no checking of the value or do any representation reformatting. For many simple attributes, however, these are not horrible restrictions. A way around this problem is to use a class wrapper around base types like int.

When an object is returned as reference its = operator is invoked to complete the assignment. For example:
```c++
X x;
x.rName()= "test";
```
This approach is also more consistent with the object philosophy: the object should do it. An object's = operator can do all the checks for the assignment and it's done once in one place, in the object, where it belongs. It's also clean from a name perspective.
When possible use this approach to attribute access.
