🔹 Common Built-in Functions of std::unique_ptr

| Function                   | Description                                                                                 |
| -------------------------- | ------------------------------------------------------------------------------------------- |
| `get()`                    | Returns the raw pointer without releasing ownership.                                        |
  Example:- 
  std::unique_ptr<int> ptr = std::make_unique<int>(42);
  int* raw = ptr.get();  // raw points to the same object, but does not take ownership
****************************************************************************************************************************
| `release()`                | Releases ownership of the pointer and returns the raw pointer. You must delete it manually. |
  Example:-
  std::unique_ptr<int> ptr = std::make_unique<int>(10);
  int* raw = ptr.release();  // ptr is now nullptr, and raw owns the memory
  // You must manually delete raw now
  delete raw;
****************************************************************************************************************************
| `reset()`                  | Deletes the owned object and optionally takes a new pointer.                                |
   Example:-
   std::unique_ptr<int> ptr = std::make_unique<int>(5);
   ptr.reset(new int(20));  // deletes the old int(5), takes ownership of new int(20)
   ptr.reset();             // deletes the int(20) and makes ptr null

****************************************************************************************************************************
| `swap()`                   | Swaps the owned pointers between two `unique_ptr`s.                                         |
  Example:-
  std::unique_ptr<int> a = std::make_unique<int>(100);
  std::unique_ptr<int> b = std::make_unique<int>(200);
  a.swap(b);  // now a owns 200, b owns 100
****************************************************************************************************************************
| `operator*` / `operator->` | Accesses the underlying object.                                                             |
  Example:- 
  std::unique_ptr<std::string> str = std::make_unique<std::string>("Hello");
  std::cout << *str << "\n";       // Dereference
  std::cout << str->length() << "\n"; // Member access
****************************************************************************************************************************
| `operator bool()`          | Returns `true` if the `unique_ptr` owns an object.                                          |
   Example:-
   std::unique_ptr<int> ptr;
   if (!ptr) {
    std::cout << "Pointer is null\n";
   }
****************************************************************************************************************************


# Sharing Pointer Basic Implementation Code :-

// Online C++ compiler to run C++ program online
#include <iostream>
#include<memory>
#include<string>
int count=1;
class Project{
    std::string m_Name;
    public:
    void SetName(const std::string &name){
        m_Name=name;
    }
    void ShowProjectDetails() const{
        std::cout<<"[Project Name]" <<m_Name<<"\n";
    }
};

class Employee{
  Project *m_pProject{};
  public:
  void SetProject(Project *prj){
      m_pProject=prj;
  }
  const Project *GetProject()const{
      return m_pProject;
  }
};

void ShowInfo(Employee *emp){
    std::cout<<"Employee "<<count++<<" ";
    emp->GetProject()->ShowProjectDetails();
}
int main() {
    Project *prj=new Project{};
    prj->SetName("C++ Training");
    Employee *e1=new Employee{};
    e1->SetProject(prj);
    Employee *e2=new Employee{};
    e2->SetProject(prj);
    Employee *e3=new Employee{};
    e3->SetProject(prj);
    ShowInfo(e1);
    ShowInfo(e2);
    ShowInfo(e3);
    prj->ShowProjectDetails();
    delete prj;
    delete e1;
    delete e2;
    delete e3;
    return 0;
}


