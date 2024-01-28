## Object Oriented

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
