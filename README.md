I want to have a parent class which it stores all child class and the child class can have a derived classes which each classes is unique.
that's why I want to initialize class in a function but a class is a parameter. I don't know what to describe but let's look at the code.
I'm beginner btw.

```cpp
class Child {
    string child_name;
}
class Jame : public Child {
    void sit() {
        cout << "Jame can sit" << endl; 
    }
}
class Harry : public Harry {
    void sleep() {
        cout << "Harry can stand" << endl;
    }
}

class Parent {
    vector <Child> children;
    void addChild(string class_name) { //Prototype
        [classname] child; //EX. Jame child;
        child.child_name = class_name;
        
        children.push_back(child);
    }
    Child* getChild(string child_name) {
        for(int i = 0; i < children.size(); i++)
            if(children.at(i).child_name == child_name)
                return &children.at(i);
    }
};

int main() {

    Parent parent;
    parent.addChild("Harry");
    Child* child = parent.getChildren("Harry");
    child->sleep(); //Harry can stand.
    child->sit(); //error: undefined function.
    
    return 0;   
}
```

Something like this.
If you have any other ways help me please, I'm very new and I don't know what it's called.