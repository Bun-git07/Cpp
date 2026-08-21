//ex1
#include <iostream>
using namespace std;
int main(){
    cout << "Hello, my name is slimshady";
    return 0;
}

//ex2
#include <iostream>
using namespace std;
int main()
{
    string name;
    int age;
    double gpa;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter GPA: ";
    cin >> gpa;
    cout << "Ur name is " << name <<" and "<< age << " years old and ur gpa is "<<gpa<<"";
    return 0;
}

//ex3
#include <iostream>
using namespace std;
int main(){
    int score1 = 60, score2 = 1;
    int sum = score1 + score2;
    int avg = sum / 2;
    if (avg >= 50){
        cout << "passed"<<endl;
        cout << "your average is "<<avg<<"";
    }else{
        cout << "failed";
    }
    return 0;
}

//ex4
#include <iostream>
using namespace std;
int main(){
    int score1 = 59,score2=70;
    int sum = score1 + score2;
    int avg = sum / 2;
    if (avg>=90){
        cout<<"grade A";
    }
    else if (avg>79 && avg<90){
        cout << "grade B";
    }
    else if (avg > 69 && avg < 80)
    {
        cout << "grade C";
    }
    else if (avg > 59 && avg < 70)
    {
        cout << "grade D";
    }else {
        cout << "Failed";
    }
    return 0;
}

//ex5
#include <iostream>
using namespace std;
int main(){
    int n,i=0;
    cout << "How many time do you wna loop: ";
    cin >> n;
    while (i<n){
        cout << "" << i+1 << ""<<endl;
        i++;
    }
    return 0;
}

//ex6
#include <iostream>
using namespace std;
int main(){
    int score[6] = {1, 2, 3, 4, 5, 6};
    int hi = score[0];
    int index = sizeof(score)/sizeof(score[0]);
    for (int i = 0; i < index;i++){
        if (score[i]>hi){
            hi = score[i];
        }
    }
    cout << "highest score is " << hi << ""<<endl;
    cout << "index is " << index << ""<<endl;
    return 0;
}

//ex7
#include <iostream>
using namespace std;
int main(){
    int vw = 0;
    string word;
    cout << "Enter a word : ";
    cin >> word;
    int index = word.length();
    for (int i = 0; i < index;i++){
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u'){
            vw++;
        }
    }
    cout << "vowels : " << vw << "";

    return 0;
}

//ex8
 #include <iostream>
 using namespace std;
 void doubleByValue(int x)
 {
     x = x * 2;
 }

void doubleByReference(int &x)
{
    x = x * 2;
}
int main()
{
    int num = 10;
    doubleByValue(num);
    cout << "After doubleByValue: " << num << endl;

    doubleByReference(num);
    cout << "After doubleByReference: " << num << endl;
    return 0;
}

//ex9
#include <iostream>
using namespace std;
int main()
{
    int x = 25;
    int *ptr = &x;

    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Value stored in ptr: " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;

    *ptr = 99;
    cout << "New value of x : " << x << "" << endl;
    return 0;
}