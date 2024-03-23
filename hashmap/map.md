# Map

Using unordered_map lib we can create hashmap
```
 #include<unordered_map>;

 unordered_map<string,int>m;
 m.insert({"apple",10});
 m["mango"] = 20;

 for(pair<string,int> p : m){
  cout<< p->first << " " << p->second << endl;
 }

 for(auto p : m){
  cout<< p->first << " " << p->second << endl;
 }

 //To Get Hash Table Size use bucket_count()
 for(int i = 0; i<m.bucket_count() ; i++){
  cout << i << "->" ;
  for(auto it = m.begin(i); it != m.end(i); i++){
  cout << "(" << it->first <<","<< it->second<<")";
  }
  cout<<endl;
 }
```

There Is "map" which also have similar functions but it sorted and is stores in logN time and fetch in logN time and use red black avl tree.

  ## Iterator and Auto

    iterators is basically used to store addresses that can be used to store address of any bucket
    iterators are need to store or iterate in hashmaps
    if you do iterator ++ you will point to the next cause internally it has operator overloading and it does it->next internally
    auto is used to create diffrent types of variables depending on the value it is intialized with *Intialization is Important*

    unordered_ma<string,int> :: iterator it;
    auto it = map.find("key");
