/* Today Topic Is Exception Handling */

//#include <iostream>
//#include <limits>
//using namespace std;
//
//void ProcessStatus(int count) {
//    int* ptrArr = (int*)malloc(count * sizeof(int));
//    if (ptrArr == nullptr) {
//        cout << "Failed To Allocate Memory" << endl; 
//        return;
//    }
//    for (int i = 0; i < count; ++i) {
//        ptrArr[i] = i;
//    }
//    free(ptrArr);
//}
//
//int main() {
//    ProcessStatus(numeric_limits<int>::max());
//    return 0;
//}


//#include<iostream>
//#include<limits>
//using namespace std;
//
//int ProcessStatus(int count) {
//	int* ptrArr = (int*)malloc(count * sizeof(int));
//	if (ptrArr == nullptr) {
//		cout << "Failed To Allocate Memory:" << endl;
//		return -1;
//	}
//	for (int i = 0; i < count; ++i) {
//		ptrArr[i] = i;
//	}
//	free(ptrArr);
//	return 0;
//}
//
//int main() {
//	ProcessStatus(numeric_limits<int>::max());
//	return 0;
//}


#include<iostream>
#include<limits>
using namespace std;

int ProcessStatus(int count) {
	if (count < 10) {
		throw out_of_range("count should be greater than ten;");
	}
	int* p = new int[count];
	int* ptrArr = (int*)malloc(count * sizeof(int));
	if (ptrArr == nullptr) {
		throw runtime_error("Failed To Allocate Memory");
		return -1;
	}
	for (int i = 0; i < count; ++i) {
		ptrArr[i] = i;
	}
	free(ptrArr);
	return 0;
}

int main() {
	try {
		//ProcessStatus(numeric_limits<int>::max());
		ProcessStatus(5);
	}
	/*catch(runtime_error& e){
		cout << "error is: " << e.what() << endl;
	}
	catch (out_of_range& e) {
		cout << "error is: " << e.what() << endl;
	}
	catch (bad_alloc& e) {
		cout << "error is: " << e.what() << endl;
	}*/
	// All - Catch Block(catch (exception&))//
	catch (exception& e) {
		cout << "error is: " << e.what() << endl;
	}
	// Universal Catch Block (catch(...))//
	// it does not access exception detail like e.what(). //
	// it is not very useful due to it does not give any data about error.//
	// "..." is called ellipses. //
	catch (...) {
		cout << "Exception which are not documented it catch them also " << endl;
	}
	return 0;
}
