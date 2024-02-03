## Object Oriented Programming

1. Classes have few hidden functions (default everytime this will be added to your class)

   - Consturctor : This creates a object (Links Data Members with the object)

     - Called Everytime a new object is created for a class.
     - We Can moditify this constructor by addind a function which has same name as the class.
     - Two Type One Without Parameters and other the parameterized both works like a function.

     ```
        /*
        * Used To Initilize the Value and Do a Default Behaviour Everytime We are Creating a object.
        */
        class Car {
          Car (char *n,int p) {
            strcpy(name,n);
            price = p;
          }
          public :
            char name[100];
            int price;
        }

        int main () {
          car c1 ("BMW",100);
        }
     ```

   - Copy Constructor: Constructor to copy one object to another.

     - Can Be Called car B = A || car B(A);

     ```
      class Car {
        Car (Car &X) { // passing as a refernce is necessary
          strcpy(name,X.name);
          price = X.price;
        }
        public :
          char name[100];
          int price;
      }

      int main () {
        car c1 ("BMW",100);
        car c2(c1); // Can Be Called Like car c2 = c1;
      }
     ```

   - Copy Assignment Operator : This is not a constructor although a function

     - has return type void
     - name is operator=
     - This is used to update a value of the object that is already created

     ```
     class Car {
       void operator= (Car &X) { //can use the reference or can be skipped
         strcpy(name,X.name);
         price = X.price;
       }
       public :
         char name[100];
         int price;
     }

     int main () {
       car c1 ("BMW",100);
       car c2;

       c2 = c1; // This will call the copy assignment operator function
     }
     ```

   - Desturctor - To Destroy the Object once the use is finished

     - Delete the objects of a class.\
     - Delete will be in lifo. (last in first Out)
     - Delete keyword used in dynamic memory allocation will call the destructor.

     ```
       class Car {
         public :
           char name[100];
           int price;

           ~Car(){
             cout << "Deleteing" << name;
           }
       }

       int main () {
         car c1 ("BMW",100);
         car c2;

         c2 = c1; // This will call the copy assignment operator function
       }
     ```

2. By Default All the Default Constructor Uses Shallow Copy.
  - We have to do the deep copy manually

3. Operator Overloading
 - We Can How Operators works in OOPs with object.
 - {returnType} operator{operatorToOverload} () {}
 - ```
       class Car {
         public :
           char name[100];
           int price;


           \\This is Overloading operator += for objects of Car 
            void operator+= (Car &X) {
              price += X.price;
              strcat(name,X.name);
            }

           ~Car(){
             cout << "Deleteing" << name;
           }
       }

       int main () {
         car c1 ("BMW",100);
         car c2 ("MARUTI",200);

         c2 += c1;
         c2.print();
       }
    ```
    ##### Output: 
    ```
      MARUTIBMW,300
    ```

4. Access Specifiers
  - Specifices How We can access which members we can access.
  - To access these things we can create getter and setter.
  - Use for getter and setter is that we can have a lot more control over the private values and have validations.
  ```
    class Car {
      private: 
        int price;
      
      public: 
        char name[100];

      //Setter
      void setPrice(p){
        price = p;
      }

      //Getter
      void getPrice(){
        return price ;
      }
    }
  ```
