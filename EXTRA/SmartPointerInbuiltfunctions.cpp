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

# we can use unique pointer also but it will give us segmentation fault because we can not share resources.
# But we can use shared ptr for sharing resources to multiple objects.

🔷 Member Functions of std::shared_ptr:-

| Function          | Description                                                                                                |
| ----------------- | ---------------------------------------------------------------------------------------------------------- |
| `use_count()`     | Returns the number of `shared_ptr` instances managing the current object.                                  |
| `unique()`        | Returns `true` if the `shared_ptr` is the only one managing the object.                                    |
| `get()`           | Returns the raw pointer to the managed object.                                                             |
| `reset()`         | Destroys the current object and makes the `shared_ptr` empty. Can optionally take a new pointer to manage. |
| `swap(other)`     | Exchanges the managed object with another `shared_ptr`.                                                    |
| `operator*()`     | Dereference operator, accesses the object.                                                                 |
| `operator->()`    | Member access operator, accesses the object’s members.                                                     |
| `operator bool()` | Returns `true` if `shared_ptr` holds an object (non-null).                                                 |

weak ptr :--
  In C++, the syntax int num{}; is uniform (brace) initialization, introduced in C++11, and it means:
int num{};  // Initializes num to 0
This is equivalent to:
int num = 0;
int num;  // Not initialized, contains garbage value


// Weak Ownership :-
#include <iostream>
#include<memory>
class Printer {
    std::shared_ptr<int> m_pValue{};
public:
    void SetValue(std::shared_ptr<int> p) {
        m_pValue = p;
    }

    void Print() {
        std::cout << "Ref count: " << m_pValue.use_count() << std::endl;
        std::cout << "Value is: " << *m_pValue << std::endl;
    }
};

int main() {
    Printer prn;
    int num{};
    std::cin >> num;
    std::shared_ptr<int> p (new int{ num });
    prn.SetValue(p);

    if (*p > 10) {
        p = nullptr;
    }

    prn.Print();
}

//weak ptr internal 

#include <iostream>
#include<memory>
class Printer {
    std::weak_ptr<int> m_pValue{};
public:
    void SetValue(std::weak_ptr<int> p) {
        m_pValue = p;
    }

    void Print() {
        if (m_pValue.expired())
        {
            std::cout << "Resource is no longer available " << std::endl;
            return;
        }
        // lock() always return a shared ptr.
        auto sp = m_pValue.lock();
        std::cout << "Reference is: " << sp.use_count() << std::endl;
        std::cout << "Value is: " << *sp << std::endl;
    }
};

int main() {
    Printer prn;
    int num{};
    std::cin >> num;
    std::shared_ptr<int> p(new int{ num });
    prn.SetValue(p);

    if (*p > 10) {
        p = nullptr;
    }

    prn.Print();
}

// Circular reference
circular ownership:-

  
emp (shared_ptr<Employee>)               prj (shared_ptr<Project>)
┌────────────────────┐                  ┌────────────────────┐
│ Employee object     │◄──────────────┐  │ Project object      │◄──────────────┐
│ ref_count = 2       │               │  │ ref_count = 2       │               │
│ m_prj ──────────────┼─────────────► │  │ m_emp ──────────────┼─────────────► │
└────────────────────┘               │  └────────────────────┘               │
         ▲                            │            ▲                          │
         └────────────────────────────┘            └──────────────────────────┘
     emp (shared_ptr<Employee>)              prj (shared_ptr<Project>)

// In below code destructors not called and it causes memory leak.
#include<iostream>
#include<memory>
class Employee;
class Project {
public:
	std::shared_ptr<Employee> m_emp;
	Project() {
		std::cout << "Project()" << std::endl;
	}
	~Project() {
		std::cout << "~Project()" << std::endl;
	}
};
class Employee {
public:
	std::shared_ptr<Project> m_prj;
	Employee() {
		std::cout << "Employee()" << std::endl;
	}
	~Employee() {
		std::cout << "~Employee()" << std::endl;
	}
};

int main() {
	std::shared_ptr<Employee> emp { new Employee{} };
	std::shared_ptr<Project> prj { new Project{} };
	emp->m_prj = prj;
	prj->m_emp = emp;
}
  
no circular ownership:-
  
  emp (shared_ptr<Employee>)               prj (shared_ptr<Project>)
┌────────────────────┐                  ┌────────────────────┐
│ Employee object     │◄──────────────┐  │ Project object      │◄──────────────┐
│ ref_count = 1       │               │  │ ref_count = 1       │               │
│ m_prj ──────────────┼─────────────► │  │ m_emp ─weak_ptr─────┼──────┐        │
└────────────────────┘               │  └────────────────────┘      ▼        │
         ▲                            │            (no ownership)            │
         └────────────────────────────┘                                      │
     emp (shared_ptr<Employee>)              prj (shared_ptr<Project>)

#include<iostream>
#include<memory>
class Employee;
class Project {
public:
	std::weak_ptr<Employee> m_emp;
	Project() {
		std::cout << "Project()" << std::endl;
	}
	~Project() {
		std::cout << "~Project()" << std::endl;
	}
};
class Employee {
public:
	std::shared_ptr<Project> m_prj;
	Employee() {
		std::cout << "Employee()" << std::endl;
	}
	~Employee() {
		std::cout << "~Employee()" << std::endl;
	}
};

int main() {
	std::shared_ptr<Employee> emp { new Employee{} };
	std::shared_ptr<Project> prj { new Project{} };
	emp->m_prj = prj;
	prj->m_emp = emp;
}

// Deleter :-
Smart pointer does not invoke delete they always invoke deleter call back.

  

