#include <iostream>
using namespace std;
class node {
public:
  string key;
  int value;
  node *next;
  node(string k, int v) {
    key = k;
    value = v;
    next = NULL;
  }
};
class hashmap {
  node **a;
  int ts;
  int cs;

private:
  void rehash() {
    node **oldData = a;

    ts *= 2;
    a = new node *[ts];
    cs = 0;
    for (int i = 0; i < ts; i++) {
      a[i] = NULL;
    }

    for (int j = 0; j < ts / 2; j++) {
      node *head = oldData[j];
      while (head) {
        insertKeyValue(head->key, head->value);
        node *temp = head;
        head = head->next;
        delete temp;
      }
    }
  }

public:
  hashmap(int s) {
    a = new node *[s];
    for (int i = 0; i < s; i++) {
      a[i] = NULL;
    }
    ts = s;
    cs = 0;
  }
  int hashFunction(string key) {
    int ans = 0;
    int x = 1;
    for (int i = 0; i < key.size(); ++i) {
      ans += (x % ts) * (key[i] % ts);
      x *= 39 % ts;
      ans = ans % ts;
    }
    return ans % ts;
  }

  void insertKeyValue(string key, int value) {
    node *n = new node(key, value);
    int hashIndex = hashFunction(key);
    n->next = a[hashIndex];
    a[hashIndex] = n;
    cs++;
    float loadFactor = (cs / (ts * 1.0));
    if (loadFactor > 0.5) {
      rehash();
    }
  }

  void printMap() {
    for (int j = 0; j < ts; j++) {
      node *head = a[j];
      cout << j << " ";
      while (head) {
        cout << "( "<< head->key << "," << head->value << " ) -> ";
        head = head->next;
      }

      cout << "NULL" << endl;
    }
  }
  node *search(string key) {
    int hashIndex = hashFunction(key);
    node *head = a[hashIndex];
    while (head) {
      if (head->key == key) {
        return head;
      }
      head = head->next;
    }
    return NULL;
  }

  // Adding & is like adding a * if we want to return as a reference we use & and * to return as a address
  int &operator[](string key) {
    node *found = search(key);
    if (found == NULL) {
      // Insert
      /**
        Here We Add A random value so that we can add the key and search it
        second we return the value bucket so that it will be updated if there is assignment operator
        If No Assignment Operator It will Print the value
      */
      insertKeyValue(key, -1);
      found = search(key);
      return found->value;
    } else {
      // Update
      return found->value;
    }
  }
};

int main() {
  hashmap h(4);
  h.insertKeyValue("mango", 100);
  h.insertKeyValue("gauva", 30);
  h.insertKeyValue("apple", 20);

  h.insertKeyValue("banana", 50);
  h.insertKeyValue("orange", 60);
  h["pineapple"] = 100;
  cout << "( pineapple , " << h["pineapple"]<< " )" <<endl;
  h["pineapple"] = 50;
  cout << "( pineapple , " << h["pineapple"]<< " )" <<endl;


  h.printMap();
  return 0;
}
